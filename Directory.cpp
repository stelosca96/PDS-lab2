//
// Created by stefano on 27/04/20.
//

#include <iostream>
#include <memory>
#include <utility>
#include "Directory.h"
#include "File.h"

std::shared_ptr<Directory> Directory::root;


void Directory::ls(int indent) const {
    std::string indent_str;
    for(int i=0; i<indent; i++)
        indent_str += "\t";
    std::cout<<indent_str<<"[+] "<<getName()<<std::endl;
    for(std::pair<std::string, std::shared_ptr<Base>> element: children){
       element.second->ls(indent+1);
    }
}

std::shared_ptr<Directory> Directory::makeDirectory(std::string name, std::weak_ptr<Directory> parent) {
    std::shared_ptr<Directory> ptr = std::shared_ptr<Directory>(new Directory(name));
    ptr->father = std::move(parent);
    ptr->self = ptr;
    return ptr;
}

std::shared_ptr<Directory> Directory::addDirectory(const std::string& child_name) {
    if(this->getDir(child_name) || child_name==".." || child_name==".")
        return nullptr;
    std::shared_ptr<Directory> dir = Directory::makeDirectory(child_name, this->self);
    children[child_name] = dir;
    return dir;
}

std::shared_ptr<Directory> Directory::getRoot(){
    if(Directory::root == nullptr){
        Directory* dir = new Directory("/");
        std::shared_ptr<Directory> ptr = std::shared_ptr<Directory>(dir);
        ptr->self = ptr;
        ptr->father = ptr;
        Directory::root = ptr;
    }
    return Directory::root;
}

std::shared_ptr<File> Directory::addFile(const std::string &nome, uintmax_t size) {
    if(this->children.count(nome)>0 || nome == ".." || nome == ".")
        return std::shared_ptr<File>();
    std::shared_ptr<File> ptr = std::make_shared<File>(nome, size);
    this->children[nome] = ptr;
    return ptr;
}

std::shared_ptr<Base> Directory::get(const std::string &name) {
    if(name=="..")
        return this->father.lock();
    if(name==".")
        return this->self.lock();
    return this->children.find(name)->second;
}

std::shared_ptr<Directory> Directory::getDir(const std::string &name) {
    return std::dynamic_pointer_cast<Directory>(get(name));
}

std::shared_ptr<File> Directory::getFile(const std::string &name) {
    return std::dynamic_pointer_cast<File>(get(name));}

bool Directory::remove(const std::string &nome) {
    return this->children.erase(nome);
}

int Directory::mType() const {
    return 0;
}

Directory::Directory(const std::string &name) : Base(name) {}

