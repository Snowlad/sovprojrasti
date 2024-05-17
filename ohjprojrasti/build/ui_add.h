/********************************************************************************
** Form generated from reading UI file 'add.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_H
#define UI_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_add
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *Branch_line;
    QLineEdit *Model_line;
    QPushButton *OKbtn;

    void setupUi(QDialog *add)
    {
        if (add->objectName().isEmpty())
            add->setObjectName("add");
        add->resize(483, 378);
        label = new QLabel(add);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 10, 81, 16));
        label_2 = new QLabel(add);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 100, 91, 16));
        label_3 = new QLabel(add);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(150, 200, 111, 16));
        Branch_line = new QLineEdit(add);
        Branch_line->setObjectName("Branch_line");
        Branch_line->setGeometry(QRect(100, 130, 113, 24));
        Model_line = new QLineEdit(add);
        Model_line->setObjectName("Model_line");
        Model_line->setGeometry(QRect(90, 280, 113, 24));
        OKbtn = new QPushButton(add);
        OKbtn->setObjectName("OKbtn");
        OKbtn->setGeometry(QRect(190, 330, 80, 24));

        retranslateUi(add);

        QMetaObject::connectSlotsByName(add);
    } // setupUi

    void retranslateUi(QDialog *add)
    {
        add->setWindowTitle(QCoreApplication::translate("add", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("add", "Add ID", nullptr));
        label_2->setText(QCoreApplication::translate("add", "Add Branch", nullptr));
        label_3->setText(QCoreApplication::translate("add", "Add Model", nullptr));
        OKbtn->setText(QCoreApplication::translate("add", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add: public Ui_add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
