#include "Data.hpp"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QString>
#include <cmath>


Data::Data()
{

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

    for( double x = 0; x < 100; x += 0.1)
    {
        double first  = std::sin(x);
        double second = 0; //std::srand( sizeof(x) );
        double y = first + second;

        out << QString("%1").arg(y) << "\n";
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
    while ( !in.atEnd() )
    {
        QString line = in.readLine();

        double y = calculate( line.toDouble() );

        out << QString("%1").arg(y) << "\n";
    }

    inputDataFile.close();
    outputDataFile.close();
}


double Data::calculate(const double arg)
{
    return arg + 0.1234;
}
