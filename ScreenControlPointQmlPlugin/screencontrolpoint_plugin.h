#ifndef SCREENCONTROLPOINT_PLUGIN_H
#define SCREENCONTROLPOINT_PLUGIN_H

#include <QQmlExtensionPlugin>

class ScreenControlPointPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
    
public:
    void registerTypes(const char *uri);
};

#endif // SCREENCONTROLPOINT_PLUGIN_H

