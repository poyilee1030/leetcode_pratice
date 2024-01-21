// basic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "basic_queue.h"
#include "basic_str.h"
#include "basic_unordered_map.h"
#include "basic_unordered_set.h"
#include "basic_vector.h"
#include "basic_check.h"


int main()
{
    long mod1 = 1e9 + 7;
    long mod2 = 1000000007L;
    long mod3 = std::pow(10,9) + 7;
    long mod4 = 10 ^ 9 + 7; // wrong
    //             ↑ 這是 位元運算子的XOR，不是次方

    // n = 0
    int n = rand() % 1;
    cout << n << endl;

    // n = 0~9
    int count = 10;
    for (int i = 0; i < count; i++) {
        int x = rand() % count;
        cout << "n(" << i << ")=" << x;
        if (i < count-1) {
            cout << ", ";
        }
    }
    cout << endl;
    

    //basic_queue();

    //basic_str();

    basic_unordered_map();

    //basic_unordered_set();

    //basic_vector();
    
    //basic_check();
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
