#include "remove.h"
#include "ui_remove.h"

Remove::Remove(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Remove)
{
    ui->setupUi(this);
}

Remove::~Remove()
{
    delete ui;
}
