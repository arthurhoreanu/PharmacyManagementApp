#pragma once
#include "Repository.h"
#include "Medicine.h"

class Controller {
private:
    Repository repo;
public:
    void add(Medicine medicine);
    void remove(Medicine& medicine);
    void getByName(std::string name);
    void modify(Medicine medicine);
    void sortByExpirationDate();
    void showInsufficientProducts(int quantity);
    void showAll();
    void showFirstTenItems();
    Medicine* findByName(const std::string& name);
};