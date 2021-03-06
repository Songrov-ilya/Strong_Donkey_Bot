#include "PlaceAbstract.h"

PlaceAbstract::PlaceAbstract(QObject *parent) : QObject(parent)
{

}

void PlaceAbstract::slotOnCommand(const Message::Ptr &messagePtr, const Content::Command &command)
{
    if (command == Content::Command::Start_Start) {
        sendStartingButtons(messagePtr->chat->id);
    }
    else if (command == Content::Command::MultiPlace_Help) {
        sendStartingButtons(messagePtr->chat->id);
    }
    else{
        qDebug() << "Error! This function is not used!" << command << messagePtr->text.c_str() << Qt::endl;
    }
}

ReplyKeyboardMarkup::Ptr PlaceAbstract::createOneColumnReplyKeyboardMarkup(const QStringList &listButtons, const bool resizeKeyboard, const bool oneTimeKeyboard)
{
    ReplyKeyboardMarkup::Ptr kb(new ReplyKeyboardMarkup);
    for (const QString &textButton : listButtons) {
        std::vector<KeyboardButton::Ptr> row;
        KeyboardButton::Ptr button(new KeyboardButton);
        button->text = textButton.toStdString();
        row.push_back(button);
        kb->keyboard.push_back(row);
    }
    kb->resizeKeyboard = resizeKeyboard;
    kb->oneTimeKeyboard = oneTimeKeyboard;
    return kb;
}

ReplyKeyboardMarkup::Ptr PlaceAbstract::createReplyKeyboardMarkup(const QVector<QStringList> &vecLayouts)
{
    return {};
}

void PlaceAbstract::sendStartingButtons(const int64_t id)
{
    static const QStringList layout { Content::getCommand(Content::ThyCloset_AddPrayerNeed)
                                    , Content::getCommand(Content::ThyCloset_AddAnswerOfGod)
                                    , Content::getCommand(Content::ThyCloset_ListPrayerNeed) };
    static const QString answer { QObject::tr("Hello child of God. This bot is designed to make your prayer life effective. \n\nMay God bless you.") };
    bot->getApi().sendMessage(id, answer.toStdString(), false, 0, createOneColumnReplyKeyboardMarkup(layout));
}
