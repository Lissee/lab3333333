#include <iostream>
#include "Methods.h"

#include <vector>

using namespace std;

// Упорядоченное множество, односвязный список, int


// Тест с решетом Эратосфена
void sieveEratosthenes(int n) {
    Set s;

    for (int i = 2; i < n; i++) {
        s = s+i;
    }
    int p = 2;

    while(p != n) {
        for (int i = p + 1; i < n; ++i) {
            if (i % p == 0)
                s = s - i;
        }
        ++p;
    }
    cout << s;

}

int main() {

    Set s;
   s= s+1;
    int n=5;
    for (int i = 2; i < n; i++) {
        s = i+s;
    }

    Set p;

    n= 20;
    for (int i = 2; i < n; i++) {
        p = i+p;
    }
    Set z;
    z = z + 89;
    cout << z;
    cout << p;
    cout << s;
    cout << s*p;
    cout << s-p;
    cout << s + z + p;
    cout << 56 * s;
    sieveEratosthenes(100);

    return 0;
}
