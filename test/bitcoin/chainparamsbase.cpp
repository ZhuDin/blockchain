




#include <chainparamsbase.h>

#include <tinyformat.h>
#include <util/system.h>
#include <util/memory.h>

#include <assert.h>

const std::string CBaseChainParams::MAIN = "main";
const std::string CBaseChainParams::TESTNET = "test";
const std::string CBaseChainParams::REGTEST = "regtest";

void SetupChainParamsBaseOptions()
{
    // gArgs.AddArg("-chain=<chain>", "Use the chain <chain> (default: main). Allowed values: main, test, regtest", ArgsManager::ALLOW_ANY, OptionsCategory::CHAINPARAMS);
    // gArgs.AddArg("-regtest", "Enter regression test mode, which uses a special chain in which blocks can be solved instantly. "
    //              "This is intended for regression testing tools and app development. Equivalent to -chain=regtest.", ArgsManager::ALLOW_ANY | ArgsManager::DEBUG_ONLY, OptionsCategory::CHAINPARAMS);
    // gArgs.AddArg("-segwitheight=<n>", "Set the activation height of segwit. -1 to disable. (regtest-only)", ArgsManager::ALLOW_ANY | ArgsManager::DEBUG_ONLY, OptionsCategory::DEBUG_TEST);
    // gArgs.AddArg("-testnet", "Use the test chain. Equivalent to -chain=test.", ArgsManager::ALLOW_ANY, OptionsCategory::CHAINPARAMS);
    // gArgs.AddArg("-vbparams=deployment:start:end", "Use given start/end times for specified version bits deployment (regtest-only)", ArgsManager::ALLOW_ANY | ArgsManager::DEBUG_ONLY, OptionsCategory::CHAINPARAMS);
}
// line 27
static std::unique_ptr<CBaseChainParams> globalChainBaseParams;

const CBaseChainParams& BaseParams()
{
    assert(globalChainBaseParams);
    return *globalChainBaseParams;
}

std::unique_ptr<CBaseChainParams> CreateBaseChainParams(const std::string& chain)
{
    printf("chainparamsbase.cpp::CreateBaseChainParams(%s) running\n", chain.c_str());
    if (chain == CBaseChainParams::MAIN)
        return MakeUnique<CBaseChainParams>("main", 8332);
    else if (chain == CBaseChainParams::TESTNET)
        return MakeUnique<CBaseChainParams>("testnet3", 18332);
    else if (chain == CBaseChainParams::REGTEST)
        return MakeUnique<CBaseChainParams>("regtest", 18443);
    else
        throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}
// line 47
void SelectBaseParams(const std::string& chain)
{
    printf("chainparamsbase.cpp::SelectBaseParams(%s) running\n", chain.c_str());
    globalChainBaseParams = CreateBaseChainParams(chain);
    printf("\tglobalChainBaseParasm --> strDataDir:%s nRPCPort:%d\n", (*globalChainBaseParams).DataDir().c_str(), (*globalChainBaseParams).RPCPort());
    gArgs.SelectConfigNetwork(chain);
}