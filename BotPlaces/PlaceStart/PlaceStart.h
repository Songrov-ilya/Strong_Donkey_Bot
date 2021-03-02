#pragma once

#include <QObject>

#include "../PlaceAbstract.h"

class PlaceStart : public PlaceAbstract
{
public:
    explicit PlaceStart(QObject *parent = nullptr);

    virtual void slotOnCommand(const Message::Ptr messagePtr) override;
};

