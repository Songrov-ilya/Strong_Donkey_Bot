#include "ManagerBot.h"


ManagerBot::ManagerBot(QObject *parent) : QObject(parent)
  , token("1074139558:AAHPrCJFleoqGnMAYmO2aKldpLTbxvAtplc")
  , bot(token.toStdString())
  , currentPlace(Content::Place::BlackHole)
{
//    printf("Token: %s\n", token.toUtf8().constData());

//    Bot bot(token.toUtf8().constData());

//    ReplyKeyboardMarkup::Ptr keyboardOneCol(new ReplyKeyboardMarkup);
//    createOneColumnKeyboard({"Option 1", "Option 2", "Option 3"}, keyboardOneCol);

//    ReplyKeyboardMarkup::Ptr keyboardWithLayout(new ReplyKeyboardMarkup);
//    createKeyboard({
//      {"Dog", "Cat", "Mouse"},
//      {"Green", "White", "Red"},
//      {"On", "Off"},
//      {"Back"},
//      {"Info", "About", "Map", "Etc"}
//    }, keyboardWithLayout);

//    bot.getEvents().onCommand("start", [&bot, &keyboardOneCol](Message::Ptr message) {
//        bot.getApi().sendMessage(message->chat->id, "/start for one column keyboard\n/layout for a more complex keyboard", false, 0, keyboardOneCol);
//    });
//    bot.getEvents().onCommand("layout", [&bot, &keyboardWithLayout](Message::Ptr message) {
//        bot.getApi().sendMessage(message->chat->id, "/start for one column keyboard\n/layout for a more complex keyboard", false, 0, keyboardWithLayout);
//    });
//    bot.getEvents().onNonCommandMessage([&bot](Message::Ptr message) {
//        printf("User wrote onNonCommandMessage %s\n", message->text.c_str());
//        if (StringTools::startsWith(message->text, "/start") || StringTools::startsWith(message->text, "/layout")) {
//            return;
//        }
//        bot.getApi().sendMessage(message->chat->id, "onNonCommandMessage Your message is: " + message->text);
//    });
//    bot.getEvents().onAnyMessage([&bot](Message::Ptr message) {
//        printf("User wrote onAnyMessage %s\n", message->text.c_str());
//        if (StringTools::startsWith(message->text, "/start") || StringTools::startsWith(message->text, "/layout")) {
//            return;
//        }
//        bot.getApi().sendMessage(message->chat->id, "onAnyMessage Your message is: " + message->text);
//    });

//    signal(SIGINT, [](int s) {
//        printf("SIGINT got\n");
//        exit(0);
//    });

//    try {
//        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
//        bot.getApi().deleteWebhook();

//        TgLongPoll longPoll(bot);
//        while (true) {
//            printf("Long poll started\n");
//            longPoll.start();
//        }
//    } catch (exception& e) {
//        printf("error: %s\n", e.what());
//    }

    placeStart     = new PlaceStart    (this);
    placeChurch    = new PlaceChurch   (this);
    placeThyCloset = new PlaceThyCloset(this);
    placeAdmin     = new PlaceAdmin    (this);
    placeBot        = placeStart;
    setSettings();
}

void ManagerBot::startBot()
{
    Content::initContent();
}

void ManagerBot::setSettings()
{
//    bot.getEvents().onUnknownCommand(std::bing(&ManagerBot::commandWasWrite, this, std::placeholders::_1));
}

void ManagerBot::commandWasWrite(const QString &command)
{
    const Content::Place place = Content::getPlace(command);
    currentPlace = place != Content::Place::MultiPlace ? place : currentPlace;

    switch (place) {
    case Content::Place::Start:
        placeBot = placeStart;
        break;
    case Content::Place::Church:
        placeBot = placeChurch;
        break;
    case Content::Place::ThyCloset:
        placeBot = placeThyCloset;
        break;
    case Content::Place::Admin:
        placeBot = placeAdmin;
        break;
    case Content::Place::MultiPlace:
        break;
    default:
        break;
    }
    placeBot->slotOnCommand(command);
}
