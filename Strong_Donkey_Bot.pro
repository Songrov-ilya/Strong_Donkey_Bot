QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BotPlaces/PlaceAbstract.cpp \
    BotPlaces/PlaceAdmin/PlaceAdmin.cpp \
    BotPlaces/PlaceChurch/PlaceChurch.cpp \
    BotPlaces/PlaceStart/PlaceStart.cpp \
    BotPlaces/PlaceThyCloset/PlaceThyCloset.cpp \
    Content/Content.cpp \
    ManagerBot.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    BotPlaces/PlaceAbstract.h \
    BotPlaces/PlaceAdmin/PlaceAdmin.h \
    BotPlaces/PlaceChurch/PlaceChurch.h \
    BotPlaces/PlaceStart/PlaceStart.h \
    BotPlaces/PlaceThyCloset/PlaceThyCloset.h \
    Content/Content.h \
    ManagerBot.h \
    mainwindow.h \
    tgbot/include/tgbot/tgbot.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += \
    tgbot/include


unix:!macx: LIBS += -L$$PWD/tgbot -lTgBot
INCLUDEPATH += $$PWD/tgbot
DEPENDPATH  += $$PWD/tgbot
unix:!macx: PRE_TARGETDEPS += $$PWD/tgbot/libTgBot.a

#-lTgBot -lboost_system -lssl -lcrypto -lpthread
unix:!macx: LIBS += -lboost_system
unix:!macx: LIBS += -lssl
unix:!macx: LIBS += -lcrypto
unix:!macx: LIBS += -lpthread


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
