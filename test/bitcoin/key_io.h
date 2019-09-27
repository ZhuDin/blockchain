#ifndef BITCOIN_KEY_IO_H
#define BITCOIN_KEY_IO_H

#include <chainparams.h>
#include <key.h>
#include <pubkey.h>
#include <script/standard.h>

#include <string>

CKey DecodeSecret(const std::string& str);
std::string EncodeSecret(const CKey& key);

// CExtKey DecodeExtKey(const std::string& str);
// std::string EncodeExtKey(const CExtKey& extkey);
// CExtPubKey DecodeExtPubKey(const std::string& str);
// std::string EncodeExtPubKey(const CExtPubKey& extpubkey);

// std::string EncodeDestination(const CTxDestination& dest);
// CTxDestination DecodeDestination(const std::string& str);
bool IsValidDestinationString(const std::string& str);
bool IsValidDestinationString(const std::string& str, const CChainParams& params);

#endif // BITCOIN_KEY_IO_H
