#include "PlaceStart.h"

PlaceStart::PlaceStart(QObject *parent) : PlaceAbstract(parent)
{

}

void PlaceStart::slotOnCommand(const Message::Ptr messagePtr)
{
    qDebug() << "PlaceStart::slotOnCommand" << messagePtr->text.c_str() << Qt::endl;
    if (isEqualCommands(messagePtr->text, Content::PlaceCommand::Start_Start)) {
        const QStringList layout { MultiPlaceContent::messageJoinChurch, MultiPlaceContent::messageHelp };
        bot->getApi().sendMessage(messagePtr->chat->id, "f", false, 0, createOneColumnReplyKeyboardMarkup(layout));
    }
    else if(isEqualStrings(messagePtr->text, MultiPlaceContent::messageJoinChurch)){
        bot->getApi().sendMessage(messagePtr->chat->id, "Please, enter identification of church");
    }
    else if(isEqualStrings(messagePtr->text, MultiPlaceContent::messageHelp)){
        bot->getApi().sendMessage(messagePtr->chat->id, "This is help mode!");
    }
    else if(isEqualStrings(messagePtr->text, "/new")){
        const QStringList layout { "new 1", "new 2" };
        bot->getApi().sendMessage(messagePtr->chat->id, "ddd", false, 0, createOneColumnReplyKeyboardMarkup(layout));
    }
}
