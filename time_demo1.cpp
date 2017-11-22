//Example of operator overloading using member method
#include<iostream>
using namespace std;
class Time
{
	private:
		int hr,min,sec;
	public:
		Time()
		{
			hr=min=sec=0;
		}
		void getTime();
		void putTime();
		Time operator +(Time t);
};
Time Time::operator +(Time t)
{
	Time temp;
	temp.sec=sec+t.sec;
	if(temp.sec>=60)
	{
		temp.min=temp.sec/60;
		temp.sec=temp.sec%60;
	}
	temp.min=temp.min+min+t.min;
	if(temp.min>=60)
	{
		temp.hr=temp.min/60;
		temp.min=temp.min%60;
	}
	temp.hr=temp.hr+hr+t.hr;
	return temp;
}

int main()
{
	Time tim1,tim2,tim3;
	tim1.getTime();
	tim2.getTime();
	tim3=tim1+tim2; // implicit call(Explicit call tim1.operator +(tim2))
}
