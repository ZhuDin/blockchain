#ifndef BITCOIN_PUBKEY_H
#define BITCOIN_PUBKEY_H

#include <uint256.h>


typedef uint256 ChainCode;

/** An encapsulated public key. */
class CPubKey
{
public:
    /**
     * secp256k1:
     */
    static constexpr unsigned int PUBLIC_KEY_SIZE             = 65;
    static constexpr unsigned int COMPRESSED_PUBLIC_KEY_SIZE  = 33;
    static constexpr unsigned int SIGNATURE_SIZE              = 72;
    static constexpr unsigned int COMPACT_SIGNATURE_SIZE      = 65;
    /**
     * see www.keylength.com
     * script supports up to 75 for single byte push
     */
    static_assert(
        PUBLIC_KEY_SIZE >= COMPRESSED_PUBLIC_KEY_SIZE,
        "COMPRESSED_PUBLIC_KEY_SIZE is larger than PUBLIC_KEY_SIZE");

};

#endif // BITCOIN_PUBKEY_H
