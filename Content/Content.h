#pragma once

#include <QObject>
#include <QDebug>

class Content : public QObject
{
    Q_OBJECT
public:
    explicit Content(QObject *parent = nullptr);
    enum class ContentType{
        Message,
        Command,
        UnknownCommand,
        NonCommandMessage,
        InlineQuery,
        ChosenInlineResult,
        CallbackQuery,
    };
    enum class Place{
        BlackHole,
        Start,
        Church,
        ThyCloset,
        Admin,
        MultiPlace,
    };
    Q_ENUM(Place)
    enum PlaceCommand{
        BlackHole_None,

        Start_Start,
        Start_JoinChurch,

        Admin_CreateChurch,

        MultiPlace_Help,
    };
    Q_ENUM(PlaceCommand)

    static void initContent();
    static Place getPlace(const QString &command);
    static Place getPlace(const std::string &command);
    static QString getCommand(const PlaceCommand placeCommand);
    static bool isEqualCommands(const std::string &command, const PlaceCommand placeCommand);

private:
    static QVector<QPair<Place, QString> > vecPlaceCommand;
};

