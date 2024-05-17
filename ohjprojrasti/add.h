#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class add;
}

class add : public QDialog
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();

    int getAddID() const;
    void setAddID(int newAddID);
    void addCar2();
    QString getAddBranch() const;
    void setAddBranch(const QString &newAddBranch);

    QString getAddModel() const;
    void setAddModel(const QString &newAddModel);
    void close_window();

signals:
    void back();

private slots:
    void addHandler(QNetworkReply * reply);
    void OKbtn_clicked();

private:
    Ui::add *ui;
    int addID;
    QString addBranch;
    QString addModel;
    QNetworkAccessManager * addManager;
    QNetworkReply * reply;
    QByteArray response_data;
};

#endif // ADD_H
