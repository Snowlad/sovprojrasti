/********************************************************************************
** Form generated from reading UI file 'edit.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_H
#define UI_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Edit
{
public:

    void setupUi(QDialog *Edit)
    {
        if (Edit->objectName().isEmpty())
            Edit->setObjectName("Edit");
        Edit->resize(400, 300);

        retranslateUi(Edit);

        QMetaObject::connectSlotsByName(Edit);
    } // setupUi

    void retranslateUi(QDialog *Edit)
    {
        Edit->setWindowTitle(QCoreApplication::translate("Edit", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Edit: public Ui_Edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_H
