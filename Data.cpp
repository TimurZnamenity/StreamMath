#include "Data.hpp"
#include "Settings.hpp"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QString>
#include <cmath>


Data::Data(QObject *parent) : QObject(parent)
{
    auto min  = Settings::value("min");
    m_min = min.isEmpty()? MIN: min.toDouble();

    auto max  = Settings::value("max");
    m_max = max.isEmpty()? MAX: max.toDouble();

    auto step = Settings::value("step");
    m_step = step.isEmpty()? STEP: step.toDouble();
}


void Data::prepare()
{
    QFile inputDataFile { "in.dat" };
    if ( !inputDataFile.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {
        qDebug() << "Unable to open Input Data File";
        return;
    }

    QTextStream out( &inputDataFile );

    long step = 0;
    for( double x = MIN; x < MAX; x += STEP)
    {
        double first  = std::sin(x);
        double second = 0; //std::srand( sizeof(x) );
        double y = first + second;

        out << QString("%1").arg(y) << "\n";

        // считаем проценты выполнения
        emit prepareProgress( calcPercentage(step++) );
    }

    inputDataFile.close();
}


void Data::process()
{
    QFile inputDataFile  {  "in.dat" };
    if ( !inputDataFile.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        qDebug() << "Unable to open Input Data File";
        return;
    }

    QFile outputDataFile { "out.dat" };
    if ( !outputDataFile.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {
        qDebug() << "Unable to open Output Data File";
        return;
    }

    QTextStream out( &outputDataFile );
    QTextStream in( &inputDataFile );
    long step = 0;
    while ( !in.atEnd() )
    {
        QString line = in.readLine();

        double y = calculate( line.toDouble() );

        out << QString("%1").arg(y) << "\n";

        // считаем проценты выполнения
        emit processProgress( calcPercentage(step++) );
    }

    inputDataFile.close();
    outputDataFile.close();
}


double Data::calculate(const double arg)
{
    return arg + 0.1234;
}


long Data::calcStepAmount()
{
    return (m_max - m_min) / m_step;
}


int Data::calcPercentage(long step)
{
    long percent = (step * 100) / calcStepAmount();
    return static_cast<int>(percent);
}
