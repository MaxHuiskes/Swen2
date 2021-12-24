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
    explicit QUIBelt(QWidget *parent);
    void setBelt(cBelt*);
    void setButton(cblock*);
    void setLabel(cblock*);

private:
    QLabel mLabel;
    cBelt  *mBelt;

signals:

};

#endif // QUIBELT_H
