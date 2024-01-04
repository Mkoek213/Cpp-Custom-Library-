#include <iostream>
#include "Vector.h"
#include "Set.h"  


int main() {
    // Integer Set
    Collections::Set<int> intSet = {1, 2, 3, 4, 5};
    std::cout << "Integer Set:\n";
    intSet.display();
    std::cout << "\nSize: " << intSet.get_size() << "\n";

    // Test find and count for integers
    int valueToFind = 33;
    int* foundValue = intSet.find(valueToFind);
    int countValue = intSet.count(valueToFind);
    std::cout << "Find " << valueToFind << ": " << (foundValue ? *foundValue : -1) << "\n";
    std::cout << "Count " << valueToFind << ": " << countValue << "\n\n";

    // Float Set
    Collections::Set<float> floatSet = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    std::cout << "Float Set:\n";
    floatSet.display();
    std::cout << "\nSize: " << floatSet.get_size() << "\n";

    // Test find and count for floats
    float floatValueToFind = 3.3f;
    float* foundFloatValue = floatSet.find(floatValueToFind);
    int countFloatValue = floatSet.count(floatValueToFind);
    std::cout << "Find " << floatValueToFind << ": " << (foundFloatValue ? *foundFloatValue : -1.0f) << "\n";
    std::cout << "Count " << floatValueToFind << ": " << countFloatValue << "\n\n";

    // String Set
    Collections::Set<std::string> stringSet = {"apple", "banana", "orange", "grape", "kiwi"};
    std::cout << "String Set:\n";
    stringSet.display();
    std::cout << "\nSize: " << stringSet.get_size() << "\n";

    // Test find and count for strings
    std::string stringValueToFind = "orange";
    std::string* foundStringValue = stringSet.find(stringValueToFind);
    int countStringValue = stringSet.count(stringValueToFind);
    std::cout << "Find " << stringValueToFind << ": " << (foundStringValue ? *foundStringValue : "Not found") << "\n";
    std::cout << "Count " << stringValueToFind << ": " << countStringValue << "\n\n";

    // Test erase for all sets
    intSet.erase(2);
    floatSet.erase(2.2f);
    stringSet.erase("banana");

    std::cout << "After Erasing:\n";
    std::cout << "Integer Set:\n";
    intSet.display();
    std::cout << "\nFloat Set:\n";
    floatSet.display();
    std::cout << "\nString Set:\n";
    stringSet.display();

    return 0;
}