#pragma once
#include <iostream>
#include <list>
#include "Medicine.h"

class Repository {
private:
    std::list<Medicine> container;
public:
    void add(Medicine medicine);
    void del(const Medicine& medicine);
    std::list<Medicine>& getAll();
    void setAll(std::list<Medicine> list);
};