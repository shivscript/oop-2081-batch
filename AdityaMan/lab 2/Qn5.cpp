#include <iostream>
using namespace std;
int& getElement(int arr[], int index) {
return arr[index];
}
int main() {
int n;
cout<<"Enter the numbers of elements "<<endl;
cin>>n;
int numbers[n];
cout<<"Enter "<<n<<" numbers"<<endl;
for(int i=0;i<n;i++) {
    cout<<"Number "<<i+1 <<": ";
    cin>>numbers[i];
}
int a,b;
cout<<" MODIFICATION"<<endl;
cout<<"Enter the position [1-"<<n<<"] : ";
cin>>a;
cout<<"Value: ";
cin>>b;
cout << "Original value at index "<<a<<": " << numbers[a-1] << endl;
getElement(numbers, a-1) = b;
cout << "Modified value at index "<<a<<": " << numbers[a-1] << endl;
return 0;
}
