#pragma once
#include <QWidget>
#include <vector>

class BarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BarWidget(QWidget* parent = nullptr);
    void setArray(const std::vector<int>& arr);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    std::vector<int> array;
};