#pragma once

#ifndef TOUPIES_DL_CLONABLE_H
#define TOUPIES_DL_CLONABLE_H


class Clonable {

public:

    virtual Clonable* clone() const = 0;                // Renvoie un pointeur sur une copie polymorphique de l'objet


};

#endif //TOUPIES_DL_CLONABLE_H
