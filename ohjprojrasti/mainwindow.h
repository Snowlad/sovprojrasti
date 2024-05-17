#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class carList{
public:

    QString getBranch() const;
    void setBranch(const QString &newBranch);

    QString getModel() const;
    void setModel(const QString &newModel);

    QString getCar_id() const;
    void setCar_id(int newCar_id);

private:
    QString branch;
    QString model;
    QString car_id;
};

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void fetch_data();
    void show_all();
    QString getCar() const;
    void setCar(const QString &newCar);
    void deletefromdata(QString rcarid, const QModelIndex &index);
private slots:
    void pushAdd_clicked();
    void pushEdit_clicked();
    void pushRemove_clicked();
    void displayCars(QNetworkReply * reply);
    void btnshowall_clicked();
    void addCar(QNetworkReply *reply);
private:
    Ui::MainWindow *ui;
    QString car;
    QNetworkAccessManager * manager;
    QNetworkReply * reply;
    QByteArray data;
    QJsonArray json_array;
    QList < carList > list;
    int tens = 0;


};
#endif // MAINWINDOW_H
