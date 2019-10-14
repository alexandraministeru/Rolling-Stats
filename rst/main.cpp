//Author: Alexandra Ministeru


#include <iostream>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <deque>
#include <time.h>

using namespace std;

template <class T>  //Generic data management
class Object
{
   public:
        Object(){}; //Default constructor
        Object(unsigned long t): TimeLimit(t){};    //Constructor sets the lifespan of a value in the container
        Object(const Object& someObject, int qs, int qe): TimeLimit(someObject.TimeLimit)   //Constructor copies a set range of elements to new object to preserve original container
        {
	        std::copy(someObject.StoreData.begin()+qs, someObject.StoreData.begin()+qe+1,std::back_inserter(StoreData));
        }

        void DeleteOld();
        void Add(T num);
        void Display();
        double Mean();
        double Median();
	    T Sum();
	    double StandardDeviationPopulation();
        double StandardDeviationSample();
        void SelectQuery(int query_start, int query_end);   //Declaration of function to delete data outside a specified range and modify the original container
        void FlushContainer();  //Extended class functionality

   private:
        std::deque<T> StoreData;    //Container where data will be stored
        std::deque<unsigned long> timeStamps;   //Container that stores the timestamps of the elements
        unsigned long TimeLimit;    //Lifespan of element

};

template <class T>
void Object<T>::DeleteOld() //Definition for function that removes elements that exceeded the time limit
{

    while(((timeStamps.back() - timeStamps.front())/CLOCKS_PER_SEC) > TimeLimit)
    {
        StoreData.pop_front();
        timeStamps.pop_front();
    }

}

template <class T>
void Object<T>::Add(T num)  //Definition of function for adding new element in container
{
    StoreData.push_back(num);
    timeStamps.push_back((unsigned long) clock());

    DeleteOld();
}


template <class T>
void Object<T>::Display() //Definition of function for displaying the container
{
    DeleteOld();
    for(unsigned int i=0; i<StoreData.size(); i++)
    {
        std::cout<<"Element["<<i<<"]="<<StoreData[i]<<std::endl;
    }

    std::cout << std::endl;
}

template <class T>
double Object<T>::Mean()    //Definition of function for calculating the mean
{
    T sum; int dimension;
    sum=std::accumulate(StoreData.begin(), StoreData.end(), 0.0);
    dimension=StoreData.size();
    double mean=static_cast<double>(sum)/dimension;
    std::cout<<"Mean is: ";
    return mean;
}

template <class T>
double Object<T>::Median()  //Definition of function for calculating the median value
{
    int dimension;
    dimension=StoreData.size();
    std::sort(StoreData.begin(), StoreData.end());

    if (dimension%2==0)
    {
        std::cout<<"Median is: ";
        return (StoreData[dimension/2 - 1] + StoreData[dimension/2])/2;
    }
    else
    {
        std::cout<<"Median is: ";
        return StoreData[dimension/2];
    }
    std::cout<<std::endl;
}

template <class T>
T Object<T>::Sum()  //Definition for calculating the sum of elements in the container
{
    T sum;
    sum=std::accumulate(StoreData.begin(), StoreData.end(), 0.0);

    std::cout<<"Sum is: ";
    return sum;
    std::cout<<std::endl;
}

template <class T>
double Object<T>::StandardDeviationPopulation() //Definition for calculating the population standard deviation
{
    double E=0;
    T sum; int dimension; double mean;
    sum=std::accumulate(StoreData.begin(), StoreData.end(), 0.0);
    dimension=StoreData.size();
    mean=static_cast<double>(sum)/dimension;

    for(unsigned int i=0; i<StoreData.size(); i++)
        E+=(StoreData[i] - mean) * (StoreData[i] - mean);

    std::cout<<"Population standard deviation is: ";
    return sqrt(E/(dimension));//population standard deviation
    std::cout<<std::endl;
}

