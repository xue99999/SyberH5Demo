#include "SyberH5Framework_Workspace.h"


Q_DECL_EXPORT int main(int argc, char *argv[])
{
    return SYBEROS::SyberosGuiCache::qApplication(argc, argv, new SyberH5Framework_Workspace());
}
