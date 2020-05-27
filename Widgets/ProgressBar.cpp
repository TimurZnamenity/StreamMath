#include "ProgressBar.hpp"

ProgressBar::ProgressBar(QWidget *parent) : QProgressBar(parent)
{
    setRange(0, 100);
    move(60, 20);
    show();
}
