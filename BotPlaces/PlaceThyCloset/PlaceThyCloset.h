#pragma once

#include <QObject>

#include "../PlaceAbstract.h"

class PlaceThyCloset : public PlaceAbstract
{
public:
    explicit PlaceThyCloset(QObject *parent = nullptr);

    virtual void slotOnCommand(const Message::Ptr &messagePtr, const Content::Command &command) override;

private:
    std::string getListPrayerNeeds(const Message::Ptr &messagePtr);
};

