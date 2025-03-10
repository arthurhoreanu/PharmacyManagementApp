#include "Controller.h"
#include "Medicine.h"

///@param medicine
void Controller::add(Medicine medicine) {
    repo.add(medicine);
}

///@param medicine
void Controller::remove(Medicine& medicine) {
    repo.del(medicine);
}

///@param name
void Controller::getByName(std::string name) {
    std::list<Medicine> repository = repo.getAll();
    if (name == "~"){
        for(Medicine i: repository) {
            i.showProduct();
            cout << "\n";
        }
    }
    for(Medicine i: repository){
        if (i.getName() == name || i.getOrigin() == name){
            i.showProduct();
            cout << "\n";
        }
    }
}

void Controller::sortByExpirationDate() {
    std::list<Medicine> repository = repo.getAll();
    repository.sort(Medicine::compareByExp);
    for (Medicine i: repository){
        i.showProduct();
        cout << "\n";
    }
}

///@param quantity [in] quantity for finding the products that are insufficient
void Controller::showInsufficientProducts(int quantity) {
    std::list<Medicine> repository = repo.getAll();
    for (Medicine i: repository){
        if (i.getQuantity() < quantity){
            i.showProduct();
            cout << "\n";
        }
    }
}

///@param medicine [in] medicine
void Controller::modify(Medicine medicine){
    Medicine newMedicine = medicine;
    std::list<Medicine> listForModify = repo.getAll();
    std::list<Medicine> newListForModify;
    for (Medicine i: listForModify){
        if (i.getName() == medicine.getName() && i.getOrigin() == medicine.getOrigin()){
            newListForModify.push_back(newMedicine);
        } else {
            newListForModify.push_back(i);
        }
    }
    repo.setAll(newListForModify);
}

void Controller::showAll() {
    std::list<Medicine> repository = repo.getAll();
    for (Medicine i: repository){
        i.showProduct();
        cout << "\n";
    }
}

void Controller::showFirstTenItems() {
    std::list<Medicine> repository = repo.getAll();
    int j = 0;
    for (Medicine i: repository){
        i.showProduct();
        cout << "\n";
        j++;
        if (j >= 10){
            break;
        }
    }
}

Medicine* Controller::findByName(const std::string& name) {
    for (Medicine& i : repo.getAll()) {
        if (i.getName() == name || i.getOrigin() == name) {
            return &i;
        }
    }
    return nullptr;
}
