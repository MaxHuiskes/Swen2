#ifndef QUIBELT_H
#define QUIBELT_H

#include <QWidget>
#include <QLabel>

class cBelt;
class cblock;

class QUIBelt : public QWidget
{
    Q_OBJECT
public:
    QUIBelt(QWidget *parent, cBelt*);
    void setBelt(cBelt*);
    void setLabel(cblock*);
    void setNoBlock(cblock*);

private:
    QLabel mLabel;
    cBelt  *mBelt;
public slots:
    void updateLabel(int);

signals:
    bool motorStatus();

};

#endif // QUIBELT_H
