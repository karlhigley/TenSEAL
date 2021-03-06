#ifndef TENSEAL_UTILS_H
#define TESNEAL_UTILS_H

#include <seal/seal.h>

#include <memory>

using namespace seal;
using namespace std;

namespace tenseal {

/*
Returns a setuped EncryptionParameters that holds the parameters required for
the BFV scheme, namely, the polynomial modulus, the coeffecient modulus bit
sizes and plaintext modulus.
*/
EncryptionParameters create_bfv_parameters(size_t poly_modulus_degree,
                                           uint64_t plain_modulus,
                                           vector<int> coeff_mod_bit_sizes);

/*
Returns a setuped EncryptionParameters that holds the parameters required for
the CKKS scheme, namely, the polynomial modulus, the coeffecient modulus bit
sizes.
*/
EncryptionParameters create_ckks_parameters(size_t poly_modulus_degree,
                                            vector<int> coeff_mod_bit_sizes);

/*
Returns a smart pointer to a SEALContext created with the provided encryption
parameters.
*/
shared_ptr<seal::SEALContext> create_context(EncryptionParameters parms);

}  // namespace tenseal

#endif