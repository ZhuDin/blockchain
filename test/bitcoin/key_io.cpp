

#include <key_io.h>

#include <base58.h>

#include <vector>


CKey DecodeSecret(const std::string& str)
{	
	printf("key_io.cpp::DecodeSecret(%s) running\n", str.c_str());
    CKey key;
    std::vector<unsigned char> data;
    if (DecodeBase58Check(str, data)) {
        printf("\tDecodeBase58Check() ok\n\tNow the strSecret(hex) is : ");
        for (std::vector<unsigned char>::iterator it = data.begin(); it != data.end(); ++it) {
            printf("%x ", *it);
        }
        printf("\n");
    	const std::vector<unsigned char>& privkey_prefix = Params().Base58Prefix(CChainParams::SECRET_KEY);
        printf("\tcall CChainParams() get privkey_prefix size --> ");printf("%zd", privkey_prefix.size());
        // for (std::vector<unsigned char>::const_iterator it = privkey_prefix.begin(); it != privkey_prefix.end(); ++it) {
        //     printf("%d ", *it);
        // }
        printf("\n");
        printf("\tafter DecodeBase58Check() the data.size() is %zd and data.back() is %d\n", data.size(), data.back());
    	if ((data.size() == 32 + privkey_prefix.size() || (data.size() == 33 + privkey_prefix.size() && data.back() == 1)) &&
            std::equal(privkey_prefix.begin(), privkey_prefix.end(), data.begin())) {
            bool compressed = data.size() == 33 + privkey_prefix.size();
            key.Set(data.begin() + privkey_prefix.size(), data.begin() + privkey_prefix.size() + 32, compressed);
        }
    }
    if (!data.empty()) {
        memory_cleanse(data.data(), data.size());
    }
    printf("\tDecodeSecret() ok\n");
    return key;
}