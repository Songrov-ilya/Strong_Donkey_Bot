#include "PlaceStart.h"

PlaceStart::PlaceStart(QObject *parent) : PlaceAbstract(parent)
{

}

void PlaceStart::slotOnCommand(const Message::Ptr messagePtr)
{
    qDebug() << "Text1" << Content::getCommand(Content::PlaceCommand::Start_Start) << Qt::endl;
    if (Content::isEqualCommands(messagePtr->text, Content::PlaceCommand::Start_Start)) {
        ReplyKeyboardMarkup::Ptr keyboardJoinChurn(new ReplyKeyboardMarkup);
        std::vector<KeyboardButton::Ptr> row;
        KeyboardButton::Ptr button(new KeyboardButton);
        button->text = "createChurch";
        row.push_back(button);
        keyboardJoinChurn->keyboard.push_back(row);
        bot->getApi().sendMessage(messagePtr->chat->id, "/start for one column keyboard\n/layout for a more complex keyboard",
                                  false, 0, keyboardJoinChurn);
        //        createOneColumnKeyboard({"Option 1", "Option 2", "Option 3"}, keyboardOneCol);
    }
}
