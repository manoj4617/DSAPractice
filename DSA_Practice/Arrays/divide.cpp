#include <iostream>
#include <cstdint>

using namespace std;

/**
 * Function to divide two integers.
 * 
 * @param dividend The number to be divided.
 * @param divisor The number to divide by.
 * @return The result of the division.
 */
int divide(int dividend, int divisor) {
    // Check for the special case where the dividend is the minimum int
    // and the divisor is -1, in which case the result is the maximum int.
    if(dividend == INT_MIN && divisor == -1){
        return INT_MAX; // Return the maximum int.
    }
    
    // Convert the dividend and divisor to absolute values to avoid dealing with
    // negative numbers.
    long long dvd = labs(dividend);
    long long dvs = labs(divisor);
    
    // Initialize the result to 0.
    long long result = 0;
    
    // Determine the sign of the result based on the signs of the dividend and divisor.
    int sign = (dividend > 0) ^ (divisor > 0) == 0 ? 1 : -1;
    
    // Repeatedly subtract the divisor from the dividend until the dividend is less than the divisor.
    while(dvd >= dvs){
        // Start with the divisor and repeatedly double it until it is greater than or equal to the dividend.
        long long temp = dvs;
        long long mul = 1;
        while(temp << 1 <= dvd){
            temp <<= 1; // Double the divisor.
            mul <<= 1; // Double the multiplication factor.
        }
        
        // Subtract the current divisor from the dividend.
        dvd -= temp;
        
        // Add the current multiplication factor to the result.
        result += mul;
    } 
    
    // Return the result, possibly negated if the dividend and divisor had opposite signs.
    return sign*result;
}

int main(){
    int dividend, divisor;
    cin >> dividend >> divisor;
    cout << divide(dividend, divisor) << endl;
    return 0; 
}