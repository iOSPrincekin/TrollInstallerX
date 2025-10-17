//
//  Use this file to import your target's public headers that you would like to expose to Swift.
//

#import <IOKit/IOKitLib.h>

// Only include headers that don't have problematic system dependencies
#include "Exploitation/MacDirtyCow/grant_full_disk_access.h"
#include "Exploitation/dmaFail/dmaFail.h"
#include "Exploitation/kfd/kfd.h"

#include "External/include/libgrabkernel2/libgrabkernel2.h"

// Forward declarations for functions that are needed
// These will be implemented in the corresponding .m/.c files
int64_t sandbox_extension_consume(const char* token);

// Function declarations that are needed by Swift code
void grant_full_disk_access(void (^_Nonnull completion)(NSError* _Nullable));

// Forward declarations for functions that have problematic dependencies
// These can be added back if the dependency issues are resolved
bool initialise_kernel_info(const char *kernelPath, bool iOS14);
bool patch_kernel_info(void);

// Forward declarations for functions from libjailbreak/util.h
int libarchive_unarchive(const char *fileToExtract, const char *extractionPath);

// Forward declarations for functions from libjailbreak/vnode.h
NSArray *get_installed_apps(void);
bool install_persistence_helper_via_vnode(const char *bundlePath);
void restartBackboard(void);

// Forward declarations for functions from MacDirtyCow/helpers.h
bool kernel_find(void);
bool helpers(void);

// Forward declarations for functions from dmaFail/dmaFail.h
bool dmaFail(void);

// Forward declarations for functions from kfd/kfd.h
bool kfd(void);

// Forward declarations for functions from libgrabkernel2/libgrabkernel2.h
bool libgrabkernel2(void);

// Forward declarations for functions from patchfind/patchfind.h
bool patchfind(void);

// Forward declarations for functions from installer headers
bool escalate(void);
bool install(void);
bool remount(void);
bool run(void);
bool update(void);

// Additional functions needed by Swift code
NSString *find_path_for_app(NSString *appName);
bool install_trollstore(NSString *tar);
bool install_persistence_helper(NSString *app);
NSString* get_NSString_from_file(int fd);
int run_binary(NSString* path, NSArray* args, NSString** output);
void post_kernel_exploit(bool iOS14);
bool build_physrw_primitive(void);
bool get_root_krw(bool iOS14);
bool drop_root_krw(bool iOS14);
bool get_root_pplrw(void);
bool unsandbox(void);
bool platformise(void);
NSString *get_kernelcache_path(void);
bool libjailbreak_kalloc_pt_init(void);
bool remount_private_preboot(void);
bool is_persistence_helper_installed(const char *path);
void github_fetchLatestVersion(NSString *repo, void (^completion)(NSString *version));
