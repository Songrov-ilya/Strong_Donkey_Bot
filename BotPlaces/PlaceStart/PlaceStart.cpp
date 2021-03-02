#include "PlaceStart.h"

PlaceStart::PlaceStart(QObject *parent) : PlaceAbstract(parent)
{

}

void PlaceStart::slotOnCommand(const Message::Ptr messagePtr)
{
//    qDebug() << "Text" << messagePtr->text.c_str() << Qt::endl;
}
