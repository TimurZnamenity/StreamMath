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
    // эти значения считаем из Settings
    double m_min;
    double m_max;
    double m_step;

    // значения по умолчанию
    const double MIN         = 0.0;
    const double MAX         = 100000000.0;
    const double STEP        = 0.1;
    const long   STEP_AMOUNT = (MAX - MIN) / STEP;

    long    calcStepAmount();
    int     calcPercentage(long step);

signals:
    void prepareProgress(int percent);
    void processProgress(int percent);
};

#endif // INPUTDATA_HPP
