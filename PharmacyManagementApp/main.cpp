#include "UserInterface.h"
#include "Test.h"
int main() {
    Test test;
    test.tests();
    std::cout << "All tests passed!" << std::endl;
    UserInterface console;
    console.menu();
}