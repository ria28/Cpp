// https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int compare_(string s1, string s2)
{
    string s1s2 = s1.append(s2);
    string s2s1 = s2.append(s1);

   return s1s2.compare(s2s1)>0?1:0;
}

void printLargest(vector<string> arr) 
{ 
    // Sort the numbers using library sort function. The function uses 
    // our comparison function myCompare() to compare two strings. 
    // See http://www.cplusplus.com/reference/algorithm/sort/ for details 
    sort(arr.begin(), arr.end(), compare_); 
  
    for (int i=0; i < arr.size() ; i++ ) 
        cout << arr[i]; 
} 


int main()
{
    vector<string> arr; 
  
    //output should be 6054854654 
    arr.push_back("54"); 
    arr.push_back("546"); 
    arr.push_back("548"); 
    arr.push_back("60"); 
    printLargest(arr); 
  
   return 0; 
}