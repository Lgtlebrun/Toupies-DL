#pragma once

#ifndef TOUPIES_DL_CLONABLE_H
#define TOUPIES_DL_CLONABLE_H


class Clonable {

public:

    virtual Clonable* clone() =0;


};

#endif //TOUPIES_DL_CLONABLE_H
