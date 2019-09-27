#ifndef BITCOIN_AMOUNT_H
#define BITCOIN_AMOUNT_H

#include <stdint.h>


/** Amount in satoshis (Can be negative) */
typedef int64_t CAmount;

static const CAmount COIN = 100000000;

#endif //  BITCOIN_AMOUNT_H