#ifndef HANDLEWIDGET_HPP
#define HANDLEWIDGET_HPP

#include <QWidget>
#include <QPushButton>

class HandleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HandleWidget(QWidget *parent = nullptr);

private:
    QPushButton *m_prepareButton;
    QPushButton *m_handleButton;
    QPushButton *m_againButton;

signals:

private slots:
    void onPrepareButtonClicked();
    void onHandleButtonClicked();
    void onAgainButtonClicked();

};

#endif // HANDLEWIDGET_HPP
