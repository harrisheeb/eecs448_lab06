/**
*	@file Tester.cpp
*	@author Harrison Heeb
*	@date 2014.09.11
*/



void Tester::Test1()
{
  //test of the constructor
  std::cout<<"\n";
  std::cout<<"Constructor Test:\n";
  std::cout<<"Test 1:";
  Queue q;
  std::cout<<"\t Newly created queue is empty: ";
  printTest(q.isEmpty());
  std::cout<<"\n";
}

void Tester::Test2()
{
  //test of the destructor
  std::cout<<"Destructor Test:\n";
  std::cout<<"Test 1:";
  std::cout<<"\t Empty queue can be deleted: ";
  Queue* q = new Queue();
  q->enqueue(5);
  q->enqueue(6);
  delete q;
  bool stuff = true;
  printTest(stuff);
  std::cout<<"\n";
}

void Tester::Test3()
{
  //test of isEmpty
  std::cout<<"IsEmpty Test:\n";
  std::cout<<"Test 1: ";
  Queue q;
  q.enqueue(5);
  std::cout<<"Enqueing a value makes the Queue not empty: ";
  printTest(!q.isEmpty());

  std::cout<<"Test 2: ";
  q.enqueue(6);
  std::cout<<"Enqueing two values makes the Queue not empty: ";
  printTest(!q.isEmpty());

  std::cout<<"Test 3: ";
  q.dequeue();
  q.dequeue();
  std::cout<<"Dequeing two values makes the Queue empty: ";
  printTest(q.isEmpty());

  std::cout<<"Test 4: ";
  q.enqueue(5);
  std::cout<<"Enqueing a value after dequeing makes the Queue not empty: ";
  printTest(!q.isEmpty());

  std::cout<<"Test 5: ";
  q.enqueue(5);
  q.enqueue(5);
  q.enqueue(5);
  q.enqueue(5);
  q.enqueue(5);
  q.enqueue(5);
  q.enqueue(5);
  q.enqueue(5);
  q.enqueue(5);
  q.enqueue(5);
  std::cout<<"Enqueing 10 values makes the Queue not empty: ";
  printTest(!q.isEmpty());

  std::cout<<"\n";
}

void Tester::Test4()
{
  //test of enqueue
  std::cout<<"Enqueue Test:\n";

  std::cout<<"Test 1: ";
  Queue q;
  q.enqueue(5);
  std::cout<<"Enqueing 1000 values makes the Queue not empty: ";
  for(int i = 0; i < 1000; i++){
    q.enqueue(i);
  }
  printTest(!q.isEmpty());

  std::cout<<"Test 2: ";
  Queue q1;
  q1.enqueue(0);
  std::cout<<"Enqueing 0 and then 1000 values makes the front = 0: ";
  for(int i = 0; i < 1000; i++){
    q1.enqueue(i);
  }
  q1.enqueue(5);
  printTest(q1.peekFront() == 0);

  std::cout<<"Test 3: ";
  Queue q2;
  q2.enqueue(0);
  std::cout<<"Enqueing 0 makes the front = 0: ";
  q2.enqueue(5);
  printTest(q2.peekFront() == 0);


  std::cout<<"\n";
}

void Tester::Test5()
{
  //test of dequeue
  std::cout<<"Dequeue Test:\n";


  std::cout<<"Test 1: ";
  Queue q;
  std::cout<<"Enqueing 1000 values and then dequeing them all makes the Queue empty: ";
  for(int i = 0; i < 1000; i++){
    q.enqueue(i);
  }
  for(int i = 0; i < 1000; i++){
    q.dequeue();
  }
  printTest(q.isEmpty());

  std::cout<<"Test 2: ";
  Queue q1;
  q1.enqueue(0);
  std::cout<<"Enqueing 0 and then dequeing it returns an int type: ";
  std::string yo = typeid(q1.dequeue()).name();
  printTest(yo == "i");

  std::cout<<"Test 3: ";
  Queue q2;
  std::cout<<"Dequeing empty queue throws an error: ";
  bool errorthing = false;
  try
  {
    q2.dequeue();
  }
  catch (const std::runtime_error& error)
  {
    // your error handling code here
    errorthing = true;
  }

  printTest(errorthing);

  std::cout<<"Test 4: ";
  Queue q4;
  std::cout<<"Dequeing removes the front of the queue: ";
  q4.enqueue(5);
  q4.enqueue(6);
  q4.dequeue();
  printTest(q4.peekFront() == 6);



  std::cout<<"\n";
}

void Tester::Test6()
{
  //test of peekFront
  std::cout<<"PeekFront Test:\n";

  std::cout<<"Test 1: ";
  Queue q1;
  q1.enqueue(0);
  std::cout<<"Enqueing 0 and then 50 values makes the front = 0: ";
  for(int i = 0; i < 50; i++){
    q1.enqueue(i);
  }
  q1.enqueue(5);
  printTest(q1.peekFront() == 0);


  std::cout<<"Test 2: ";
  Queue q2;
  std::cout<<"Peeking the front of an empty queue throws an error: ";
  bool errorthing = false;
  try
  {
    q2.peekFront();
  }
  catch (const std::runtime_error& error)
  {
    // your error handling code here
    errorthing = true;
  }
  printTest(errorthing);


  std::cout<<"Test 3: ";
  Queue q3;
  std::cout<<"Peeking the front of an empty queue after adding an element and then deleting it throws an error: ";
  bool errorthing2 = false;
  q3.enqueue(5);
  q3.dequeue();
  try
  {
    q3.peekFront();
  }
  catch (const std::runtime_error& error)
  {
    // your error handling code here
    errorthing2 = true;
  }
  printTest(errorthing2);

  std::cout<<"Test 4: ";
  Queue q4;
  std::cout<<"Peeking the front of an empty queue after adding 2 elements = the first element: ";
  q4.enqueue(5);
  q4.enqueue(6);
  printTest(q4.peekFront() == 5);



    std::cout<<"\n";
}
void Tester::printTest(bool cond){
  if(cond){
    std::cout<<"PASSED\n";
  } else {
    std::cout<<"FAILED\n";
  }
}
