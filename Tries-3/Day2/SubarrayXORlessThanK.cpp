#include <bits/stdc++.h>
using namespace std;
class Node{
	Node* children[2];
	int cnt[2];
	public:
	Node(){
		for(int i=0;i<2;i++){
			children[i] = NULL;
			cnt[i] = 0;
		} 
	}
	void insert(int num){
        Node* temp =this;
		int b = 0;
        for(int i=31;i>=0;i--){
            b = (num>>i)&1;
            temp->cnt[b]++;
			if(temp->children[b]==NULL){
                temp->children[b] = new Node();
            }
            temp = temp->children[b];
        }
    }
	int subarrLessThanK(int num,int k){
		Node* temp = this;
		int array = 0;
		int bit_k = 0;
		int b = 0;
		for(int i=31;i>=0 && temp!=NULL;i--){
			bit_k = (k>>i)&1;
        	b = (num>>i)&1;
			if(bit_k==1){
				array+=temp->cnt[b];
				temp = temp->children[1-b];
			}else{
				temp=temp->children[b];
			}
		}
		return array;
	}
};
long long numOfSubarrLessThanK(vector<int>& arr,int n,int k){
	Node* root = new Node();
	int array_xor = 0;
	long long array = 0;
	root->insert(0);
	for(int i=0;i<n;i++){
		array_xor ^= arr[i];
		array += root->subarrLessThanK(array_xor,k);
		root->insert(array_xor);
	}
	return array;
}
int main() {
	int t,temp;
	cin >> t;    
	for(int i=0;i<t;i++){
		int n,k;
		vector<int> arr;
		cin >> n >> k;
		for(int i=0;i<n;i++){
			cin >> temp;
			arr.push_back(temp);
		}
		cout << numOfSubarrLessThanK(arr,n,k) << endl;
	}	
	return 0;
}