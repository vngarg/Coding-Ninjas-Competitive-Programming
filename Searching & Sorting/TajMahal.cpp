/* Problem Statement

Taj Mahal is one of the seven wonders of the world. Aahad loves to travel places and wants to visit Taj Mahal. He visited Agra to view Taj Mahal. There is a ticketing system at Taj Mahal. There are total ‘n’ windows which provide the tickets to get entry into Taj Mahal. There are ‘Ai’ people already present at each window to get the tickets. Each window gives ticket to one person in one minute. Initially, Aahad stands in front of the first window. After each minute, if he didn’t get the ticket, he moves on to the next window to get the ticket. If he is at window 1, he will move to 2. If at 2nd, he will move to 3rd. If he is at last window, he will move to 1st again and so on. Find the window number at which he will get the ticket.

*/

#include <bits/stdc++.h>
using namespace std;

int GetTicket(int *arr, int n) {
    int index = INT_MAX;

    while (index > n) {
        for (int i = 0; i < n; ++i) {
            if (arr[i] <= i && i < index)
                index = i;

            if (arr[i] >= n)
                arr[i] = arr[i] % n;
        }
    }

    return index;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << GetTicket(arr, n) + 1;
    return 0;
}