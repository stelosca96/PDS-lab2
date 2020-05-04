//
// Created by stefano on 29/04/20.
//

#include "Base.h"

std::string Base::getName() const {
    return this->name;
}

Base::Base(const std::string &name) : name(name) {}
