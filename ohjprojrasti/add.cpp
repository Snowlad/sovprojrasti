#include "add.h"
#include "ui_add.h"

add::add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
    connect(ui->OKbtn,&QPushButton::clicked,this,&add::OKbtn_clicked);
}

add::~add()
{
    delete ui;
}

void add::addCar2()
{
    QJsonObject jsonObj;

    QString Branch = ui->Branch_line->text();
    QString Model = ui->Model_line->text();

    jsonObj.insert("branch",Branch);
    jsonObj.insert("model",Model);

    QString site_url="http://localhost:3000/car";
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


    addManager = new QNetworkAccessManager(this);
    connect(addManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(addHandler(QNetworkReply*)));

    reply = addManager->post(request, QJsonDocument(jsonObj).toJson());

    qDebug()<<response_data;

}

void add::addHandler(QNetworkReply *reply)
{
     response_data =reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    addManager->deleteLater();
}

void add::OKbtn_clicked()
{

    addCar2();


    this->close();
    delete this;
}

int add::getAddID() const
{
    return addID;
}

void add::setAddID(int newAddID)
{
    addID = newAddID;
}



QString add::getAddBranch() const
{
    return addBranch;
}

void add::setAddBranch(const QString &newAddBranch)
{
    addBranch = newAddBranch;
}

QString add::getAddModel() const
{
    return addModel;
}

void add::setAddModel(const QString &newAddModel)
{
    addModel = newAddModel;
}

void add::close_window()
{

}


