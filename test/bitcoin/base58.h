#include <vector>
#include <string>

bool DecodeBase58Check(const std::string& str, std::vector<unsigned char>& vchRet);

bool DecodeBase58Check(const char* psz, std::vector<unsigned char>& vchRet);

bool DecodeBase58(const char* psz, std::vector<unsigned char>& vch);