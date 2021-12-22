#ifndef QUIBELT_H
#define QUIBELT_H

#include <QWidget>
#include <QLabel>


class cBelt;


class QUIBelt : public QWidget
{
    Q_OBJECT
public:
    explicit QUIBelt(QWidget *parent, cBelt *belt);

private:
    QLabel mLabel;
    cBelt *mBelt;

signals:

};

#endif // QUIBELT_H
