QT     += core gui qml quickcontrols2

TARGET = appload
TEMPLATE = app

SOURCES +=  src/main.cpp src/management.cpp src/AppLoad.cpp src/AppLoadCoordinator.cpp src/library.cpp \
            src/qtfb/fbmanagement.cpp src/qtfb/FBController.cpp

HEADERS +=  src/AppLoad.h src/AppLoadCoordinator.h src/library.h src/AppLibrary.h \
            src/qtfb/FBController.h src/qtfb/fbmanagement.h

RESOURCES += resources/resources.qrc
