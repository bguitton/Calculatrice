#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#define NBTOUCHES 20

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QScriptEngine>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculatrice; }
QT_END_NAMESPACE

class Calculatrice : public QWidget
{
    Q_OBJECT

public:
    Calculatrice(QWidget *parent = nullptr);
    ~Calculatrice();


private:
    Ui::Calculatrice *ui;
    // touches[16];
    QString tableDesSymboles[NBTOUCHES]={"0","1","2","3","4","5","6","7","8","9","c","=","/","*","-","+","(",")"," "," "};
    QPushButton *touches[NBTOUCHES];
    QLineEdit *afficheur;
    QGridLayout *grille;
    QListWidget *historique;
public slots:
    void onQpushButtonClicked();



};
#endif // CALCULATRICE_H
