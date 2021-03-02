#pragma once

#include <QObject>

#include <tgbot/tgbot.h>
using namespace TgBot;

extern std::unique_ptr<Bot> bot;

void initGlobalData(const QString &token);

