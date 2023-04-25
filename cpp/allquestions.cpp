#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
int len3;

// Question 1
int* intersection(int arr1[], int len1, int arr2[], int len2) {

    int* smaller_arr;
    int smaller_len;
    
    if (len1 <= len2) {
        smaller_arr = arr1;
        smaller_len = len1;
    }
    
    else {
        smaller_arr = arr2;
        smaller_len = len2;
    }

    int* intersection_arr = new int[smaller_len];
    
    int intersection_len = 0;
    
    for (int i = 0; i < smaller_len; i++) {
        int current = smaller_arr[i];
        bool found = false;
        for (int j = 0; j < len1; j++) {
            if (arr1[j] == current) {
                found = true;
                break;
            }
        }
        if (found) {
            for (int j = 0; j < len2; j++) {
                if (arr2[j] == current) {
                    intersection_arr[intersection_len++] = current;
                    break;
                }
            }
        }
    }

    int* result = new int[intersection_len];
    for (int i = 0; i < intersection_len; i++) {
        result[i] = intersection_arr[i];
    }
    delete[] intersection_arr;
    len3 = intersection_len;
    return result;
}


// Question 2
bool isPalindrome(string s) {
    int n = s.length();
    for(int i=0; i<n/2; i++) {
        if(s[i] != s[n-i-1])
            return false;
    }
    return true;
}

string* findPalindromes(string arr[], int n) {
    int count = 0;
    for(int i=0; i<n; i++) {
        if(isPalindrome(arr[i]))
            count++;
    }

    string* result = new string[count];
    int j = 0;
    for(int i=0; i<n; i++) {
        if(isPalindrome(arr[i]))
            result[j++] = arr[i];
    }

    return result;
}

// Question 3
int* sieve_of_eratosthenes(int* arr, int len, int& new_len) {
    bool* is_prime = new bool[arr[len-1] + 1];
    fill_n(is_prime, arr[len-1] + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    
    for (int i = 2; i * i <= arr[len-1]; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= arr[len-1]; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int* new_arr = new int[len];
    new_len = 0;
    for (int i = 0; i < len; i++) {
        if (is_prime[arr[i]]) {
            new_arr[new_len++] = arr[i];
        }
    }

    delete[] is_prime;
    return new_arr;
}


// Question 4
list<string> anagrams(string word, list<string> word_list) {
    list<string> result;
    string sorted_word = word;
    sort(sorted_word.begin(), sorted_word.end());
    for (string w : word_list) {
        string sorted_w = w;
        sort(sorted_w.begin(), sorted_w.end());
        if (sorted_word == sorted_w) {
            result.push_back(word);
            result.push_back(w);
        }
    }
    return result;
}



int main() {

    // Question 1
    int arr1[] = {1, 2, 3, 4, 5};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {3, 4, 5, 6, 7};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    int* result = intersection(arr1, len1, arr2, len2);
    cout << "Intersection: ";
    for (int i = 0; i < len3; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    delete[] result;

    // Question 2
    string myString_list[] = {"racecar", "hello", "madam", "python", "radar"};
    int n = sizeof(myString_list) / sizeof(myString_list[0]);
    string* result1 = findPalindromes(myString_list, n);
    cout << "Palindromes: ";
    for (int i = 0; i < n; i++) {
        cout << result1[i] << " ";
    }
    cout << endl;


    // Question 3
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr) / sizeof(arr[0]);

    int new_len;
    int* new_arr = sieve_of_eratosthenes(arr, len, new_len);

    cout << "Original array: ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "New array with primes: ";
    for (int i = 0; i < new_len; i++) {
        cout << new_arr[i] << " ";
    }
    cout << endl;

    delete[] new_arr;

    // NOT : SON SORU COK COK COK COK COK UZUN OLUCAKTI ONUN YERINE LIST VE ALGPRITHM KULLANDIM ONUN DISINDAKI HICBIR SORUDA IOSTREAM VE STRING DISINDA LIBRARY KULLANMADIM
    // Question 4
    string word = "listen";
    list<string> word_list = {"enlists", "google", "inlets", "banana"};
    list<string> result2 = anagrams(word, word_list);
    for (string w : result2) {
        cout << w << " ";
    }
    cout << endl;


    return 0;
}