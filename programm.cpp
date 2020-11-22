#include <iostream>
#include <thread>

using namespace std;

void Sum(int &a)
{
  this_thread::sleep_for(chrono::milliseconds(3000));

  cout << "===============| Sum started |===============" << endl;

  this_thread::sleep_for(chrono::milliseconds(4000));

  a *= 2;

  this_thread::sleep_for(chrono::milliseconds(4000));

  cout << "===============| Sum stopped |===============" << endl;
}



int main()
{
  setlocale(LC_ALL, "ru");

  int a = 3;

  thread p(Sum, std::ref(a));

  for (size_t i=0; i < 10; i++)
  {
    cout << "ID potoka: "<< this_thread::get_id() <<  "\tmain works\t" << i << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
  }

  cout << a << endl;
  p.join();

}
