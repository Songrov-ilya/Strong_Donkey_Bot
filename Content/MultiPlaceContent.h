#pragma once

#include <QObject>

class MultiPlaceContent : public QObject
{
    Q_OBJECT
public:
    explicit MultiPlaceContent(QObject *parent = nullptr);

    static const QString messageHelp;
    static const QString messageJoinChurch;
};
