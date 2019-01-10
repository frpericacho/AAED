#include <iostream>
#include <atomic>
#include <mutex>
#include <ctime>
#include <chrono>
#include <vector>
#include <thread>

using namespace std;

struct recurso
{
  int valor = 0;
  mutex cerrojo;
  void incrementar()
  {
    cerrojo.lock();
    valor++;
    cerrojo.unlock();
  }
};

struct atomico
{
  atomic<int> contador;
  void incremento()
  {
    contador++;
  }
};


int main()
{
  chrono::time_point<chrono::system_clock> startM,endM,startA,endA;
  recurso contador;
  vector<thread> hilos;
  std::chrono::duration<double> elapsed_secondsA,elapsed_secondsM;
  int it = 1;
  cout<<"Accesos  Mutex  atomic"<<endl;
  while(it<100)
  {
      startM = chrono::system_clock::now();
      for(int i = 0;i<1000;++i)
        hilos.push_back(thread([&contador](){
          for(int j = 0;j<100;++j)
            {  contador.incrementar(); }
        }));
      for(auto& thread : hilos)
      {
        thread.join();
      }
      endM = chrono::system_clock::now();
      atomico cont;
      hilos.clear();
      startA = chrono::system_clock::now();
      for(int i = 0;i<1000;++i)
        hilos.push_back(thread([&cont](){
          for(int j = 0;j<100;++j)
            {  cont.incremento(); }
        }));
      for(auto& thread : hilos)
      {
        thread.join();
      }
      endA = chrono::system_clock::now();
      elapsed_secondsA = endA-startA;
      elapsed_secondsM = endM-startM;
      cout<<it<<"     "<< elapsed_secondsM.count()<<"  "<< elapsed_secondsA.count()<<endl;
      it++;
  }
  return 0;
}