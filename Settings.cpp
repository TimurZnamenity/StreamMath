#include "Settings.hpp"
#include <QFile>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>


Settings::Settings()
{

}


QString Settings::value(QString key)
{
    QFile settingsFile { "settings.json" };
    if ( !settingsFile.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        qDebug() << "Unable to open Input Data File";
        return "";
    }

    auto settingsText = settingsFile.readAll();
    QJsonObject jsonObj;
    QJsonDocument jsonDoc;
    QJsonParseError parseError;

    // если пустой текст
    if( settingsText.isEmpty() )
        // возвращаем пустую строку
        return "";

    jsonDoc = QJsonDocument::fromJson(settingsText, &parseError);
    if(parseError.error != QJsonParseError::NoError)
    {
        qDebug() << settingsText;
        qWarning() << "Json parse error: " << parseError.errorString();
    }
    else
    {
        if(jsonDoc.isObject())
            jsonObj  = jsonDoc.object();
        else if (jsonDoc.isArray())
            jsonObj["non_field_errors"] = jsonDoc.array();
    }

    // разбираем объект
    if( jsonObj[key].isUndefined() )
        return "";

    return jsonObj[key].toString();

}
