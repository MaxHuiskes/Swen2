#include "headers/quibelt.h"

QUIBelt::QUIBelt(QWidget *parent, cBelt *belt)
    : QWidget(parent)
    , mLabel(this)
{
    beltcount = belt;
    QString beltinfo ="Conveyor belt number " + QString::number(beltcount->beltnr) + '\n' + "Block on Conveyor belt " + QString::number(beltcount->block);

    mLabel.setText(beltinfo);
}
