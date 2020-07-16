#include "libplugin.h"

void
_force_plugin_version(void)
{
    int v;
    plugin_version(&v);
}