template <class T>
double Object<T>::StandardDeviationSample() //Definition for calculating the sample standard deviation
{
    double E=0;
    T sum; int dimension; double mean;
    sum=std::accumulate(StoreData.begin(), StoreData.end(), 0.0);
    dimension=StoreData.size();
    mean=static_cast<double>(sum)/dimension;

    for(unsigned int i=0; i<StoreData.size(); i++)
        E+=(StoreData[i] - mean) * (StoreData[i] - mean);

    std::cout<<"Sample standard deviation is: ";
    return sqrt(E/(dimension-1));//sample standard deviation
    std::cout<<std::endl;
}

template <class T>
void Object<T>::SelectQuery(int query_start, int query_end) //Definition of function for setting the range and
{                                                           //removing elements outside the range
    int dimension=StoreData.size();

    for (unsigned int p=query_end; p<dimension; p++)
         StoreData.pop_back();

    for (unsigned int p=0; p<query_start-1; p++)
         StoreData.pop_front();
}

template <class T>
void Object<T>::FlushContainer()    //Definition to clear container if needed
{
    StoreData.clear();
}

int main()
{
    Object<float> obj(10);
	/*obj.Add(1.5);
	obj.Add(2.5);
	obj.Add(2);
	obj.Add(3689);
	obj.Add(523.4);
	obj.Add(90);
	obj.Add(69);
	obj.Add(420.323);
	obj.Add(233);

	obj.Display();

	Object<float> obj2(obj,2,5);
    obj2.Display();

    std::cout<<obj.Mean()<<std::endl;
	std::cout<<obj.Median()<<std::endl;
	std::cout<<obj.Sum()<<std::endl;
    std::cout<<obj.StandardDeviationPopulation()<<std::endl;
    std::cout<<obj.StandardDeviationSample()<<std::endl;

    std::cout<<std::endl;
    obj.SelectQuery(2,5);
    obj.Display();*/

    int choice;
    int flag;
    flag = 1;
    while(flag == 1) {
        cout<<endl<<"Choose option: "<<endl<<endl << "-> 1 - Add one element"<<endl<<"-> 2 - Add multiple elements"<<endl<<
        "-> 3 - Display current data"<<endl<<"-> 4 - Get statistics"<<endl<<"-> 5 - Flush all data"<<endl<<
        "-> 6 - Select query (and delete the rest of the data)"<<endl<<
        "-> 7 - Exit"<<endl;

        std::cin>>choice;
        int numberOfElements;
        float element;
        int queryStart;
        int queryEnd;

        switch(choice) {
            case 1:
                std::cout<<endl<<"Type element: "<<endl;
                std::cin>>element;
                obj.Add(element);
                break;
            case 2:
                std::cout<<endl<<"How many?"<<endl;
                std::cin>>numberOfElements;
                std::cout<<endl;
                for (int i = 0; i < numberOfElements; i++) {
                    std::cin>>element;
                    obj.Add(element);
                }
                break;

            case 3:
                std::cout<<endl;
                obj.Display();
                break;
            case 4:
                std::cout<<endl;
                std::cout<<obj.Mean();
                std::cout<<endl;
                std::cout<<obj.Median()<<std::endl;
                std::cout<<obj.Sum()<<std::endl;
                std::cout<<obj.StandardDeviationPopulation()<<std::endl;
                std::cout<<obj.StandardDeviationSample()<<std::endl;
                break;

            case 5:
                obj.FlushContainer();
                std::cout<<endl<<"Flushed!"<<endl;
                break;

            case 6:
                std::cout<<endl<<"Query start: "<<endl;
                std::cin>>queryStart;
                std::cout<<"Query end: "<<endl;
                std::cin>>queryEnd;
                obj.SelectQuery(queryStart,queryEnd);
                break;

            case 7:
                flag = 0;
                break;
            default:
                std::cout<<endl<<"Please retype option."<<endl;
                break;
            }

}

	return 0;
}

