#include "Content.h"

#include <QMetaEnum>

QVector<QPair<Content::Place, QString> > Content::vecPlaceCommand;

Content::Content(QObject *parent) : QObject(parent)
{

}

void Content::initContent()
{
    QMetaEnum en = QMetaEnum::fromType<Content::PlaceCommand>();
    for (int var = 0; var < en.keyCount(); ++var) {
        const QByteArray arrKey = en.valueToKeys(var);
        const auto list = arrKey.split('_');
        if (list.size() == 2) {
            const Content::Place place = QVariant::fromValue(list.at(0)).value<Content::Place>();
            vecPlaceCommand.append(qMakePair(place, "/" + list.at(1).toLower()));
        }
    }
    Q_ASSERT(vecPlaceCommand.size() == Content::PlaceCommand::MultiPlace_Help + 1);
}

Content::Place Content::getPlace(const QString &command)
{
    for (const auto &pair: vecPlaceCommand) {
        if (pair.second == command) {
            return pair.first;
        }
    }
    return Place::MultiPlace;
}

Content::Place Content::getPlace(const std::string &command)
{
    return getPlace(QString::fromStdString(command));
}

QString Content::getCommand(const Content::PlaceCommand placeCommand)
{
    if (placeCommand < vecPlaceCommand.size()) {
        return vecPlaceCommand.at(placeCommand).second;
    }
    return {};
}

bool Content::isEqualCommands(const std::string &command, const Content::PlaceCommand placeCommand)
{
    return QString::fromStdString(command).toLower() == getCommand(placeCommand);
}
