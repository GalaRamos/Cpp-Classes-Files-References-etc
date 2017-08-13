/*
Iterators
-begin() – Returns an iterator pointing to the first element in the vector
-end() – Returns an iterator pointing to the theoretical element that follows
last element in the vector
-rbegin() – Returns a reverse iterator pointing to the last element in the
vector (reverse beginning). It moves from last to first element
-rend() – Returns a reverse iterator pointing to the theoretical element
preceding the first element in the vector (considered as reverse end)
Capacity
-size() – Returns the number of elements in the vector
-max_size() – Returns the maximum number of elements that the vector can hold
-capacity() – Returns the size of the storage space currently allocated to
the vector expressed as number of elements
-resize(size_type g) – Resizes the container so that it contains ‘g’ elements
-empty() – Returns whether the container is empty
Accessing the elements
-reference operator [g] – Returns a reference to the element at position ‘g’
in the vector
-at(g) – Returns a reference to the element at position ‘g’ in the vector
-front() – Returns a reference to the first element in the vector
-back() – Returns a reference to the last element in the vector
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Example Iterators
int main()
{
    vector <int> g1;
    vector <int> :: iterator i;
    vector <int> :: reverse_iterator ir;
    for (int i = 1; i <= 5; i++)
        g1.push_back(i);
    cout << "Output of begin and end\t:\t";
    for (i = g1.begin(); i != g1.end(); ++i)
        cout << *i << '\t';
    cout << endl << endl;
    cout << "Output of rbegin and rend\t:\t";
    for (ir = g1.rbegin(); ir != g1.rend(); ++ir)
        cout << '\t' << *ir;

    return 0;
}
/* Output:
Output of begin and end	:	1	2	3	4	5
Output of rbegin and rend  :	5	4	3	2	1
*/

// Example Capacity
int main()
{
    vector <int> g1;
    for (int i = 1; i <= 5; i++)
        g1.push_back(i);
    cout << "Size : " << g1.size();
    cout << "\nCapacity : " << g1.capacity();
    cout << "\nMax_Size : " << g1.max_size();

    return 0;
}
/* Output:
Size : 5
Capacity : 8
Max_Size : 4611686018427387903
*/

// Example Accessing the elements
int main()
{
    vector <int> g1;

    for (int i = 1; i <= 10; i++)
        g1.push_back(i * 10);
    cout << "Reference operator [g] : g1[2] = " << g1[2];
    cout << endl;
    cout << "at : g1.at(4) = " << g1.at(4);
    cout << endl;
    cout << "front() : g1.front() = " << g1.front();
    cout << endl;
    cout << "back() : g1.back() = " << g1.back();
    cout << endl;

    return 0;
}
/* Output:
Reference operator [g] : g1[2] = 30
at : g1.at(4) = 50
front() : g1.front() = 10
back() : g1.back() = 100
*/
