#pragma once

#include <iostream>

using namespace std;

void strings()
{
    string d = "decimal";
    string m = "medical";

    int i, H[26] = { 0 };
    for (i = 0; d[i] != NULL; i++) {
        H[d[i] - 97] += 1;
    }

    for (i = 0; m[i] != 0; i++) {
        H[m[i] - 97] -= 1;
        if (H[m[i] - 97] == -1) {
            cout << "Not an anagram";
            break;
        }
    } if (m[i] == NULL) {
        cout << "This is an anagram";
    }
}


void Perm(char s[], int k)
{

    static int A[10] = { 0 };
    static char Res[10];
    int i;


    if (s[k] == 0)
    {
        Res[k] = 0;
        cout << Res << endl;
    }
    else
    {
        for (i = 0; s[i] != NULL; i++)
        {
            if (A[i] == 0)
            {
                Res[k] = s[i];
                A[i] = 1;
                Perm(s, k + 1);
                A[i] = 0;

            }
        }
    }
}
