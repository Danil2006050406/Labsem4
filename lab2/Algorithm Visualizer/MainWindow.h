#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QListWidget>
#include <vector>

#include "BarWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    QLineEdit* inputField;
    QLabel* resultLabel;
    QLabel* timeLabel;
    QLabel* compareLabel;
    QComboBox* algorithmBox;
    QListWidget* historyList;
    BarWidget* barWidget;

    std::vector<int> currentArray;

    void updateResult();
};