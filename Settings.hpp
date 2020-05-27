#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QString>

class Settings
{
public:
    Settings();

    static QString value(QString key);
};

#endif // SETTINGS_HPP
