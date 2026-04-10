#include "BarWidget.h"
#include <QPainter>

BarWidget::BarWidget(QWidget* parent)
    : QWidget(parent)
{
    setMinimumHeight(200);
}

void BarWidget::setArray(const std::vector<int>& arr)
{
    array = arr;
    update();
}

void BarWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    painter.fillRect(rect(), Qt::white);

    if (array.empty())
        return;

    int barWidth = width() / array.size();

    for (size_t i = 0; i < array.size(); i++)
    {
        int barHeight = array[i] * 2;

        painter.drawRect(
            i * barWidth,
            height() - barHeight,
            barWidth - 5,
            barHeight
            );
    }
}