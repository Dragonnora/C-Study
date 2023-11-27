#include <stdio.h>

// Prototypes
struct Fraction reduce_fraction(struct Fraction);
struct Fraction get_fraction(); 
void print_fraction(struct Fraction); 
int gcd(int, int); 


// Structure that represents components of a fraction 
struct Fraction {
    int numerator;
    int denominator;
};

int main() {
    struct Fraction frac;
    
    // Gets fraction
    frac = get_fraction();

    // Prints input fraction
    print_fraction(frac);
    printf(" = ");

    /* Inward then outward. Fraction is reduced, then the reduced fraction is 
       returned to function that prints it */ 
    print_fraction(reduce_fraction(frac));
    
    return 0;
}

// Calculate gcd 
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Reduces fraction
struct Fraction reduce_fraction(struct Fraction frac) {
    
    // get divisor
    int divisor = gcd(frac.numerator, frac.denominator);
    
    // divide components by divisor to reduce fraction
    frac.numerator /= divisor; 
    frac.denominator /= divisor;
    
    return frac;
}

// Gets fraction from user
struct Fraction get_fraction() {
    
    // Creates fraction
    struct Fraction frac;
    printf("Enter numerator: ");
    scanf("%d", &frac.numerator);

    // Get the denominator with verification for non-zero value
    do {
        printf("Enter the denominator (non-zero): ");
        scanf("%d", &frac.denominator);
        
        if (frac.denominator == 0) {
            printf("Error: Denominator cannot be zero. Please try again.\n");
        }
    } while (frac.denominator == 0);

    return frac;
}

// Prints fraction
void print_fraction(struct Fraction frac) {
    printf("%d/%d", frac.numerator, frac.denominator);
}


