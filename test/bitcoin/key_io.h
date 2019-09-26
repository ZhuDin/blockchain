#ifndef BITCOIN_KEY_IO_H
#define BITCOIN_KEY_IO_H

#include <key.h>

#include <string>

CKey DecodeSecret(const std::string& str);

#endif // BITCOIN_KEY_IO_H
