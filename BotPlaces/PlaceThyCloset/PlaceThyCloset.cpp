#include "PlaceThyCloset.h"

PlaceThyCloset::PlaceThyCloset(QObject *parent) : PlaceAbstract(parent)
{

}

void PlaceThyCloset::slotOnCommand(const Message::Ptr &messagePtr, const Content::Command &command)
{
    if (command == Content::Command::ThyCloset_AddPrayerNeed) {
        static const auto answer { QObject::tr("Write your prayer need:").toStdString() };
        bot->getApi().sendMessage(messagePtr->chat->id, answer);
    }
    else if (command == Content::Command::ThyCloset_AddAnswerOfGod) {
        static const auto answer { QObject::tr("Write number of prayer need:").toStdString() };
        bot->getApi().sendMessage(messagePtr->chat->id, answer);
    }
    else if (command == Content::Command::ThyCloset_ListPrayerNeed) {
        bot->getApi().sendMessage(messagePtr->chat->id, getListPrayerNeeds(messagePtr));
    }
    else{
        PlaceAbstract::slotOnCommand(messagePtr, command);
    }
}

std::string PlaceThyCloset::getListPrayerNeeds(const Message::Ptr &messagePtr)
{
    return QStringList({"Church", "Youth", "Child"}).join("\n").toStdString();
}
