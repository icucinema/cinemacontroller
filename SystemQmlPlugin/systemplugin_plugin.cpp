#include "systemplugin_plugin.h"
#include "system.h"

#include <qqml.h>

void SystempluginPlugin::registerTypes(const char *uri)
{
    // @uri uk.co.icucinema.System
    qmlRegisterType<System>(uri, 1, 0, "System");
}


