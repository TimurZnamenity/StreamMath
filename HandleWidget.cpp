#include <QLayout>
#include "ProgressBar.hpp"
#include "HandleWidget.hpp"
#include "Data.hpp"

HandleWidget::HandleWidget(QWidget *parent) : QWidget(parent)
{
    auto layout = new QVBoxLayout(this);

    m_prepareButton = new QPushButton("Подготовить данные");
    connect( m_prepareButton, &QPushButton::clicked,
             this,          &HandleWidget::onPrepareButtonClicked );
    layout->addWidget( m_prepareButton );

    m_handleButton = new QPushButton("Обработать данные");
    connect( m_handleButton, &QPushButton::clicked,
             this,          &HandleWidget::onHandleButtonClicked );
    layout->addWidget( m_handleButton );

    m_againButton = new QPushButton("Теперь всё снова");
    connect( m_againButton, &QPushButton::clicked,
             this,          &HandleWidget::onAgainButtonClicked );
    layout->addWidget( m_againButton );

    setLayout( layout );

    m_prepareButton->setEnabled( true  );
    m_handleButton->setEnabled ( false );
    m_againButton->setEnabled  ( false );
}

void HandleWidget::onPrepareButtonClicked()
{
    m_prepareButton->setEnabled( false );
    m_handleButton->setEnabled ( true  );
    m_againButton->setEnabled  ( false );

    std::unique_ptr<ProgressBar> bar{new ProgressBar(this)};
    std::unique_ptr<Data> data{new Data(this)};
    connect( data.get(), &Data::prepareProgress,
             bar.get(),  &ProgressBar::setValue);
    data.get()->prepare();
}

void HandleWidget::onHandleButtonClicked()
{
    m_prepareButton->setEnabled( false );
    m_handleButton->setEnabled ( false );
    m_againButton->setEnabled  ( true  );

    std::unique_ptr<ProgressBar> bar{new ProgressBar(this)};
    std::unique_ptr<Data> data{new Data(this)};
    connect( data.get(), &Data::processProgress,
             bar.get(),  &ProgressBar::setValue);
    data.get()->process();
}

void HandleWidget::onAgainButtonClicked()
{
    m_prepareButton->setEnabled( true  );
    m_handleButton->setEnabled ( false );
    m_againButton->setEnabled  ( false );
}

