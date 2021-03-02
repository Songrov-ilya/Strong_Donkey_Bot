#include "GlobalData.h"

std::unique_ptr<Bot> bot(nullptr);

void initGlobalData(const QString &token)
{
    bot.reset(new Bot(token.toStdString()));
}
