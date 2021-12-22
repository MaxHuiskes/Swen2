#ifndef QUIBELT_H
#define QUIBELT_H

#include <QWidget>
#include <QLabel>
#include "cbelt.h"

class QUIBelt : public QWidget
{
    Q_OBJECT
public:
    explicit QUIBelt(QWidget *parent = nullptr, cBelt *belt = nullptr);

private:
    QLabel mLabel;
    cBelt *beltcount;

signals:

};

#endif // QUIBELT_H
