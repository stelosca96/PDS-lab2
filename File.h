//
// Created by stefano on 29/04/20.
//

#ifndef LAB02_FILE_H
#define LAB02_FILE_H


#include "Base.h"

class File: public Base {
private:
    uintmax_t size;
public:
    int mType() const;
    uintmax_t getSize() const;
    void ls(int indent) const override;

    File(const std::string &name, uintmax_t size);
};


#endif //LAB02_FILE_H
