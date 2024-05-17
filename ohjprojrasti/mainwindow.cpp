#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItem>
#include "add.h"
#include <QModelIndex>
#include <QVariant>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushAdd, &QPushButton::clicked, this, &MainWindow::pushAdd_clicked);
    connect(ui->pushEdit, &QPushButton::clicked, this, &MainWindow::pushEdit_clicked);
    connect(ui->pushRemove, &QPushButton::clicked, this, &MainWindow::pushRemove_clicked);
    connect(ui->btnshowAll, &QPushButton::clicked, this, &MainWindow::btnshowall_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
}

void MainWindow::fetch_data()
{
    qDebug()<<"fetch_datassa";
    QString site_url="http://localhost:3000/car";
    QNetworkRequest request(site_url);
    manager = new QNetworkAccessManager(this);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::displayCars);
    reply = manager->get(request);
}

void MainWindow::displayCars(QNetworkReply *reply)
{
    if (reply->error()!= QNetworkReply::NoError){
        qDebug()<<"error???";
        return;
    }
    else{
        data=reply->readAll();
        qDebug()<<data;
        QJsonDocument Jsondoc = QJsonDocument::fromJson(data);
        if(Jsondoc.isArray()){
            QJsonArray arraytaijoku = Jsondoc.array();
            list.clear();
            foreach(const QJsonValue &value, arraytaijoku){
                QJsonObject obj= value.toObject();
                carList item;
                item.setCar_id(obj["id_car"].toInt());
                item.setBranch(obj["branch"].toString());
                item.setModel(obj["model"].toString());
                list.append(item);
            }
        }
        btnshowall_clicked();
        this->show();
        disconnect(manager,&QNetworkAccessManager::finished,this,&MainWindow::displayCars);
        reply->deleteLater();
    }
}

void MainWindow::btnshowall_clicked()
{
    QStandardItemModel * model=new QStandardItemModel(20,3);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("car_id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("branch"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("model"));
    int start = tens * 20;
    model->setRowCount(start);
    int rowstoshow = std::min<int>(list.size()-start,20);
    for (int row = 0; row < rowstoshow; ++row){
        QStandardItem * id = new QStandardItem((list[start+row].getCar_id()));
        model->setItem(row,0,id);
        QStandardItem * branch = new QStandardItem((list[start+row].getBranch()));
        model->setItem(row,1,branch);
        QStandardItem * model_ = new QStandardItem((list[start+row].getModel()));
        model->setItem(row,2,model_);
    }
    ui->tableView->setModel(model);
    this->fetch_data();
    this->show();

}

void MainWindow::show_all()
{

}

QString MainWindow::getCar() const
{


    return car;
}

void MainWindow::deletefromdata(QString rcarid, const QModelIndex &index)
{
    QJsonObject jsonObj;
    QString site_url = "http://localhost:3000/car/" + rcarid;
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    QNetworkAccessManager * deletemanager = new QNetworkAccessManager(this);
    connect(deletemanager,&QNetworkAccessManager::finished,this,&MainWindow::displayCars);
    ui->tableView->model()->removeRow(index.row());
    reply->deleteLater();
    deletemanager->post(request,QJsonDocument(jsonObj).toJson());
}

void MainWindow::addCar(QNetworkReply *reply)
{

}

void MainWindow::pushAdd_clicked()
{


    add * addWindow = new add(this);
    addWindow->addCar2();
    //connect(addWindow, SIGNAL(back()),this,SLOT(displayCars(QNetworkReply*)));
    addWindow->show();


}
void MainWindow::pushEdit_clicked()
{

}

void MainWindow::pushRemove_clicked()
{
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    QVariant value = index.sibling(index.row(),index.column()).data();
    QString selected_value=value.toString();


    ui->labelResult->setText("Valittu "+selected_value);
    int id_column = 0;
    QVariant id_value = index.sibling(index.row(),index.column()).data();
    QString carID = id_value.toString();
    deletefromdata(carID, index);

}



QString carList::getBranch() const
{
    return branch;
}

void carList::setBranch(const QString &newBranch)
{
    branch = newBranch;
}

QString carList::getModel() const
{
    return model;
}

void carList::setModel(const QString &newModel)
{
    model = newModel;
}

QString carList::getCar_id() const
{

    return car_id;
}

void carList::setCar_id(int newCar_id)
{
    car_id = QString::number( newCar_id);
}
