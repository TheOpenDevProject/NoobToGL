TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
LIBS += $$quote(/usr/local/lib/libglfw.so.3) -glfw3
LIBS += -lGL -ldl
SOURCES += main.cpp \
    glad.c \
    display.cpp \
    glmathtoolkit.cpp \
    shader.cpp \
    mesh.cpp

HEADERS += \
    glad/glad.h \
    KHR/khrplatform.h \
    display.h \
    glmathtoolkit.h \
    shader.h \
    mesh.h
QMAKE_CXXFLAGS += -g -rdynamic

DISTFILES += \
    basicshader.vs \
    basicshader.fs
