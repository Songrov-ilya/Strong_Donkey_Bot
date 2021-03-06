#pragma once

#include <QObject>
#include <QDebug>

#include "../Content/Content.h"
#include "../Content/MultiPlaceContent.h"
#include "../GlobalData/GlobalData.h"

#include <tgbot/tgbot.h>
using namespace TgBot;

class PlaceAbstract : public QObject
{
    Q_OBJECT
public:
    explicit PlaceAbstract(QObject *parent = nullptr);

    virtual void slotOnCommand(const Message::Ptr &messagePtr);

protected:
    bool isEqualStrings(const std::string &a, const QString &b);
    bool isEqualCommands(const std::string &command, const Content::PlaceCommand placeCommand);
    ReplyKeyboardMarkup::Ptr createOneColumnReplyKeyboardMarkup(const QStringList &listButtons, const bool resizeKeyboard = true, const bool oneTimeKeyboard = false);
    ReplyKeyboardMarkup::Ptr createReplyKeyboardMarkup(const QVector<QStringList> &vecLayouts);
};

