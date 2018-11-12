#include <iostream>
#include <thread>


using namespace std;

int count =0;
int numThreads, numIncrementsPerThread;


void increment(int threadNo){
    cout << "Thread " << threadNo << " read count";
    count = count +numIncrementsPerThread;
    cout << "Thread " << threadNo << " incremented count";
}


int main(){
        
    
    cout << "Input numThreads: ";
    cin >> numThreads;
    cout << "Input numIncrementsPerThread: ";
    cin >> numIncrementsPerThread;

    thread allThreads[numThreads];

    for(int i =0; i < numThreads; i++){
        cout << "Thread " << i<< "spawning...\n";
        allThreads[i] = thread(increment, i); //spawn new thread
    }

    cout << "Threads spawned yaaa";

    
    
    for (int i = 0; i< numThreads; i++){
        allThreads[i].join(); 
        cout << "Thread " << i<< "joined\n";
    }

    cout << "count = " << count << endl;

    return 0;
}