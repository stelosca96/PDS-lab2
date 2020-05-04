//
// Created by stefano on 29/04/20.
//
#include <iostream>
#include "File.h"

uintmax_t File::getSize() const {
    return this->size;
}

void File::ls(int indent) const {
    std::string indent_str;
    for(int i=0; i<indent; i++)
        indent_str += "\t";
    std::cout<<indent_str<<getName()<<std::endl;
}

File::File(const std::string &name, uintmax_t size) : Base(name), size(size) {}

int File::mType() const {
    return 1;
}
