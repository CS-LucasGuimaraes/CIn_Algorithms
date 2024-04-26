#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

void selectionSort(int* arr, const int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;

        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) min = j;
        }

        swap(arr[i], arr[min]);
        
    }
    
}
