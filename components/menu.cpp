#include <QWidget>
#include <QVBoxLayout>
#include <QPainter>
#include "menu.h"

MenuItem::MenuItem(QWidget *parent)
    : FlatButton(parent)
{
}

MenuItem::MenuItem(const QString &text, QWidget *parent)
    : FlatButton(text, parent)
{
}

MenuItem::~MenuItem()
{
}

QSize MenuItem::sizeHint() const
{
    return FlatButton::sizeHint().expandedTo(QSize(200, 40));
}

Menu::Menu(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;
    setLayout(layout);

    layout->setMargin(0);
    layout->setSpacing(0);

    QSizePolicy policy;
    policy.setVerticalPolicy(QSizePolicy::Maximum);
    setSizePolicy(policy);
}

Menu::~Menu()
{
}

void Menu::addMenuItem(MenuItem *item)
{
    _items.push_back(item);
    layout()->addWidget(item);
}

void Menu::addMenuItem(const QString &text)
{
    addMenuItem(new MenuItem(text));
}

void Menu::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.fillRect(rect(), Qt::white);
    painter.drawRect(rect().adjusted(0, 0, -1, -1));

    QWidget::paintEvent(event);
}
