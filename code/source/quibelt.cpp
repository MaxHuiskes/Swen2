#include "headers/quibelt.h"
#include "headers/cbelt.h"
#include "cblock.h"
QUIBelt::QUIBelt(QWidget *parent)
    : QWidget(parent)
    , mLabel (this  )
{


}
void QUIBelt::setBelt(cBelt *blt){
    mBelt = blt;
    QString beltinfo ="Conveyor belt number " +
            QString::number(mBelt->beltnr) + '\n' +
            "Block on Conveyor belt: " +
            '\n' + mBelt->block;

    mLabel.setText(beltinfo);
}
void QUIBelt::setButton(cblock *block){
    mBelt->setBlock(block);

    QString beltinfo ="Conveyor belt number " +
            QString::number(mBelt->beltnr) +
            '\n' + "Block on Conveyor belt: " +
            '\n' + mBelt->block;

    mLabel.setText(beltinfo);
}
void QUIBelt::setLabel(cblock *block){
    mBelt->setBlock(block);

    QString beltinfo ="Conveyor belt number " +
            QString::number(mBelt->beltnr) +
            '\n' + "Block on Conveyor belt: " +
            '\n' + mBelt->block;

    mLabel.setText(beltinfo);
}
