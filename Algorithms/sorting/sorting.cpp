
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define lld long double
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define bloop(i,a,b) for(int i=a; i>=b; i--)
#define tc(t) int t; cin>>t; while(t--)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define vpi vector<pi>
#define all(a) a.begin(),a.end()
#define rall(a) a.end(),a.begin()

#define py cout<<"YES\n";
#define pn cout<<"NO\n";
#define PI 3.141592653589793238
#define mod (int) 1000000007
#define infinity (int) (1e18)
#define modul (int) 1e9+7

// *********************************Swaptwonumber**************************

void swapnumber(int *ap , int *bp){
	int temp=*ap;
	*ap=*bp;
	*bp=temp;	
}

// *******************************printarray*************************************

void printarray(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}



// *****************************selectionsort**************************************************

// Time COmplexity - o(n^2)


// The outer loop iterates through each element in the array, from index i=0 to index i=n-2. During each iteration of the outer loop, we assume that the first i elements of the array are already sorted, and we find the smallest element in the remaining unsorted part of the array.

// The inner loop starts at index j=i+1 and iterates through the remaining unsorted part of the array, from index j=i+1 to index j=n-1. During each iteration of the inner loop, we compare the current element at index j with the current minimum element found so far, which is stored in the variable minIndex.

// If the current element is smaller than the current minimum element, we update minIndex to point to the index of the new smallest element. At the end of the inner loop, minIndex will contain the index of the smallest element in the unsorted part of the array.

// Finally, we swap the smallest element with the first unsorted element (which is at index i). This puts the smallest element in its correct position in the sorted array, and ensures that the first i+1 elements of the array are now sorted.

// We repeat these steps for each element in the array, until the entire array is sorted.


// **************************************************************************************************


void selectionsort(int a[],int n){
	int min_index;
	for(int i=0;i<n-1;i++){
		min_index=i;
		for(int j=i+1;j<n;j++){

			if(a[j]<a[min_index])min_index=j;
		}
		swapnumber(&a[min_index],&a[i]);
	}
}


// **************************************************************************************************


// ****************************bubblesort************************************

// TIME COMPLEXITY - O(n^2)

// The outer loop runs from i = 0 to i = n-2 (inclusive), because the last element is already in its correct position after the n-1th iteration. The i variable keeps track of how many elements have been sorted from the end of the array.

// The inner loop runs from j = 0 to j = n-i-2 (inclusive), because the last i elements have already been sorted and do not need to be compared. The j variable iterates through the unsorted portion of the array, comparing adjacent elements and swapping them if they are in the wrong order.


// **************************************************************************************************

void bubblesort(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]) swapnumber(&a[j],&a[j+1]);
		}
	}
}



// **************************************************************************************************




// ************************************* insertionsort*******************

// TIME COMPLEXITY - O(n^2)

// Insertion sort is a simple sorting algorithm that builds the final sorted array or list one item at a time. It is an efficient algorithm for sorting small to medium-sized lists, especially when the list is almost sorted.

// The basic idea behind insertion sort is to iterate through the list and for each element, insert it into its correct position in the sorted sub-list that precedes it. The algorithm starts by assuming that the first element in the list is already sorted, and then iterates through the remaining elements, comparing each one to the elements in the sorted sub-list and inserting it into its correct position.

// Here are the steps to perform an insertion sort on a list of n elements:

// Assume the first element of the list is already sorted.
// For i = 1 to n-1, iterate through the remaining unsorted elements in the list.
// Compare the ith element to the elements in the sorted sub-list, moving from right to left.
// If the current element is smaller than the element being compared, shift the larger element one position to the right.
// Repeat step 4 until the correct position is found for the current element.
// Insert the current element into its correct position in the sorted sub-list.
// Continue iterating through the remaining unsorted elements until the entire list is sorted.
// Here is an example of how insertion sort works on the list [5, 2, 4, 6, 1, 3]:


// **************************************************************************************************

void insertionsort(int a[],int n){
	for(int i=1;i<n;i++){
		int temp=a[i];
		int j=i-1;
		while(j>=0 and a[j]>temp){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}


// **************************************************************************************************

// ****************************************MergeSort************************************************


// TIme Complexity - O(nLog(n))


void merge(int a[],int l,int m,int r){
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for(int i=0;i<n1;i++){
		L[i]=a[l+i];
	}
	for(int j=0;j<n2;j++){
		R[j]=a[m+1+j];
	}
	    int i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}


void mergesort(int a[],int l,int r){
	if(l<r){
		int m=l+(r-l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r); 
	}
}
// **************************************************************************************************
// **************************************************************************************************


	






int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	mergesort(a,0,n-1);
	printarray(a,n);

}
