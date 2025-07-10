#include <iostream>
#include <vector> 
using namespace std;

vector <int> reverse(vector <int> &v) {
	int s = 0;
	int e = v.size()-1;

	while(s<=e) {
		swap(v[s++], v[e--]);
	}
	return v;
}


vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int i = n-1;
	int j = m-1;
	vector <int> ans;
	int carry = 0;

	while(i>=0 && j>=0) {
		int val1 = a[i];
		int val2 = b[j];

		int sum = val1 + val2 + carry;

		carry = sum / 10;
		sum = sum % 10;
		i--;
		j--;

		ans.push_back(sum);
	}

	// first case = first array is greater than the second one 
	while(i>=0) {
		int sum = a[i] + carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		i--;
	}

	// second case
	while(j>=0) {
		int sum = b[j] + carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		j--;
	}


	while(carry != 0) {
		int sum = carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
	}
	// print(ans);
	return reverse(ans);
}


void input_array(vector<int> &arr, int n) {
	for (int i=0; i<n ; i++) {
		cin >> arr[i];
	}
}


int main() {

	
	int n;
	cout << "Enter the size of the first array : ";
	cin >> n;
    vector <int> arr1(n);

	input_array(arr1, n);

	
	
    int m;
	cout << endl << "Enter the size of the second array : ";
	cin >> m;
    vector <int> arr2(m);

	input_array(arr2, m);



	vector<int> result = findArraySum(arr1, n, arr2, m);

	for (int elem : result) {
		cout << elem;
	}
    
    return 0;
}