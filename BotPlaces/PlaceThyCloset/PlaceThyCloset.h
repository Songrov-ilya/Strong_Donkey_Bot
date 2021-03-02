#pragma once

#include <QObject>

#include "../PlaceAbstract.h"

class PlaceThyCloset : public PlaceAbstract
{
public:
    explicit PlaceThyCloset(QObject *parent = nullptr);

    virtual void slotOnCommand(const QString &commandName) override;
};

