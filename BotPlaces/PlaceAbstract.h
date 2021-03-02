#pragma once

#include <QObject>
#include <QDebug>

//#include "../Content/Content.h"
#include "../GlobalData/GlobalData.h"

#include <tgbot/tgbot.h>
using namespace TgBot;

class PlaceAbstract : public QObject
{
    Q_OBJECT
public:
    explicit PlaceAbstract(QObject *parent = nullptr);

    virtual void slotOnCommand(const Message::Ptr messagePtr);
};

