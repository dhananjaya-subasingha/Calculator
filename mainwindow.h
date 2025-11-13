#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bt1_clicked();

    void on_bt2_clicked();

    void on_bt3_clicked();

    void on_bt4_clicked();

    void on_bt5_clicked();

    void on_bt6_clicked();

    void on_bt7_clicked();

    void on_bt8_clicked();

    void on_bt9_clicked();

    void on_bt10_clicked();

    void on_bt_addition_clicked();

    void on_bt_substraction_clicked();

    void on_bt_multipication_clicked();

    void on_bt_division_clicked();

    void on_btdot_clicked();

    void on_bt_equal_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
