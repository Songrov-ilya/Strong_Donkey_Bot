#include "Content.h"

#include <QMetaEnum>
#include <QPair>

QVector<QPair<Content::PlaceCommand, QString> > Content::vecPlaceCommand{
            {   Content::PlaceCommand(Content::Place::Start, Content::Start_Start), "/start"                                                },

            {   Content::PlaceCommand(Content::Place::ThyCloset, Content::ThyCloset_AddPrayerNeed), QObject::tr("🙏 Add prayer need")       },
            {   Content::PlaceCommand(Content::Place::ThyCloset, Content::ThyCloset_AddAnswerOfGod), QObject::tr("✔️ Add answer of God")    },
            {   Content::PlaceCommand(Content::Place::ThyCloset, Content::ThyCloset_ListPrayerNeed), QObject::tr("🗒 List of prayer needs") },

            {   Content::PlaceCommand(Content::Place::Admin, Content::Admin_DeletePrayerNeed), QObject::tr("Delete prayer need")        },
            {   Content::PlaceCommand(Content::Place::Admin, Content::Admin_DeleteHistory), QObject::tr("Delete history")               },
};

Content::Content(QObject *parent) : QObject(parent)
{

}

void Content::initContent()
{
    //    QMetaEnum en = QMetaEnum::fromType<Content::PlaceCommand>();
    //    for (int var = 0; var < en.keyCount(); ++var) {
    //        const QByteArray arrKey = en.valueToKeys(var);
    //        const auto list = arrKey.split('_');
    //        if (list.size() == 2) {
    //            const Content::Place place = QVariant::fromValue(list.at(0)).value<Content::Place>();
    //            vecPlaceCommand.append(qMakePair(place, "/" + list.at(1).toLower()));
    //        }
    //    }
    //    Q_ASSERT(vecPlaceCommand.size() == Content::PlaceCommand::MultiPlace_Help + 1);
}

Content::PlaceCommand Content::getPlaceCommand(const QString &command)
{
    for (const auto &pair: qAsConst(vecPlaceCommand)) {
        if (pair.second == command) {
            return pair.first;
        }
    }
    return {};
}

Content::PlaceCommand Content::getPlaceCommand(const std::string &command)
{
    return getPlaceCommand(QString::fromStdString(command));
}

QString Content::getCommand(const Content::Command placeCommand)
{
    if (placeCommand < vecPlaceCommand.size()) {
        return vecPlaceCommand.at(placeCommand).second;
    }
    return {};
}
