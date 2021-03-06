#include <iostream>
#include <array>
using namespace std;

/*template <class T,size_t N>
T maxSumSubsequence(array<T,N>& data)
{
	T sum =0,maxSum = 0, zero = static_cast<T>(O);
	//template<class T, size_t N>
	typename array<T,N>::iterator it;
	for( it = data.begin(); it !=data.end(); it++)
	{
		sum = sum+*it;
		if(sum < zero)
			sum = zero;
		else if(maxSum < sum)
			maxSum = sum;
	}
	return maxSum;
}*/

/*Kadane's Algorithm: This varaition of function handles negative numbers aswell */
template <class T,size_t N>
T maxSumSubsequence(array<T,N>& data)
{
        T sum = data[0], maxSum = data[0];
        size_t i;
        for(i = 1; i < data.size(); i++)
        {
                if(sum < 0)
                	sum = data[i];
                else
                	sum = sum + data[i];
                
                if(maxSum < sum)
                        maxSum = sum;
        }
        return maxSum;
}

int main() {
	// call maxSumSubsequence here
	array<int,8> intData = {1,-3,5,-2,9,-8,-6, 4};
	array<float,4> floatData = {-0.5,1.3,-0.5,3.0};
	cout << "Max Subsequence Sum of intData is: " << maxSumSubsequence(intData)<<endl;
	cout << "Max Subsequence Sum of floatData is: "<< maxSumSubsequence(floatData)<<endl;
	return 0;
}
