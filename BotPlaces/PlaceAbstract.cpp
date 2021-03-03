#include "PlaceAbstract.h"

PlaceAbstract::PlaceAbstract(QObject *parent) : QObject(parent)
{

}

void PlaceAbstract::slotOnCommand(const Message::Ptr messagePtr)
{

}

bool PlaceAbstract::isEqualStrings(const std::string &a, const QString &b)
{
    return a == b.toStdString();
}

bool PlaceAbstract::isEqualCommands(const std::string &command, const Content::PlaceCommand placeCommand)
{
    return Content::isEqualCommands(command, placeCommand);
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

}
