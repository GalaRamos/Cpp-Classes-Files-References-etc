/*
Stacks are a type of container adaptors with LIFO(Last In First Out) type of
working, where a new element is added at one end and (top) an element is removed
from that end only.

  empty() – Returns whether the stack is empty
  size() – Returns the size of the stack
  top() – Returns a reference to the top most element of the stack
  push(g) – Adds the element ‘g’ at the top of the stack
  pop() – Deletes the top most element of the stack
*/

#include <iostream>
#include <stack>

using namespace std;

void showstack(stack <int> gq)
{
    stack <int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}

int main ()
{
    stack <int> gquiz;
    gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    gquiz.push(5);
    gquiz.push(1);

    cout << "The stack gquiz is : ";
    showstack(gquiz);

    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.top() : " << gquiz.top();
    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showstack(gquiz);

    return 0;
}
/* Output:
The stack gquiz is : 	1	5	20	30	10

gquiz.size() : 5
gquiz.top() : 1
gquiz.pop() : 	5	20	30	10
*/
