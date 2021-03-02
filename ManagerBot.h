#pragma once

#include <QObject>
#include <QString>

#include <tgbot/tgbot.h>

#include "Content/Content.h"
#include "BotPlaces/PlaceStart/PlaceStart.h"
#include "BotPlaces/PlaceChurch/PlaceChurch.h"
#include "BotPlaces/PlaceThyCloset/PlaceThyCloset.h"
#include "BotPlaces/PlaceAdmin/PlaceAdmin.h"

using namespace TgBot;

class ManagerBot : public QObject
{
    Q_OBJECT

public:
    explicit ManagerBot(QObject *parent = nullptr);

    void startBot();

private:
    void setSettings();
    void commandWasWrite(const QString &command);

private:
    const QString token;
    Bot bot;
    Content::Place currentPlace;
    PlaceStart      *placeStart     ;
    PlaceChurch     *placeChurch    ;
    PlaceThyCloset  *placeThyCloset ;
    PlaceAdmin      *placeAdmin     ;
    PlaceAbstract *placeBot;
};

