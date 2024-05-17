/********************************************************************************
** Form generated from reading UI file 'remove.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVE_H
#define UI_REMOVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Remove
{
public:

    void setupUi(QDialog *Remove)
    {
        if (Remove->objectName().isEmpty())
            Remove->setObjectName("Remove");
        Remove->resize(400, 300);

        retranslateUi(Remove);

        QMetaObject::connectSlotsByName(Remove);
    } // setupUi

    void retranslateUi(QDialog *Remove)
    {
        Remove->setWindowTitle(QCoreApplication::translate("Remove", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Remove: public Ui_Remove {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVE_H
