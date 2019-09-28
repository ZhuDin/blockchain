



#ifndef BITCOIN_INTERFACES_NODE_H
#define BITCOIN_INTERFACES_NODE_H







#include <functional>
#include <memory>
#include <stddef.h>
#include <stdint.h>
#include <string>
#include <tuple>
#include <vector>


// line 32
namespace interfaces {
class Handler;


// line 36
//! Top-level interface for a bitcoin node (bitcoind process).
class Node 
{
public:
    virtual ~Node() {}
// line 42
    //! Send init error.
    virtual void initError(const std::string& message) = 0;

    //! Set command line arguments.
    virtual bool parseParameters(int argc, const char* const argv[], std::string& error) = 0;

    //! Set a command line argument
    virtual void forceSetArg(const std::string& arg, const std::string& value) = 0;

    //! Set a command line argument if it doesn't already have a value
    virtual bool softSetArg(const std::string& arg, const std::string& value) = 0;

    //! Set a command line boolean argument if it doesn't already have a value
    virtual bool softSetBoolArg(const std::string& arg, bool value) = 0;

    //! Load settings from configuration file.
    virtual bool readConfigFiles(std::string& error) = 0;

    //! Choose network parameters.
    virtual void selectParams(const std::string& network) = 0;

    //! Get the (assumed) blockchain size.
    virtual uint64_t getAssumedBlockchainSize() = 0;

    //! Get the (assumed) chain state size.
    virtual uint64_t getAssumedChainStateSize() = 0;

    //! Get network name.
    virtual std::string getNetwork() = 0;

    //! Init logging.
    virtual void initLogging() = 0;

    //! Init parameter interaction.
    virtual void initParameterInteraction() = 0;

    //! Get warnings.
    virtual std::string getWarnings(const std::string& type) = 0;

    // Get log flags.
    virtual uint32_t getLogCategories() = 0;

    //! Initialize app dependencies.
    virtual bool baseInitialize() = 0;

    //! Start node.
    virtual bool appInitMain() = 0;

    //! Stop node.
    virtual void appShutdown() = 0;

    //! Start shutdown.
    virtual void startShutdown() = 0;

    //! Return whether shutdown was requested.
    virtual bool shutdownRequested() = 0;

    //! Setup arguments
    virtual void setupServerArgs() = 0;

    //! Map port.
    virtual void mapPort(bool use_upnp) = 0;
// line 105









// line 130
    //! Get total bytes recv.
    virtual int64_t getTotalBytesRecv() = 0;

    //! Get total bytes sent.
    virtual int64_t getTotalBytesSent() = 0;

    //! Get mempool size.
    virtual size_t getMempoolSize() = 0;

    //! Get mempool dynamic usage.
    virtual size_t getMempoolDynamicUsage() = 0;

    //! Get header tip height and time.
    virtual bool getHeaderTip(int& height, int64_t& block_time) = 0;

    //! Get num blocks.
    virtual int getNumBlocks() = 0;

    //! Get last block time.
    virtual int64_t getLastBlockTime() = 0;

    //! Get verification progress.
    virtual double getVerificationProgress() = 0;

    //! Is initial block download.
    virtual bool isInitialBlockDownload() = 0;

    //! Is -addresstype set.
    virtual bool isAddressTypeSet() = 0;

    //! Get reindex.
    virtual bool getReindex() = 0;

    //! Get importing.
    virtual bool getImporting() = 0;

    //! Set network active.
    virtual void setNetworkActive(bool active) = 0;
// line 169
    //! Get network active.
    virtual bool getNetworkActive() = 0;


};
// line 261
//! Return implementation of Node interface.
std::unique_ptr<Node> MakeNode();
// line 264
} // namespace interfaces

#endif // BITCOIN_INTERFACES_NODE_H