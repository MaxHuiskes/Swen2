#include "headers/quibelt.h"
#include "headers/cbelt.h"

QUIBelt::QUIBelt(QWidget *parent, cBelt *belt)
    : QWidget(parent)
    , mLabel (this  )
    , mBelt  (belt  )
{

    QString beltinfo ="Conveyor belt number " +
                      QString::number(mBelt->beltnr) + '\n' +
                      "Block on Conveyor belt: " +
                      '\n' + mBelt->block;

    mLabel.setText(beltinfo);
}

void QUIBelt::setButton(QString block){
    mBelt->setBlock(block);

    QString beltinfo ="Conveyor belt number " +
                      QString::number(mBelt->beltnr) +
                      '\n' + "Block on Conveyor belt: " +
                      '\n' + mBelt->block;

    mLabel.setText(beltinfo);
}
