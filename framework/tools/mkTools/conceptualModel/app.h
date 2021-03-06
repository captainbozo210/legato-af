//--------------------------------------------------------------------------------------------------
/**
 * @file app.h
 *
 * Copyright (C) Sierra Wireless Inc.
 */
//--------------------------------------------------------------------------------------------------

#ifndef LEGATO_MKTOOLS_MODEL_APP_H_INCLUDE_GUARD
#define LEGATO_MKTOOLS_MODEL_APP_H_INCLUDE_GUARD


//--------------------------------------------------------------------------------------------------
/**
 * Represents a single application.
 */
//--------------------------------------------------------------------------------------------------
struct App_t
{
    App_t(parseTree::AdefFile_t* filePtr);

    const parseTree::AdefFile_t* defFilePtr;  ///< Pointer to root of parse tree for the .adef file.
                                              ///< NULL if the app was created by mkexe.

    const parseTree::App_t* parseTreePtr; ///< Ptr to the app section in the .sdef file parse tree.
                                          ///< NULL if the app was created by mkapp.

    std::string dir;    ///< Absolute path to the directory containing the .adef file.

    std::string name;   ///< Name of the app (C identifier safe name). "" if created by mkexe.

    std::string workingDir; ///< Path to working dir for app, relative to build's root working dir.

    std::string version;    ///< Human-readable version label.

    bool isSandboxed;       ///< true if the application should be sandboxed.

    enum {AUTO, MANUAL} startTrigger;    ///< Start automatically or only when asked?

    bool isPreloaded;   ///< true = exclude app update from system update (app pre-loaded on target)
    bool isPreBuilt;    ///< true = app is a pre-built app.  Affects how some error messages are
                        ///< displayed

    std::string preloadedMd5; ///< MD5 hash of preloaded app (empty if not specified).

    std::set<Component_t*> components;  ///< Set of components used in this app.

    std::map<std::string, Exe_t*> executables;  ///< Collection of executables defined in this app.

    std::list<FileSystemObject_t*> bundledFiles; ///< List of files to be bundled in the app.
    std::list<FileSystemObject_t*> bundledDirs;  ///< List of directories to be bundled in the app.

    std::list<FileSystemObject_t*> requiredFiles; ///< List of files to be imported into the app.
    std::list<FileSystemObject_t*> requiredDirs;  ///< List of dirs to be imported into the app.
    std::list<FileSystemObject_t*> requiredDevices;///< List of devices to be imported into the app.

    std::list<ProcessEnv_t*> processEnvs;   ///< Process environments defined in the app.

    /// Set of the names of groups that this application's user should be a member of.
    std::set<std::string> groups;

    // Per-user limits:
    PositiveIntLimit_t      cpuShare;           ///< Relative share value
    NonNegativeIntLimit_t   maxFileSystemBytes; ///< Total bytes in sandbox tmpfs file system.
    PositiveIntLimit_t      maxMemoryBytes;     ///< Total bytes of RAM.
    NonNegativeIntLimit_t   maxMQueueBytes;     ///< Total bytes in all POSIX MQueues.
    NonNegativeIntLimit_t   maxQueuedSignals;   ///< Total number of queued signals.
    PositiveIntLimit_t      maxThreads;         ///< Number of threads.
    NonNegativeIntLimit_t   maxSecureStorageBytes;   ///< Total bytes in Secure Storage.

    // Watchdog
    WatchdogAction_t  watchdogAction;
    WatchdogTimeout_t watchdogTimeout;

    /// Map of configuration tree names to access permissions (see permissions.h).
    std::map<std::string, Permissions_t> configTrees;

    /// Set of server-side IPC API interfaces provided by pre-built binaries in this app.
    /// Keyed by server interface name.
    std::map<std::string, ApiServerInterfaceInstance_t*> preBuiltServerInterfaces;

    /// Set of client-side IPC API interfaces required by pre-built binaries in this app.
    /// Keyed by client interface name.
    std::map<std::string, ApiClientInterfaceInstance_t*> preBuiltClientInterfaces;

    /// Map of server interfaces that external entities can bind to (key is external name).
    std::map<std::string, ApiServerInterfaceInstance_t*> externServerInterfaces;

    /// Map of client interfaces marked for later binding to external services (key is external name)
    std::map<std::string, ApiClientInterfaceInstance_t*> externClientInterfaces;

    // Function for finding component instance.  Throw exception if not found.
    ComponentInstance_t* FindComponentInstance(const parseTree::Token_t* exeTokenPtr,
                                               const parseTree::Token_t* componentTokenPtr);

    // Functions for looking up interface instances.  Throw exception if not found.
    ApiServerInterfaceInstance_t* FindServerInterface(const parseTree::Token_t* exeTokenPtr,
                                                      const parseTree::Token_t* componentTokenPtr,
                                                      const parseTree::Token_t* interfaceTokenPtr);
    ApiClientInterfaceInstance_t* FindClientInterface(const parseTree::Token_t* exeTokenPtr,
                                                      const parseTree::Token_t* componentTokenPtr,
                                                      const parseTree::Token_t* interfaceTokenPtr);
    ApiClientInterfaceInstance_t* FindClientInterface(const parseTree::Token_t* interfaceTokenPtr);
    ApiInterfaceInstance_t* FindInterface(const parseTree::Token_t* exeTokenPtr,
                                          const parseTree::Token_t* componentTokenPtr,
                                          const parseTree::Token_t* interfaceTokenPtr);

    // Get the path to the app's root.cfg file relative to the build's working directory.
    std::string ConfigFilePath() const;
};


#endif // LEGATO_MKTOOLS_MODEL_APP_H_INCLUDE_GUARD
