#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QtConcurrent>
#include "SortContext.h"
#include <vector>
#include <random>
#include <fstream>

#include "sequentialmergesorter.h"
#include "parallelmergesorter.h"
#include "Timer.h"



void MainWindow::on_runButton_clicked() {
    int size = ui->sizeInput->text().toInt();

    std::vector<int> data(size);
    std::mt19937 rng(42);

    for (int& x : data)
        x = rng() % 10000;

    std::vector<int> seqData = data;
    std::vector<int> parData = data;

    SequentialMergeSorter seqSorter;
    ParallelMergeSorter parSorter;

    SortContext context;

    Timer timer;
    context.setSorter(&seqSorter);
    timer.start();
    context.execute(seqData);
    double seqTime = timer.stop();

    context.setSorter(&parSorter);
    timer.start();
    context.execute(parData);
    double parTime = timer.stop();

    if (seqData != parData) {
        QMessageBox::critical(this, "Error", "Results are different!");
        return;
    }

    ui->resultLabel->setText(
        "Sequential: " + QString::number(seqTime) + " ms\n" +
        "Parallel: " + QString::number(parTime) + " ms"
    );

    std::ofstream file("results.csv", std::ios::app);

    file << size << ","
        << seqTime << ","
        << parTime << "\n";

    file.close();

    auto future = QtConcurrent::run([=]() mutable {
        std::vector<int> asyncData = data;

        ParallelMergeSorter sorter;
        sorter.sort(asyncData);

        QMetaObject::invokeMethod(this, [=]() {
            ui->resultLabel->setText(
                "Sequential: " + QString::number(seqTime) + " ms\n" +
                "Parallel: " + QString::number(parTime) + " ms\n" +
                "Sorting finished"
                );
            });
        });

}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow() {
    delete ui;
}