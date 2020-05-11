#include <QTextEdit>
#include "../general/headers/Systeme.h"

#ifndef TEXTEDIT_H
#define TEXTEDIT_H

class TextEdit : public QTextEdit {

    Q_OBJECT

public:

    TextEdit(QWidget* parent = nullptr) : QTextEdit(parent) {}

    TextEdit& operator<<(QString const& str){

        append(str);
        return *this;
    }

    TextEdit& operator<<(Systeme& s);
    TextEdit& operator<<(std::string& s);

    virtual void closeEvent(QCloseEvent *event) override;



signals:

    void restartStp();

};




#endif // TEXTEDIT_H
