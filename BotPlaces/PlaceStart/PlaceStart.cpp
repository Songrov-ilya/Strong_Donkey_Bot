#include "PlaceStart.h"

PlaceStart::PlaceStart(QObject *parent) : PlaceAbstract(parent)
{

}

void PlaceStart::slotOnCommand(const Message::Ptr &messagePtr)
{
    qDebug() << "PlaceStart::slotOnCommand" << messagePtr->text.c_str() << Qt::endl;
    if (isEqualCommands(messagePtr->text, Content::PlaceCommand::Start_Start)) {
        responseOnStart(messagePtr);
    }
    else if(isEqualStrings(messagePtr->text, MultiPlaceContent::messageJoinChurch)){
        responseOnJoinChurch(messagePtr);
    }
    else if(isEqualStrings(messagePtr->text, MultiPlaceContent::messageHelp)){
        responseOnHelp(messagePtr);
    }
    else if(isEqualStrings(messagePtr->text, "/new")){
        const QStringList layout { "new 1", "new 2" };
        bot->getApi().sendMessage(messagePtr->chat->id, "ddd", false, 0, createOneColumnReplyKeyboardMarkup(layout));
    }
}

void PlaceStart::responseOnStart(const Message::Ptr &messagePtr)
{
    const QStringList layout { MultiPlaceContent::messageJoinChurch, MultiPlaceContent::messageHelp };
    bot->getApi().sendMessage(messagePtr->chat->id, "f", false, 0, createOneColumnReplyKeyboardMarkup(layout));
}

void PlaceStart::responseOnJoinChurch(const Message::Ptr &messagePtr)
{

}

void PlaceStart::responseOnHelp(const Message::Ptr &messagePtr)
{
    static const QString help { "Hello, child of God."
                                "\n\n"
                                "This bot was created to unite us in prayer. "
                                "You can join your church to share your needs and pray for others. "
                                "You will also have your own closet where you can organize your own prayer life."
                                "\n\n"
                                "Bot features:\n"
                                "- write needs for the whole church\n"
                                "- to see the needs of the church"
                                "- create a hidden list of needs (In the closet)\n"
                                "- share the answer to prayers\n"
                                "\n\n"
                                "If you are an administrator and want to create a church, write '/admin'"};
    bot->getApi().sendMessage(messagePtr->chat->id, help.toStdString());
}
