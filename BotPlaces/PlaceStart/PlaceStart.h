#pragma once

#include <QObject>

#include "../PlaceAbstract.h"

class PlaceStart : public PlaceAbstract
{
public:
    explicit PlaceStart(QObject *parent = nullptr);

    virtual void slotOnCommand(const Message::Ptr &messagePtr) override;

private:
    void responseOnStart(const Message::Ptr &messagePtr);
    void responseOnJoinChurch(const Message::Ptr &messagePtr);
    void responseOnHelp(const Message::Ptr &messagePtr);
};

