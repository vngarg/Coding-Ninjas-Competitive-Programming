#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

vector<int>* getSieve() {
    bool isPrimes[MAX];

    for(int i=0;i<MAX;++i)
        isPrimes[i] = true;

    for(int i=2;i*i<MAX;++i) {
        if(isPrimes[i]) {
            for(int j=i*i;j<MAX;j+=i)
                isPrimes[j] = false;
        }
    }

    vector<int>* primes = new vector<int>();
    primes->push_back(2);
    for(int i=3;i<MAX;++i)
        if(isPrimes[i])
            primes->push_back(i);

    return primes;
}

void GetPrimes(long long l, long long r, vector<int>* &primes) {
    bool isPrime[r-l+1];

    for(int i=0;i<=r-l;++i)
        isPrime[i] = true;

    for(int i=0;primes->at(i)*(long long)primes->at(i) <= r;++i) {
        int currPrime = primes->at(i);
        long long base = (l/(currPrime))*(currPrime);
        
        if(base < l) 
            base = base + currPrime;

        for(long long j=base;j<=r;j+=currPrime)
            isPrime[j-l] = false;

        if(base == currPrime)
            isPrime[base - l] = true;
    }

    for(int i=0;i<=r-l;++i)
        if(isPrime[i])
            cout<< i+l <<endl;
}

int main() {
    vector<int>* primes = getSieve();
    int t;
    cin>>t;
    while(t--) {
        long long l, r;
        cin>>l>>r;
        GetPrimes(l, r, primes);
    }
    return 0;
}