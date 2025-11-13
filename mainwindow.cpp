#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bt1_clicked()
{
    ui->display_calculation->insertPlainText("1");
}

void MainWindow::on_bt2_clicked()
{
    ui->display_calculation->insertPlainText("2");
}

void MainWindow::on_bt3_clicked()
{
    ui->display_calculation->insertPlainText("3");
}

void MainWindow::on_bt4_clicked()
{
    ui->display_calculation->insertPlainText("4");
}

void MainWindow::on_bt5_clicked()
{
    ui->display_calculation->insertPlainText("5");
}

void MainWindow::on_bt6_clicked()
{
    ui->display_calculation->insertPlainText("6");
}

void MainWindow::on_bt7_clicked()
{
    ui->display_calculation->insertPlainText("7");
}

void MainWindow::on_bt8_clicked()
{
    ui->display_calculation->insertPlainText("8");
}

void MainWindow::on_bt9_clicked()
{
    ui->display_calculation->insertPlainText("9");
}

void MainWindow::on_bt10_clicked()
{
    ui->display_calculation->insertPlainText("0");
}

void MainWindow::on_bt_addition_clicked()
{
    ui->display_calculation->insertPlainText("+");
}

void MainWindow::on_bt_substraction_clicked()
{
    ui->display_calculation->insertPlainText("-");
}


void MainWindow::on_bt_multipication_clicked()
{
    ui->display_calculation->insertPlainText("*");
}


void MainWindow::on_bt_division_clicked()
{
    ui->display_calculation->insertPlainText("/");
}


void MainWindow::on_btdot_clicked()
{
    ui->display_calculation->insertPlainText(".");
}


void MainWindow::on_bt_equal_clicked()
{
    QString expr = ui->display_calculation->toPlainText();
    QVector<QString> tokens;

    QString number = "";
    for (int i = 0; i < expr.size(); ++i) {
        QChar c = expr[i];
        if (c.isDigit() || c == '.') {
            number += c;  // build multi-digit number
        } else {  // operator
            if (!number.isEmpty()) {
                tokens.append(number);
                number = "";
            }
            tokens.append(QString(c));
        }
    }
    if (!number.isEmpty()) tokens.append(number);

    // Step 1: Handle * and /
    for (int i = 0; i < tokens.size(); ++i) {
        if (tokens[i] == "*" || tokens[i] == "/") {
            double a = tokens[i-1].toDouble();
            double b = tokens[i+1].toDouble();
            double result = (tokens[i] == "*") ? a*b : a/b;
            tokens[i-1] = QString::number(result);
            tokens.remove(i); // remove operator
            tokens.remove(i); // remove second operand
            i--;
        }
    }

    // Step 2: Handle + and -
    double answer = tokens[0].toDouble();
    for (int i = 1; i < tokens.size(); i += 2) {
        QString op = tokens[i];
        double val = tokens[i+1].toDouble();
        if (op == "+") answer += val;
        else if (op == "-") answer -= val;
    }

    ui->display_calculation->insertPlainText(QString::number(answer));


}

