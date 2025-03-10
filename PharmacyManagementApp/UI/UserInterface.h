#include "Controller.h"
#include "Repository.h"

class UserInterface {
    Controller action;
public:
    void menu();
    void showMenu();
    void showCRUDOptions();
    void populateData(Controller &action) const;
    void removeMedicine();
    void addMedicine();
    void updateMedicine();
};