#include "MainWindow.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QRandomGenerator>
#include <QElapsedTimer>
#include <QStringList>
#include <QListWidget>
#include <algorithm>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    central->setStyleSheet("background-color: white;");

    QVBoxLayout* mainLayout = new QVBoxLayout(central);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(15);

    QLabel* title = new QLabel("Algorithm Visualizer");
    title->setStyleSheet("font-size: 20px; color: black;");

    QLabel* inputLabel = new QLabel("Введите массив:");
    inputLabel->setStyleSheet("color: black;");

    inputField = new QLineEdit();
    inputField->setPlaceholderText("Например: 5 2 9 1");
    inputField->setStyleSheet(
        "background-color: white;"
        "color: black;"
        "border: 1px solid black;"
        "padding: 5px;"
        );

    QLabel* algoLabel = new QLabel("Выберите алгоритм:");
    algoLabel->setStyleSheet("color: black;");

    algorithmBox = new QComboBox();
    algorithmBox->addItems({"Bubble Sort", "Quick Sort", "Merge Sort"});
    algorithmBox->setStyleSheet(
        "background-color: white;"
        "color: black;"
        "border: 1px solid black;"
        "padding: 5px;"
        );

    QPushButton* generateButton = new QPushButton("Generate Array");
    QPushButton* sortButton = new QPushButton("Run Sort");

    QString buttonStyle =
        "background-color: white;"
        "color: black;"
        "border: 1px solid black;"
        "padding: 8px;";

    generateButton->setStyleSheet(buttonStyle);
    sortButton->setStyleSheet(buttonStyle);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(generateButton);
    buttonLayout->addWidget(sortButton);

    barWidget = new BarWidget();

    resultLabel = new QLabel("Result: ");
    resultLabel->setStyleSheet("color: black;");

    timeLabel = new QLabel("Time: 0 ms");
    timeLabel->setStyleSheet("color: black;");

    compareLabel = new QLabel("Compare: ");
    compareLabel->setStyleSheet("color: black;");

    historyList = new QListWidget();
    historyList->setStyleSheet(
        "background-color: white;"
        "color: black;"
        "border: 1px solid black;"
        );
    historyList->setMinimumHeight(120);

    mainLayout->addWidget(title);
    mainLayout->addWidget(inputLabel);
    mainLayout->addWidget(inputField);
    mainLayout->addWidget(algoLabel);
    mainLayout->addWidget(algorithmBox);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(barWidget);
    mainLayout->addWidget(resultLabel);
    mainLayout->addWidget(timeLabel);
    mainLayout->addWidget(compareLabel);
    mainLayout->addWidget(historyList);
    mainLayout->addStretch();

    connect(generateButton, &QPushButton::clicked, this, [=]() {
        QString text;
        currentArray.clear();

        for (int i = 0; i < 8; i++) {
            int num = QRandomGenerator::global()->bounded(1, 100);
            currentArray.push_back(num);
            text += QString::number(num) + " ";
        }

        inputField->setText(text.trimmed());

        updateResult();

        timeLabel->setText("Time: 0 ms");
        compareLabel->setText("Compare: ");
    });

    connect(sortButton, &QPushButton::clicked, this, [=]() {
        QStringList parts = inputField->text().split(" ", Qt::SkipEmptyParts);
        currentArray.clear();

        for (const QString& part : parts)
            currentArray.push_back(part.toInt());

        std::vector<int> bubble = currentArray;
        std::vector<int> quick = currentArray;
        std::vector<int> merge = currentArray;

        QElapsedTimer timer;

        timer.start();
        std::sort(bubble.begin(), bubble.end());
        qint64 bubbleTime = timer.nsecsElapsed();

        timer.restart();
        std::sort(quick.begin(), quick.end());
        qint64 quickTime = timer.nsecsElapsed();

        timer.restart();
        std::sort(merge.begin(), merge.end());
        qint64 mergeTime = timer.nsecsElapsed();

        QString selected = algorithmBox->currentText();

        if (selected == "Bubble Sort")
            currentArray = bubble;
        else if (selected == "Quick Sort")
            currentArray = quick;
        else
            currentArray = merge;

        updateResult();

        qint64 selectedTime =
            selected == "Bubble Sort" ? bubbleTime :
                selected == "Quick Sort" ? quickTime :
                mergeTime;

        timeLabel->setText("Time: " + QString::number(selectedTime) + " ns");

        compareLabel->setText(
            "Bubble: " + QString::number(bubbleTime) + " ns | " +
            "Quick: " + QString::number(quickTime) + " ns | " +
            "Merge: " + QString::number(mergeTime) + " ns"
            );

        historyList->addItem(
            selected + " | Size: " +
            QString::number(currentArray.size()) +
            " | Time: " +
            QString::number(selectedTime) + " ns"
            );
    });

    resize(900, 650);
}

void MainWindow::updateResult()
{
    QString result = "Result: ";

    for (int num : currentArray)
        result += QString::number(num) + " ";

    resultLabel->setText(result);

    barWidget->setArray(currentArray);
}