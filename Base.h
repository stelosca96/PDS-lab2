//
// Created by stefano on 29/04/20.
//

#ifndef LAB02_BASE_H
#define LAB02_BASE_H

#include <string>

class Base {
private:
    std::string name;
public:
    std::string getName() const;
    virtual int mType() const = 0;
    virtual void ls(int indent) const=0;

    Base(const std::string &name);
};


#endif //LAB02_BASE_H
