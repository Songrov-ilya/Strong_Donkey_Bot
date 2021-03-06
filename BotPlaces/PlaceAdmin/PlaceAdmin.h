#pragma once

#include <QObject>

#include "../PlaceAbstract.h"

class PlaceAdmin : public PlaceAbstract
{
public:
    explicit PlaceAdmin(QObject *parent = nullptr);

    virtual void slotOnCommand(const Message::Ptr &messagePtr) override;
};

