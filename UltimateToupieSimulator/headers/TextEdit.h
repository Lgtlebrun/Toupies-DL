#include <QTextEdit>
#include "../general/headers/Systeme.h"

#ifndef TEXTEDIT_H
#define TEXTEDIT_H

class TextEdit : public QTextEdit {

    /// Widget imitant une console en format GUI.
    /// Destiné à l'affichage du mode TEXTE de STS.

    Q_OBJECT

// ========================== METHODES ==============================

public:

    TextEdit(QWidget* parent = nullptr) : QTextEdit(parent) {}          // Cstor

    // Surcharge d'opérateurs <<

    TextEdit& operator<<(QString const& str){
        /// Permet d'utiliser TextEdit comme un flux dans un fichier texte avec des QString.

        append(str);
        return *this;
    }

    TextEdit& operator<<(Systeme& s);           // Permet l'affichage personnalisé des caractéristiques d'un Systeme
    TextEdit& operator<<(std::string& s);       // Généralise l'utilisation comme flot vers fichier texte aux string standards


    // Gestion de la fermeture : émet le signal restartStp
    virtual void closeEvent(QCloseEvent *event) override;


// ==== SLOTS ====
signals:

    void restartStp();      // Appelle le slot restart() de ScWidget

};




#endif // TEXTEDIT_H
