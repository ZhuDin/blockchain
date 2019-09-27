








#ifndef BITCOIN_UTIL_SYSTEM_H
#define BITCOIN_UTIL_SYSTEM_H





#include <attributes.h>



#include <logging.h>
#include <sync.h>





#include <exception>
#include <map>
#include <set>
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

// line 104
enum class OptionsCategory {
    OPTIONS,
    CONNECTION,
    WALLET,
    WALLET_DEBUG_TEST,
    ZMQ,
    DEBUG_TEST,
    CHAINPARAMS,
    NODE_RELAY,
    BLOCK_CREATION,
    RPC,
    GUI,
    COMMANDS,
    REGISTER_COMMANDS,

    HIDDEN // Always the last option to avoid printing these in the help
};

// line 122
struct SectionInfo
{
    std::string m_name;
    std::string m_file;
    int m_line;
};

// line 129
class ArgsManager
{
public:
    enum Flags {
        NONE = 0x00,
        // Boolean options can accept negation syntax -noOPTION or -noOPTION=1
        ALLOW_BOOL = 0x01,
        ALLOW_INT = 0x02,
        ALLOW_STRING = 0x04,
        ALLOW_ANY = ALLOW_BOOL | ALLOW_INT | ALLOW_STRING,
        DEBUG_ONLY = 0x100,
        /* Some options would cause cross-contamination if values for
         * mainnet were used while running on regtest/testnet (or vice-versa).
         * Setting them as NETWORK_ONLY ensures that sharing a config file
         * between mainnet and regtest/testnet won't cause problems due to these
         * parameters by accident. */
        NETWORK_ONLY = 0x200,
    };

protected:
    friend class ArgsManagerHelper;

    struct Arg
    {
        std::string m_help_param;
        std::string m_help_text;
        unsigned int m_flags;
    };

    mutable CCriticalSection cs_args;
    std::map<std::string, std::vector<std::string>> m_override_args GUARDED_BY(cs_args);
    std::map<std::string, std::vector<std::string>> m_config_args GUARDED_BY(cs_args);
    std::string m_network GUARDED_BY(cs_args);
    std::set<std::string> m_network_only_args GUARDED_BY(cs_args);
    std::map<OptionsCategory, std::map<std::string, Arg>> m_available_args GUARDED_BY(cs_args);
    std::list<SectionInfo> m_config_sections GUARDED_BY(cs_args);

    NODISCARD bool ReadConfigStream(std::istream& stream, const std::string& filepath, std::string& error, bool ignore_invalid_keys = false);

public:
    ArgsManager();

    /**
     * Select the network in use
     */
    void SelectConfigNetwork(const std::string& network);

    NODISCARD bool ParseParameters(int argc, const char* const argv[], std::string& error);
    NODISCARD bool ReadConfigFiles(std::string& error, bool ignore_invalid_keys = false);

    /**
     * Log warnings for options in m_section_only_args when
     * they are specified in the default section but not overridden
     * on the command line or in a network-specific section in the
     * config file.
     */
    const std::set<std::string> GetUnsuitableSectionOnlyArgs() const;

    /**
     * Log warnings for unrecognized section names in the config file.
     */
    const std::list<SectionInfo> GetUnrecognizedSections() const;

    /**
     * Return a vector of strings of the given argument
     *
     * @param strArg Argument to get (e.g. "-foo")
     * @return command-line arguments
     */
    std::vector<std::string> GetArgs(const std::string& strArg) const;

    /**
     * Return true if the given argument has been manually set
     *
     * @param strArg Argument to get (e.g. "-foo")
     * @return true if the argument has been set
     */
    bool IsArgSet(const std::string& strArg) const;

    /**
     * Return true if the argument was originally passed as a negated option,
     * i.e. -nofoo.
     *
     * @param strArg Argument to get (e.g. "-foo")
     * @return true if the argument was passed negated
     */
    bool IsArgNegated(const std::string& strArg) const;

    /**
     * Return string argument or default value
     *
     * @param strArg Argument to get (e.g. "-foo")
     * @param strDefault (e.g. "1")
     * @return command-line argument or default value
     */
    std::string GetArg(const std::string& strArg, const std::string& strDefault) const;

    /**
     * Return integer argument or default value
     *
     * @param strArg Argument to get (e.g. "-foo")
     * @param nDefault (e.g. 1)
     * @return command-line argument (0 if invalid number) or default value
     */
    int64_t GetArg(const std::string& strArg, int64_t nDefault) const;

    /**
     * Return boolean argument or default value
     *
     * @param strArg Argument to get (e.g. "-foo")
     * @param fDefault (true or false)
     * @return command-line argument or default value
     */
    bool GetBoolArg(const std::string& strArg, bool fDefault) const;

    /**
     * Set an argument if it doesn't already have a value
     *
     * @param strArg Argument to set (e.g. "-foo")
     * @param strValue Value (e.g. "1")
     * @return true if argument gets set, false if it already had a value
     */
    bool SoftSetArg(const std::string& strArg, const std::string& strValue);

    /**
     * Set a boolean argument if it doesn't already have a value
     *
     * @param strArg Argument to set (e.g. "-foo")
     * @param fValue Value (e.g. false)
     * @return true if argument gets set, false if it already had a value
     */
    bool SoftSetBoolArg(const std::string& strArg, bool fValue);

    // Forces an arg setting. Called by SoftSetArg() if the arg hasn't already
    // been set. Also called directly in testing.
    void ForceSetArg(const std::string& strArg, const std::string& strValue);

    /**
     * Looks for -regtest, -testnet and returns the appropriate BIP70 chain name.
     * @return CBaseChainParams::MAIN by default; raises runtime error if an invalid combination is given.
     */
    std::string GetChainName() const;

    /**
     * Add argument
     */
    void AddArg(const std::string& name, const std::string& help, unsigned int flags, const OptionsCategory& cat);

    /**
     * Add many hidden arguments
     */
    void AddHiddenArgs(const std::vector<std::string>& args);

    /**
     * Clear available arguments
     */
    void ClearArgs() {
        LOCK(cs_args);
        m_available_args.clear();
        m_network_only_args.clear();
    }

    /**
     * Get the help string
     */
    std::string GetHelpMessage() const;

    /**
     * Return Flags for known arg.
     * Return ArgsManager::NONE for unknown arg.
     */
    unsigned int FlagsOfKnownArg(const std::string& key) const;
};

// line 303
extern ArgsManager gArgs;

#endif // BITCOIN_UTIL_SYSTEM_H