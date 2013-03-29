#include "screencontrolpoint_plugin.h"
#include "screencontrolpoint.h"

#include <qqml.h>

void ScreenControlPointPlugin::registerTypes(const char *uri)
{
    // @uri uk.co.icucinema.ScreenControlPoint
    qmlRegisterType<ScreenControlPoint>(uri, 1, 0, "ScreenControlPoint");
}


