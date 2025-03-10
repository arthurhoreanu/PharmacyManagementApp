#include "UserInterface.h"
#include <string>

//Shows menu for CRUD options
void UserInterface::showCRUDOptions() {
    cout << "Choose an option:\n"
            "1. ADD a product\n"
            "2. REMOVE a product\n"
            "3. MODIFY a product\n"
            "4. See ALL products\n";
}

//Shows start menu
void UserInterface::showMenu() {
    cout << "Choose an option:\n"
            "1. ADD, REMOVE or MODIFY a product\n"
            "2. Search for a product\n"
            "3. Look for current products with smaller quantity than needed\n"
            "4. See current products sorted by their expiration date\n";
}

// Function that deals with the behavior of the app regarding the choice
void UserInterface::menu() {
    populateData(action);

    int choice = 0;
    while (choice != 9) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int choice2 = 0;
                while (choice2 != 9) {
                    showCRUDOptions();
                    cout << "Enter your choice: ";
                    cin >> choice2;

                    switch (choice2) {
                        case 1:
                            addMedicine();
                            break;
                        case 2:
                            removeMedicine();
                            break;
                        case 3:
                            updateMedicine();
                            break;
                        case 4:
                            action.showAll();
                            break;
                        case 9:
                            cout << "Returning to main menu...\n";
                            break;
                        default:
                            cout << "Invalid choice. Try again.\n";
                    }
                }
                break;
            }
            case 2: {
                string name;
                cout << "Enter product name: ";
                cin >> name;
                action.getByName(name);
                break;
            }
            case 3: {
                int quantity;
                cout << "Enter the quantity threshold: ";
                cin >> quantity;
                action.showInsufficientProducts(quantity);
                break;
            }
            case 4:
                action.sortByExpirationDate();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

void UserInterface::addMedicine() {
    string name, origin, expDate;
    int quantity, price;
    cout << "Enter medicine name: ";
    cin >> name;
    cout << "Enter medicine origin: ";
    cin >> origin;
    cout << "Enter expiration date: ";
    cin >> expDate;
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter price: ";
    cin >> price;
    Medicine m(name, origin, expDate, quantity, price);
    action.add(m);
}

void UserInterface::removeMedicine() {
    std::string name;
    std::cout << "Enter medicine name to remove: ";
    std::cin >> name;
    Medicine* foundMedicine = action.findByName(name);
    if (foundMedicine) {
        action.remove(*foundMedicine);
        std::cout << "Medicine removed successfully.\n";
    } else {
        std::cout << "Medicine not found.\n";
    }
}

void UserInterface::updateMedicine() {
    string name, origin, expDate;
    int quantity, price;
    cout << "Enter medicine name: ";
    cin >> name;
    cout << "Enter new origin: ";
    cin >> origin;
    cout << "Enter new expiration date: ";
    cin >> expDate;
    cout << "Enter new quantity: ";
    cin >> quantity;
    cout << "Enter new price: ";
    cin >> price;
    Medicine m(name, origin, expDate, quantity, price);
    action.modify(m);
}

void UserInterface::populateData(Controller &action) const {
    Medicine m1 = Medicine("Aspenter", "Terapia", "2025", 4, 15);
    Medicine m2 = Medicine("Aspirin", "Bayer", "2024", 15, 16);
    Medicine m3 = Medicine("Biofen", "Biofarm", "2025", 20, 11);
    action.add(m1);
    action.add(m2);
    action.add(m3);
    action.showFirstTenItems();
}
