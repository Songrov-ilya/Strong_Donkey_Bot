#pragma once

#include <QObject>
#include <QString>

#include "GlobalData/GlobalData.h"
#include "Content/Content.h"
#include "BotPlaces/PlaceThyCloset/PlaceThyCloset.h"
#include "BotPlaces/PlaceAdditional/PlaceAdditional.h"

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
    void anyMessageWasWrite(const Message::Ptr messagePtr);
    void callbackQueryWasWrite(const CallbackQuery::Ptr callbackQuery);

    void changePlaceBot(const Content::Place place);

private:
    PlaceThyCloset      *placeThyCloset ;
    PlaceAdditional     *placeAdditional;
    PlaceAbstract       *placeBot       ;
};

