#include <key.h>


#include <secp256k1.h>
#include <secp256k1_recovery.h>

static secp256k1_context* secp256k1_context_sign = nullptr;

CPubKey CKey::GetPubKey() const {
    // assert(fValid);
    // secp256k1_pubkey pubkey;
    // size_t clen = CPubKey::PUBLIC_KEY_SIZE;
    CPubKey result;
    // int ret = secp256k1_ec_pubkey_create(secp256k1_context_sign, &pubkey, begin());
    // assert(ret);
    // secp256k1_ec_pubkey_serialize(secp256k1_context_sign, (unsigned char*)result.begin(), &clen, &pubkey, fCompressed ? SECP256K1_EC_COMPRESSED : SECP256K1_EC_UNCOMPRESSED);
    // assert(result.size() == clen);
    // assert(result.IsValid());
    return result;
}

bool CKey::Check(const unsigned char *vch) {
    return secp256k1_ec_seckey_verify(secp256k1_context_sign, vch);
}