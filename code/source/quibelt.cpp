#include "quibelt.h"
#include "cbelt.h"
#include "clift.h"
#include "cblock.h"
#include <QDebug>
QUIBelt::QUIBelt(QWidget *parent, cBelt* belt)
    : QWidget(parent)
    , mLabel (this  )
    , mBelt (belt)
{
}


QUIBelt::~QUIBelt(){}

void QUIBelt::setBelt(cBelt *blt){      // set belt info to mainwindow
    mBelt = blt;
    QString beltinfo ="Conveyor belt number " +
            QString::number(mBelt->getBeltNr()) + '\n' +
            "Block on Conveyor belt: " +
            '\n' + mBelt->block + '\n' ;

    mLabel.setText(beltinfo);
}



void QUIBelt::setLabel(cblock *block){      // set block and change belt info
    if (mBelt->getOccupiedStatus()==0){
        mBelt->setBlock(block);

        QString beltinfo ="Conveyor belt number " +
                QString::number(mBelt->getBeltNr()) +
                '\n' + "Block on Conveyor belt: " +
                '\n' + block->print+ '\n' ;

        mLabel.setText(beltinfo);
    }
}


void QUIBelt::setNoBlock(cblock *block){      // set no block and change belt info
    mBelt->setNoBlock(block);

    QString beltinfo ="Conveyor belt number " +
            QString::number(mBelt->getBeltNr()) +
            '\n' + "Block on Conveyor belt: " +
            '\n' + block->print+ '\n' ;

    mLabel.setText(beltinfo);
}

void QUIBelt::updateLabel(){
    QString beltinfo ="Conveyor belt number " +
            QString::number(mBelt->getBeltNr()) +
            '\n' + "Block on Conveyor belt: " +
            '\n' + mBelt->block+ '\n' +
            "Motor on: " + QString::number(mBelt->getMotorStatus()) ;

    mLabel.setText(beltinfo);
}

