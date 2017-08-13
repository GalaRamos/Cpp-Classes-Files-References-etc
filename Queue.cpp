/*
Queues are a type of container adaptors which operate in a first in first out
(FIFO) type of arrangement. Elements are inserted at the back (end) and are
deleted from the front.

  empty() – Returns whether the queue is empty
  size() – Returns the size of the queue
  front() – Returns a reference to the first element of the queue
  back() – Returns a reference to the last element of the queue
  push(g) – Adds the element ‘g’ at the end of the queue
  pop() – Deletes the first element of the queue
*/

#include <iostream>
#include <queue>

using namespace std;

void showq(queue <int> gq)
{
    queue <int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

int main()
{
    queue <int> gquiz;
    gquiz.push(10);
    gquiz.push(20);

    cout << "The queue gquiz is : ";
    showq(gquiz);

    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.front() : " << gquiz.front();
    cout << "\ngquiz.back() : " << gquiz.back();

    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showq(gquiz);

    return 0;
}
/* Output:
The queue gquiz is : 	10	20

gquiz.size() : 2
gquiz.front() : 10
gquiz.back() : 20
gquiz.pop() : 	20
*/
