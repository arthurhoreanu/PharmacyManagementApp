# PharmacyManagementApp

PharmacyManagementApp is a C++ console-based application designed to help manage pharmaceutical products efficiently. It allows users to add, remove, search, and update medicines while keeping track of their stock and expiration dates.

## Features

- **Add Medicines**: Register new medicines with details like name, origin, expiration date, quantity, and price.
- **Remove Medicines**: Delete medicines from the inventory.
- **Update Medicines**: Modify existing medicine information.
- **Search Medicines**: Find medicines by name or origin.
- **Sort by Expiration Date**: Display all medicines sorted by expiration date.
- **Check Low Stock**: Identify medicines with quantities below a specified threshold.

## File Structure

<pre>
📂 Model (Data Models)
    Medicine.h - Defines the Medicine class
    Medicine.cpp - Implements medicine attributes and methods

📂 Repository (Data Storage)
    Repository.h - Defines the Repository class
    Repository.cpp - Handles data operations for storing medicines

📂 Controller (Business Logic)
    Controller.h - Defines the Controller class
    Controller.cpp - Implements medicine management logic

📂 UI (User Interface)
    UserInterface.h - Defines the UI class
    UserInterface.cpp - Implements the console-based interface

📂 Test (Unit Tests)
    Test.h - Defines the test suite
    Test.cpp - Implements unit tests for repository and controller

main.cpp - Entry point of the application
</pre>
