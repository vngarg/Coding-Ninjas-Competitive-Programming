#include<bits/stdc++.h>
using namespace std;

#include<iostream>
#include<map>
#include<utility>
#include<vector>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
    vector<pair<int, int> >pairs_vector;
	
	map<int, bool>m;
	for (int i = 0; i < n; i++)
	{
		m[arr[i]] = true;
	}
	int max_length = 0;
	int start = 0;
	for (int i = 0; i < n; i++)
	{
		int current_length = 1;
		int current_start = 0;
		if (m[arr[i]] = true)
		{
			m[arr[i]] = false;
			
			int element_at_position = arr[i];
			while (m[element_at_position + 1] == true)
			{
				current_length += 1;
				m[element_at_position + 1] = false;
				element_at_position++;
			}
			
			element_at_position = arr[i];
			current_start = element_at_position;
			while (m[element_at_position - 1] == true)
			{
				m[element_at_position - 1] = false;
				current_start--;
				current_length++;
				element_at_position--;
			}
		}
		if (current_length >= max_length)
		{
			max_length = current_length;
			start = current_start;
			pair<int, int>p;
			p.first = start;
			p.second = max_length;
			pairs_vector.push_back(p);
		}
	}
	if (max_length == 1 && start == arr[n - 1])
	{
		vector<int>temp;
		temp.push_back(arr[0]);
		return temp;
	}
	for (int i = 0; i < n; i++)
	{
		int starting_element = arr[i];
		for (int j = 0; j < pairs_vector.size(); j++)
		{
			if (starting_element == pairs_vector[j].first && max_length == pairs_vector[j].second)
			{
				vector<int>temp;
				for (int k = starting_element; k < starting_element + max_length; k++)
				{
					temp.push_back(k);
				}
				return temp;
			}
		}
	}
}

int main() {
    cout<<"Enter Length of Array: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array"<<endl;

    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    vector<int> v;
    vector<int>::iterator it;
    v = longestConsecutiveIncreasingSequence(arr, n);

    for(it=v.begin(); it!=v.end(); ++it)
        cout<<*it<<" ";

    return 0;
}