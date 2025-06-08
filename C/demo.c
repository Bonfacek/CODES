#include <stdio.h>

// ---------------------- USER-DEFINED DATA TYPES ----------------------

// Structure
struct Person {
    char name[50];
    int age;
};

// Enumeration
enum Day { MON, TUE, WED };

// Typedef
typedef int Marks;

// ---------------------- VOID FUNCTION ----------------------
void greet() {
    printf("\n[VOID FUNCTION] Hello! This is a void function.\n");
}

// Void pointer function
void printInt(void *ptr) {
    printf("[VOID POINTER] Value: %d\n", *(int *)ptr);
}

// ---------------------- DERIVED FUNCTION ----------------------
int sum(int a, int b) {
    return a + b;
}

// ---------------------- MAIN FUNCTION ----------------------
int main() {

    printf("========== FUNDAMENTAL DATA TYPES ==========\n");
    int age = 25;
    float pi = 3.14f;
    double largePi = 3.1415926535;
    char grade = 'A';

    printf("Integer: %d\n", age);
    printf("Float: %.2f\n", pi);
    printf("Double: %.10lf\n", largePi);
    printf("Character: %c\n", grade);

    printf("\n========== USER-DEFINED DATA TYPES ==========\n");
    struct Person p1 = {"Alice", 30};
    enum Day today = TUE;
    Marks math = 88;

    printf("Struct -> Name: %s, Age: %d\n", p1.name, p1.age);
    printf("Enum -> Today is: %d\n", today);  // 0 = MON, 1 = TUE, etc.
    printf("Typedef (Marks) -> Score: %d\n", math);

    printf("\n========== DERIVED DATA TYPES ==========\n");
    int numbers[3] = {10, 20, 30};    // Array
    int *ptr = numbers;              // Pointer
    int result = sum(numbers[0], numbers[1]); // Function call

    printf("Array -> First Element: %d\n", numbers[0]);
    printf("Pointer -> Value at ptr: %d\n", *ptr);
    printf("Function -> Sum of first two elements: %d\n", result);

    printf("\n========== VOID (EMPTY) DATA TYPE ==========\n");
    greet(); // Void function call

    int num = 42;
    void *vptr = &num;
    printInt(vptr); // Void pointer demonstration

    return 0;
}
