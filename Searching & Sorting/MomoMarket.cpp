/* Problem Statement

Shreya loves to eat momos. Her mother gives her money to buy vegetables but she manages to save some money out of it daily. After buying vegetables, she goes to "Momos Market", where there are ‘n’ number of shops of momos. Each of the shops of momos has a rate per momo. She visits the market and starts buying momos (one from each shop) starting from the first shop. She will visit the market for ‘q’ days. You have to tell that how many momos she can buy each day if she starts buying from the first shop daily. She cannot use the remaining money of one day on some other day. But she will save them for other expenses in the future, so, you also need to tell the sum of money left with her at the end of each day.

*/

#include<bits/stdc++.h>
using namespace std;

void CalculateMomos(int* cost, int n, int money) {
    int numberMomo = 0;

    for(int i=0;i<n;++i) {
        if(cost[i] <= money) {
            ++numberMomo;
            money -= cost[i];
        } else {
            break;
        }
    }

    cout<<numberMomo<<" "<<money<<endl;
}

int main() {
    int n, q;
    cin>>n;
    int cost[n];
    for(int i=0;i<n;++i)
        cin>>cost[i];

    cin>>q;
    while(q--) {
        int totalMoney;
        cin>>totalMoney;
        CalculateMomos(cost, n, totalMoney);
    }
    return 0;
}