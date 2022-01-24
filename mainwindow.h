#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gestore.h"
#include <QMainWindow>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <QComboBox>
using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    Gestore gestore;

    void setCheckedComboBoxProgettiDS(QComboBox* comboBox);
    void setCheckedComboBoxSubordinatiDS(QComboBox* comboBox);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void testBool();


private slots:
    void on_DipendentiPushButton_clicked();
    void on_HomePushButton_clicked();
    void on_ProgettiPushButton_clicked();

    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_B1PushButton_clicked();
    void on_B2PushButton_clicked();
    void on_B3PushButton_clicked();
    void on_B4PushButton_clicked();
    void on_B5PushButton_clicked();
    void on_B6PushButton_clicked();
    void on_B7PushButton_clicked();
    void on_B8PushButton_clicked();
    void on_B9PushButton_clicked();
    void on_B10PushButton_clicked();
    void on_B11PushButton_clicked();
    void on_B12PushButton_clicked();
    void on_B13PushButton_clicked();
    void on_B14pushButton_clicked();
    void on_IndietroPushButton_clicked();
    void on_IndietroPushButton_2_clicked();
    void on_IndietroPushButton_3_clicked();
    void on_IndietroPushButton_4_clicked();
    void on_IndietroPushButton_5_clicked();
    void on_IndietroPushButton_6_clicked();
    void on_IndietroPushButton_7_clicked();
    void on_IndietroPushButton_8_clicked();
    void on_IndietroPushButton_9_clicked();
    void on_IndietroPushButton_10_clicked();
    void on_IndietroPushButton_11_clicked();
    void on_IndietroPushButton_12_clicked();
    void on_IndietroPushButton_13_clicked();
    void on_IndietroPushButton_14_clicked();
    void on_A6PushButton_clicked();
    void on_AggiungiDSPushButton_clicked();
    void on_pushButton_8_clicked();
    void on_B2ComboBox_currentTextChanged(const QString &arg1);
    void on_B1ComboBox_currentTextChanged(const QString &arg1);
    void on_B3ComboBox_currentTextChanged(const QString &arg1);
    void on_StagistaComboBox_currentTextChanged(const QString &arg1);
    void on_AggiungiDJpushButton_clicked();
    void on_pushButton_2_clicked();
    void on_B7ComboBox_currentTextChanged(const QString &arg1);
    void on_B8ComboBox_currentTextChanged(const QString &arg1);
    void on_B9ComboBox_currentTextChanged(const QString &arg1);
    void on_pushButton_7_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_13_clicked();
    void on_C4ComboBox_currentTextChanged(const QString &arg1);
    void on_IndietroPushButton_15_clicked();
};
#endif // MAINWINDOW_H
