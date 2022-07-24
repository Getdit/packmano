QT       += core gui multimedia widgets

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        block.cpp \
        bomb.cpp \
        cherry.cpp \
        enemy.cpp \
        game.cpp \
        goldapple.cpp \
        main.cpp \
        menu.cpp \
        player.cpp \
        records.cpp \
        score.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    block.h \
    bomb.h \
    cherry.h \
    enemy.h \
    game.h \
    goldapple.h \
    menu.h \
    player.h \
    records.h \
    score.h

RESOURCES += \
    res.qrc

FORMS += \
    menu.ui \
    records.ui
