#include "Test.h"
#include <cassert>
#include <iostream>

// Tests for repository
void Test::tests() {
    Repository repo;

    // Test add and retrieve elements
    Medicine m1("Aspenter", "Terapia", "2025", 4, 15);
    repo.add(m1);
    assert(repo.getAll().size() == 1);
    assert(repo.getAll().front().getName() == "Aspenter");

    // Test remove element
    repo.del(m1);
    assert(repo.getAll().size() == 0);

    // Test multiple elements
    Medicine m2("Aspirin", "Bayer", "2024", 15, 16);
    Medicine m3("Biofen", "Biofarm", "2025", 20, 11);
    repo.add(m1);
    repo.add(m2);
    repo.add(m3);
    assert(repo.getAll().size() == 3);

    std::cout << "Repository tests passed!\n";
}