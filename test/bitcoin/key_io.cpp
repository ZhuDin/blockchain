

#include <key_io.h>

#include <base58.h>
#include <chainparams.h>

#include <vector>

CKey DecodeSecret(const std::string& str)
{	
	printf("key_io.cpp::DecodeSecret(%s) running\n", str.c_str());
    CKey key;
    std::vector<unsigned char> data;
    if (DecodeBase58Check(str, data)) {
    	const std::vector<unsigned char>& privkey_prefix = CChainParams().Base58Prefix(CChainParams::SECRET_KEY);
    }
    
    return key;
}