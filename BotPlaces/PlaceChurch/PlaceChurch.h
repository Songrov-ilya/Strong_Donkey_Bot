#pragma once

#include <QObject>

#include "../PlaceAbstract.h"

class PlaceChurch : public PlaceAbstract
{
public:
    explicit PlaceChurch(QObject *parent = nullptr);

    virtual void slotOnCommand(const Message::Ptr &messagePtr) override;
};

