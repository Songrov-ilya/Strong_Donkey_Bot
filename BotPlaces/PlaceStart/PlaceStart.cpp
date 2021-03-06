#include "PlaceStart.h"

PlaceStart::PlaceStart(QObject *parent) : PlaceAbstract(parent)
{

}

void PlaceStart::slotOnCommand(const Message::Ptr &messagePtr, const Content::Command &command)
{
    if (command == Content::Command::Start_Start) {
        sendStartingButtons(messagePtr->chat->id);
    }
    else if (command == Content::Command::MultiPlace_AnyMessage) {
        sendStartingButtons(messagePtr->chat->id);
    }
    else{
        PlaceAbstract::slotOnCommand(messagePtr, command);
    }
}
