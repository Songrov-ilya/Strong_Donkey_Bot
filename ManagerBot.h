#pragma once

#include <QObject>
#include <QString>

#include "GlobalData/GlobalData.h"
#include "Content/Content.h"
#include "BotPlaces/PlaceStart/PlaceStart.h"
#include "BotPlaces/PlaceThyCloset/PlaceThyCloset.h"
#include "BotPlaces/PlaceAdmin/PlaceAdmin.h"

#include <tgbot/tgbot.h>
using namespace TgBot;

class ManagerBot : public QObject
{
    Q_OBJECT

public:
    explicit ManagerBot(const QString token, QObject *parent = nullptr);

    void startBot();

private:
    void setSettings();
    void commandWasWrite(const Message::Ptr messagePtr);

private:
    PlaceStart      *placeStart     ;
    PlaceThyCloset  *placeThyCloset ;
    PlaceAdmin      *placeAdmin     ;
    PlaceAbstract   *placeBot       ;
};

