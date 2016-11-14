/*
Bitwise Operators
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



#include <iostream>
using namespace std;


// Start of main function
int main() 
{
    // Bitwise operators are operators that perform operations to numbers at the bit level.
    // These can particularly useful when you want to modify or get information from your data in C++.
    {
        // If you are familiar with binary, you'll know that each bit has a value 2^n, with the pattern being 1, 2, 4, 8, 16, 32 and so on.

        // For example the number 200 is 1100 1000 or 128 + 64 + 8
        unsigned int twohundered = 200;
    }
    cin.get();


    {
        // & is the bitwise and operator.
        // and returns true only if both values are true
        // If you aren't familiar with boolean logic, it looks something like this:

        // AND
        //  a & b | a | b |
        //    0   | 0 | 0 |
        //    0   | 0 | 1 |
        //    0   | 1 | 0 |
        //    1   | 1 | 1 |

        // It takes each of the bits of your numbers and "ands" them together
        unsigned int a = 107;      // 0110 1011 =   0 + 64 + 32 +  0 + 8 + 0 + 2 + 1
        unsigned int b = 213;      // 1101 0101 = 128 + 64 +  0 + 16 + 0 + 4 + 0 + 1
                                   // &
        unsigned int c = a & b;    // 0100 0001 =   0 + 64 +  0 +  0 + 0 + 0 + 0 + 1

        cout << "107 & 213 = " << c << endl;



        // Bitwise and is useful when you want to test for a specific bit.

        // Since negative integers have a sign bit as the highest place, we can use this to determine if a number is negative:
        int positive = 5;
        int negative = -5;
        int signbit = INT_MIN;  // Int min is 0 everywhere but the sign bit.

        // If we bitwise and with the sign bit, we should get the signbit exactly, for negative numbers, and 0 for positive numbers
        if ((positive & signbit) == signbit)
            cout << positive << " is negative." << endl;

        if((positive & signbit) == 0)
            cout << positive << " is positive." << endl;


        if ((negative & signbit) == signbit)
            cout << negative << " is negative." << endl;

        if ((negative & signbit) == 0)
            cout << negative << " is positive." << endl;

    }
    cin.get();


    {
        // | is the bitwise or operator.
        // It does an or operation on each of the bits in the input.
        // or returns true if either or both of the values are true.

        // OR
        //  a | b | a | b |
        //    0   | 0 | 0 |
        //    1   | 0 | 1 |
        //    1   | 1 | 0 |
        //    1   | 1 | 1 |

        unsigned int a = 107;       // 0110 1011 =   0 + 64 + 32 +  0 + 8 + 0 + 2 + 1
        unsigned int b = 213;       // 1101 0101 = 128 + 64 +  0 + 16 + 0 + 4 + 0 + 1
                                    // |
        unsigned int c = a | b;     // 1111 1111 = 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1

        cout << "107 | 213 = " << c << endl;

        // Bitwise or is useful when you want to combine bits in a bitfield.
        // A bitfield is a commonly used strategy for storing or passing multiple booleans as part of the same value.
        // You may have a value looking like this:

        unsigned char black = 0;                    // 000
        unsigned char red = 1;                      // 001
        unsigned char green = 2;                    // 010
        unsigned char blue = 4;                     // 100

        // To combine values, you can do something like this:
        unsigned char cyan = green | blue;          // 110
        unsigned char yello = red | green;          // 011
        unsigned char magenta = red | blue;         // 101
        unsigned char white = red | green | blue;   // 111
    }
    cin.get();


    {
        // ^ is the bitwise xor operator, which performs an xor operation on each bit
        // xor returns true if only one of the values are true.

        // XOR
        //  a ^ b | a | b |
        //    0   | 0 | 0 |
        //    1   | 0 | 1 |
        //    1   | 1 | 0 |
        //    0   | 1 | 1 |

        unsigned int a = 107;       // 0110 1011 =   0 + 64 + 32 +  0 + 8 + 0 + 2 + 1
        unsigned int b = 213;       // 1101 0101 = 128 + 64 +  0 + 16 + 0 + 4 + 0 + 1
                                    // ^
        unsigned int c = a ^ b;     // 1011 1110 = 128 +  0 + 32 + 16 + 8 + 4 + 2 + 0

        cout << "107 ^ 213 = " << c << endl;

    }
    cin.get();


    {
        // ~ is the bitwise not operator, which only operates on one value, and reverses all of its bits.

        // NOT
        //  ~a | a |
        //   1 | 0 |
        //   0 | 1 |

        unsigned int a = 107;       // 0110 1011 =   0 + 64 + 32 +  0 + 8 + 0 + 2 + 1
                                    // ~
        unsigned int b = ~a;        // 1001 0100 = 128 +  0 +  0 + 16 + 0 + 4 + 0 + 0

        cout << "~107 = " << b << endl; // This outputs a very large number, because an integer is 4 bytes.
    }
    cin.get();


    {
        // >> is the bitshift right operator.
        // This shifts all of the bits in a number to the right, by the number of bits given by the number on the right.


        unsigned int a = 4;         // 0100
        unsigned int b = a >> 2;    // 0001

        cout << "4 >> 2 = " << b << endl;

        // This will fill any bits on the left with 0's
        // >> 1 is the same thing as dividing by 2.
        unsigned int number = 107;
        while (number > 0)
        {
            cout << number << endl;
            number = number >> 1;
        }
    }
    cin.get();


    {
        // << is the bitshift left operator.
        // This shifts all of the bits in a number to the left, by the number of bits given by the number on the right.


        unsigned int a = 2;         // 0010
        unsigned int b = a << 2;    // 1000

        cout << "2 << 2 = " << b << endl;

        // This will fill bits on the right with 0's
        // << 1 is the same thing as multiplying by 2.
        unsigned int number = 3;
        while (number > 0)
        {
            cout << number << endl;
            number = number << 1;
        }
    }
    cin.get();



    return 0;   // End Program.
}