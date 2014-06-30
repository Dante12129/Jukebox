TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    source/gui.cpp \
    source/loader.cpp \
    source/jukebox.cpp \
    source/randomgenerator.cpp

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -pedantic -Wno-unused-local-typedefs -Wno-unused-parameter

LIBS += -LC:/SFML-2.1/bin -LC:/SFML-2.1/Thor-master/bin -LC:/SFML-2.1/SFGUI-0.2.3/bin -LC:/lua-5.2.2/bin -LC:/Users/Main/Documents/Programs/DteEngine/bin -LC:\boost_1_55_0\stage\lib

CONFIG(release, debug|release): LIBS += -lDteEngine -lLua52 -lsfgui -lthor -lsfml-audio-2 -lsfml-graphics-2 -lsfml-network-2 -lsfml-window-2 -lsfml-system-2 - llibboost_regex-mgw48-mt-1_55 -llibboost_filesystem-mgw48-mt-1_55 libboost_system-mgw48-mt-1_55
CONFIG(debug, debug|release): LIBS += -lDteEngine-d -lLua52-d -lsfgui-d -lthor-d -lsfml-audio-d-2 -lsfml-graphics-d-2 -lsfml-network-d-2 -lsfml-window-d-2 -lsfml-system-d-2 -llibboost_regex-mgw48-mt-d-1_55 -llibboost_filesystem-mgw48-mt-d-1_55 libboost_system-mgw48-mt-d-1_55

INCLUDEPATH += C:/SFML-2.1/include C:/SFML-2.1/Thor-master/include C:/SFML-2.1/SFGUI-0.2.3/include C:/lua-5.2.2/include C:/Users/Main/Documents/Programs/DteEngine/DteEngine C:/Users/Main/Documents/Programs/DteEngine/DteEngine/Include C:/boost_1_55_0 C:/Selene/include C:/PicoJSON
DEPENDPATH += C:/SFML-2.1/include C:/SFML-2.1/Thor-master/include C:/SFML-2.1/SFGUI-0.2.3/include C:/lua-5.2.2/include C:/Users/Main/Documents/Programs/DteEngine/DteEngine C:/Users/Main/Documents/Programs/DteEngine/DteEngine/Include C:/boost_1_55_0 C:/Selene/include

HEADERS += \
    include/gui.hpp \
    include/loader.hpp \
    include/jukebox.hpp \
    include/randomgenerator.hpp

