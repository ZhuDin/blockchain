#ifndef BITCOIN_KEY_H
#define BITCOIN_KEY_H

#include <pubkey.h>

#include <stdexcept>
#include <vector>

/**
 * secure_allocator is defined in allocators.h
 * CPrivKey is a serialized private key, with all parameters included
 * (PRIVATE_KEY_SIZE bytes)
 */
// typedef std::vector<unsigned char, secure_allocator<unsigned char> > CPrivKey;

class CKey
{
public:
    /**
     * secp256k1:
     */
    static const unsigned int PRIVATE_KEY_SIZE            = 279;
    static const unsigned int COMPRESSED_PRIVATE_KEY_SIZE = 214;
    /**
     * see www.keylength.com
     * script supports up to 75 for single byte push
     */
    static_assert(
        PRIVATE_KEY_SIZE >= COMPRESSED_PRIVATE_KEY_SIZE,
        "COMPRESSED_PRIVATE_KEY_SIZE is larger than PRIVATE_KEY_SIZE");

private:
    //! Whether this private key is valid. We check for correctness when modifying the key
    //! data, so fValid should always correspond to the actual state.
    bool fValid;

    //! Whether the public key corresponding to this private key is (to be) compressed.
    bool fCompressed;

    //! The actual byte data
    std::vector<unsigned char, secure_allocator<unsigned char> > keydata;


public:
     /**
     * Compute the public key from a private key.
     * This is expensive.
     */
    CPubKey GetPubKey() const;
};

#endif // BITCOIN_KEY_H
