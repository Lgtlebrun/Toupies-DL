#include "../headers/TextEdit.h"

TextEdit& TextEdit::operator<<(Systeme& s){
/* Surchage de l'opérateur << permettant un affichage des statistiques dans n'importe quel ostream */
    for (int k(0); k < s.getNbCorps() ; ++k) {

        *this << "==== Toupie " + QString::fromStdString(std::to_string(k+1)) + " :\n";
        *this<< QString::fromStdString(s.getCorps(k)->getType()) ;

        *this << "parametre                :  " + QString::fromStdString(s.getCorps(k)->getParam().to_str()) + "\n";
        *this << "vitesse                  :  " + QString::fromStdString(s.getCorps(k)->getVitesse().to_str()) + "\n";




        *this << "\n";

    }
    return *this ;

}



void TextEdit::closeEvent(QCloseEvent *event)
{

    emit restartStp();

    QWidget::closeEvent(event);
}

