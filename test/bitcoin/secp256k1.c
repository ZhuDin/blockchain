#include <secp256k1.h>

// #include <secp256k1/util.h>
// #include <secp256k1/num_impl.h>
// #include <secp256k1/field_impl.h>
// #include <secp256k1/scalar_impl.h>
// #include <secp256k1/group_impl.h>
// #include <secp256k1/ecmult_impl.h>
// #include <secp256k1/ecmult_const_impl.h>
// #include <secp256k1/ecmult_gen_impl.h>
// #include <secp256k1/ecdsa_impl.h>
// #include <secp256k1/eckey_impl.h>
// #include <secp256k1/hash_impl.h>
// #include <secp256k1/scratch_impl.h>
#include <secp256k1/ecmult.h>

int secp256k1_ec_seckey_verify(const secp256k1_context* ctx, const unsigned char *seckey) {
    // secp256k1_scalar sec;
    int ret;
    // int overflow;
    // VERIFY_CHECK(ctx != NULL);
    // ARG_CHECK(seckey != NULL);

    // secp256k1_scalar_set_b32(&sec, seckey, &overflow);
    // ret = !overflow && !secp256k1_scalar_is_zero(&sec);
    // secp256k1_scalar_clear(&sec);
    return ret;
}

struct secp256k1_context_struct {
    secp256k1_ecmult_context ecmult_ctx;
    // secp256k1_ecmult_gen_context ecmult_gen_ctx;
    // secp256k1_callback illegal_callback;
    // secp256k1_callback error_callback;
};