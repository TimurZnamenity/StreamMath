#ifndef INPUTDATA_HPP
#define INPUTDATA_HPP

#include <QObject>


class Data : public QObject
{
    Q_OBJECT
public:
    Data(QObject *parent = nullptr);

    void prepare();

    void process();

    double calculate(const double arg);

private:
    const double MIN         = 0.0;
    const double MAX         = 100000.0;
    const double STEP        = 0.1;
    const double STEP_AMOUNT = (MAX - MIN) / STEP;


    int calcPercentage(long step);

signals:
    void prepareProgress(int percent);
    void processProgress(int percent);
};

#endif // INPUTDATA_HPP
