#include <iostream> 
#include <chrono>

using namespace std;  
  
int shell(int a[], int n)  
{  
    for (int gap = n/2; gap > 0; gap /= 2)  
    {  
        for (int i = gap; i < n; i += 1)  

        {   
            
            int temp = a[i];  
            int j;        
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)  
                a[j] = a[j - gap];  
              
             
            a[j] = temp;  
        }  
    }  
    return 0;  
}  
void printArr(int a[], int n)  //function to print all the element
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout<<a[i]<<"  ";  
}      
int main()  
{  
    int a[] = { 7,5,1,9,3,12,55 };  
    int n = sizeof(a) / sizeof(a[0]);  
    cout<<"Before sorting  - \n";  
    printArr(a, n);
    auto startTime = chrono::high_resolution_clock::now();
    shell(a, n);
    auto endTime = chrono::high_resolution_clock::now();

    cout<<"\nAfter applying shell sort- \n"; 
    printArr(a, n);  


// Calculate execution time in seconds
    chrono::duration<double> executionTime = endTime - startTime;
    cout << "\nExecution Time in seconds: " << executionTime.count() << endl;

    return 0;  
}  
