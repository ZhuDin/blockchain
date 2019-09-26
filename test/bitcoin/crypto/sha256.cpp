#include <crypto/sha256.h>

// Internal implementation code.
namespace
{
/// Internal SHA-256 implementation.
namespace sha256
{

/** Initialize SHA-256 state. */
void inline Initialize(uint32_t* s)
{
    s[0] = 0x6a09e667ul;
    s[1] = 0xbb67ae85ul;
    s[2] = 0x3c6ef372ul;
    s[3] = 0xa54ff53aul;
    s[4] = 0x510e527ful;
    s[5] = 0x9b05688cul;
    s[6] = 0x1f83d9abul;
    s[7] = 0x5be0cd19ul;
}
}
}
CSHA256::CSHA256() : bytes(0)
{
    sha256::Initialize(s);
}
