#include "calculatrice.h"
#include "ui_calculatrice.h"

Calculatrice::Calculatrice(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculatrice)
{
    ui->setupUi(this);
    ui->setupUi(this);
    int colonne=0,ligne=0;
    grille = new QGridLayout(this);
    afficheur = new QLineEdit(this);
    afficheur->setReadOnly(true);
    afficheur->setAlignment(Qt::AlignRight);
    historique=new QListWidget(this);
    grille->addWidget(afficheur,ligne,colonne,1,5);//(y,x,rowspan,colspan)
    grille->addWidget(historique,1,4,5,1);//(y,x,rowspan,colspan)
    for(int i=0;i<NBTOUCHES;i++){
        touches[i]= new QPushButton(this);
        touches[i]->setText(tableDesSymboles[i]);
        grille->addWidget(touches[i],i/4+1,i%4);
        connect(touches[i],&QPushButton::clicked,this,&Calculatrice::onQpushButtonClicked);
        touches[i]->setMaximumWidth(80);
        touches[i]->setMinimumHeight(80);
    }

    this->setLayout(grille);
}

Calculatrice::~Calculatrice()
{
    delete ui;
    delete grille;
    delete afficheur;
    delete  historique;

}

void Calculatrice::onQpushButtonClicked()
{
    QPushButton *touche;
    QScriptEngine unCalcul;
    QScriptValue uneValeur;
    touche = qobject_cast<QPushButton*>(sender());
    if(touche->text()!="=" &&touche->text()!="c"){
        afficheur->insert(touche->text());


    }else
    {
        if(touche->text()=="c"){
            afficheur->clear();
        }else{
            historique->addItem(afficheur->text()+"=");
            uneValeur=unCalcul.evaluate(afficheur->text());
            afficheur->setText(uneValeur.toString());
            historique->addItem(uneValeur.toString());

        }

    }
}

