#include <iostream>
#include <stack>
#include <queue>
#include <chrono>
using namespace std;
using namespace chrono;
template &lt;class T&gt;
class MyStack
{
private:
T data[10000];
int top;
public:
MyStack()
{
    top = -1;
}
void push(T value)
{
if (top &lt; 9999)
data[++top] = value;
}
void pop()
{
if (top &gt;= 0)
top--;
}
};
template &lt;class T&gt;
class MyQueue
{
private:
T data[10000];
int front, rear;
public:
MyQueue()
{
front = 0;
rear = -1;
}
void enqueue(T value)
{
if (rear &lt; 9999)
data[++rear] = value;
}
void dequeue()
{


if (front &lt;= rear)
front++;
}
};
int main()
{
const int N = 10000;

// Custom Stack Benchmark
auto start = high_resolution_clock::now();
MyStack&lt;int&gt; myStack;
for (int i = 0; i &lt; N; i++)
myStack.push(i);
for (int i = 0; i &lt; N; i++)
myStack.pop();
auto end = high_resolution_clock::now();
auto customStackTime =
duration_cast&lt;microseconds&gt;(end - start);
// STL Stack Benchmark
start = high_resolution_clock::now();
stack&lt;int&gt; stlStack;
for (int i = 0; i &lt; N; i++)
stlStack.push(i);
for (int i = 0; i &lt; N; i++)
stlStack.pop();
end = high_resolution_clock::now();
auto stlStackTime =
duration_cast&lt;microseconds&gt;(end - start);
// Custom Queue Benchmark
start = high_resolution_clock::now();
MyQueue&lt;int&gt; myQueue;
for (int i = 0; i &lt; N; i++)


myQueue.enqueue(i);
for (int i = 0; i &lt; N; i++)
myQueue.dequeue();
end = high_resolution_clock::now();
auto customQueueTime =
duration_cast&lt;microseconds&gt;(end - start);
// STL Queue Benchmark
start = high_resolution_clock::now();
queue&lt;int&gt; stlQueue;
for (int i = 0; i &lt; N; i++)
stlQueue.push(i);
for (int i = 0; i &lt; N; i++)
stlQueue.pop();
end = high_resolution_clock::now();
auto stlQueueTime =
duration_cast&lt;microseconds&gt;(end - start);
cout &lt;&lt; &quot;Custom Stack Time: &quot;
&lt;&lt; customStackTime.count() &lt;&lt; &quot; microseconds&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;STL Stack Time: &quot;
&lt;&lt; stlStackTime.count() &lt;&lt; &quot; microseconds&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;Custom Queue Time: &quot;
&lt;&lt; customQueueTime.count() &lt;&lt; &quot; microseconds&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;STL Queue Time: &quot;
&lt;&lt; stlQueueTime.count() &lt;&lt; &quot; microseconds&quot; &lt;&lt; endl;
return 0;