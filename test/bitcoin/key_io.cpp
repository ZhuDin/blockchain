



#include <key_io.h>

#include <base58.h>

#include <vector>





#include <assert.h>
#include <string.h>
#include <algorithm>

CKey DecodeSecret(const std::string& str)
{	
	printf("key_io.cpp::DecodeSecret(%s) running\n", str.c_str());
    CKey key;
    std::vector<unsigned char> data;
    if (DecodeBase58Check(str, data)) {
        printf("  DecodeBase58Check() ok\n\tNow the strSecret(hex) is : ");
        for (std::vector<unsigned char>::iterator it = data.begin(); it != data.end(); ++it) {
            printf("%x ", *it);
        }
        printf("\n");
    	const std::vector<unsigned char>& privkey_prefix = Params().Base58Prefix(CChainParams::SECRET_KEY);
        printf("\tBase58Prefix of SECRET_KEY --> %d or %x(hex)\n", *(privkey_prefix.data()), *(privkey_prefix.data()));
        printf("\tafter DecodeBase58Check() the data.size() is %zd\n", data.size());
    	if ((data.size() == 32 + privkey_prefix.size() || (data.size() == 33 + privkey_prefix.size() && data.back() == 1)) &&
            std::equal(privkey_prefix.begin(), privkey_prefix.end(), data.begin())) {
            bool compressed = data.size() == 33 + privkey_prefix.size();
            key.Set(data.begin() + privkey_prefix.size(), data.begin() + privkey_prefix.size() + 32, compressed);
            printf("\tnow CKey:keydata value --> ");
            for(int size = 0; size < key.size(); size++) printf("%x ", *(key.begin()+size));
            printf("\n");
        }
    }
    if (!data.empty()) {
        memory_cleanse(data.data(), data.size());
    }
    printf("  DecodeSecret() ok\n");
    return key;
}