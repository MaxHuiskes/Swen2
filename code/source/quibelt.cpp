#include "headers/quibelt.h"
#include "headers/cbelt.h"

QUIBelt::QUIBelt(QWidget *parent, cBelt *belt)
    : QWidget(parent)
    , mLabel (this  )
    , mBelt  (belt  )
{

    QString beltinfo ="Conveyor belt number " +
            QString::number(mBelt->beltnr) + '\n' +
            "Block on Conveyor belt " +
            QString::number(mBelt->block);

    mLabel.setText(beltinfo);
}
