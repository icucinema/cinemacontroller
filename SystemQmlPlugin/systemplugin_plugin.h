#ifndef SYSTEMPLUGIN_PLUGIN_H
#define SYSTEMPLUGIN_PLUGIN_H

#include <QQmlExtensionPlugin>

class SystempluginPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
    
public:
    void registerTypes(const char *uri);
};

#endif // SYSTEMPLUGIN_PLUGIN_H

