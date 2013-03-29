##### Set up some env vars for Qt apps
export QML2_IMPORT_PATH=/usr/local/qt5pi/imports:/usr/local/qt5pi/qml:$QML2_IMPORT_PATH
export PATH=/opt/CinemaController/bin:$PATH
export LD_LIBRARY_PATH=/opt/hupnp/lib:$LD_LIBRARY_PATH

##### Env Vars for TSLib
export TSLIB_TSDEVICE=/dev/input/by-id/usb-1a86_USB2.0-Ser_-event-if00
export TSLIB_CONFFILE=/etc/ts.conf
export TSLIB_CALIBFILE=/etc/pointercal
export TSLIB_PLUGINDIR=/usr/lib/ts

###### Launch the program
CinemaController -plugin tslib:/dev/input/by-id/usb-1a86_USB2.0-Ser_-event-if00
