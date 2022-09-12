#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"animal.h"
#include<QApplication>
#include<QtCharts/QChartView>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QHorizontalStackedBarSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>
#include<QtCharts/QPieSeries>
#include<QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QBarSet *set0 = new QBarSet("Nombre");
     animal a;
       *set0 << a.CalculAnimalType("chien") << a.CalculAnimalType("cheval") <<a.CalculAnimalType("chat")<<a.CalculAnimalType("volaille") <<a.CalculAnimalType("bovin");


       QBarSeries *series = new QBarSeries();
          series->append(set0);

          QChart *chart = new QChart();
              chart->addSeries(series);
              chart->setTitle("Statistique des nombres des animaux par rapport à leurs types");
              chart->setAnimationOptions(QChart::SeriesAnimations);
              QStringList categories;
                 categories << "Chien" << "Cheval" << "Chat"  << "volaille"<<"Bovin";
                 QBarCategoryAxis *axisX = new QBarCategoryAxis();
                 axisX->append(categories);
                 chart->addAxis(axisX, Qt::AlignBottom);
                 series->attachAxis(axisX);

                 QValueAxis *axisY = new QValueAxis();
                 axisY->setRange(0,10);
                 chart->addAxis(axisY, Qt::AlignLeft);
                 series->attachAxis(axisY);
                 chart->legend()->setVisible(true);
                    chart->legend()->setAlignment(Qt::AlignBottom);
                    QChartView *chartView = new QChartView(chart);
                        chartView->setRenderHint(QPainter::Antialiasing);
                        setCentralWidget(chartView);

}

MainWindow::~MainWindow()
{
    delete ui;
}

