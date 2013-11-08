<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<INCOMPLETE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#include <iostream>
#include <queue>
#include <math>
#include <algorithm>
using namespace std;

/*K Nearest points to origin*/
struct point{
	int x;
	int y;
};

/*compute distance*/
int distance(point p)
{
	return (static_cast<int>(sqrt(pow(p.x,2) + pow(p.y,2))));
}

class isNear
{
	public:
	bool operator()(point &p1, point &p2) /* returns true if p1 is farer than p2*/
	{
		if(distance(p1) > distance(p2))
			return true;
		else
			return false;
	}
}

array<point,size_t> findKNearestNeighbour(const array<point,size_t> &neighbors, int K)
{
	vector<point> KNN;
	
	priority_queue<point, vector<point>, isNear> pq;
	for(int i = 0 ; i < K; i++)
	{
		pq.push(array[i]);
	}
	
//	array<point,size_t>::iterator it;
    for(int i = K; i < neighbors.size(); i++)
    {
    	if(distance(pq.top()) > distance(neighbors[i]))
    		{
    			pq.pop();
    			pq.push(neighbors[i]);
    		}
    }
    
}

int main() {
	// your code goes here
	array<point,5> = {{2,1},{10,10},{2,5},{1,1},{3,4}};
	array<point,2> = findNearestNeighbor
	return 0;
}
