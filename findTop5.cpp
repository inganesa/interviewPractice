/*question::
Given a list of test results (each with a test date, Student ID, and the student’s Score), return the Final Score for each student. A student’s Final Score is calculated as the average of his/her 5 highest test scores. You can assume each student has at least 5 test scores.
next one*/
#include <iostream>
using namespace std;

class TestResult {
public:
  int studentId;
  string testDate;
  int testScore;
};
typedef priority_queue<double,vector<double>,isSmaller) que;

class isSmaller{
	public:
 bool operator()(double &val1, double &val2)
	{
		if(val1 <= val2)
			return true;
	}
	
}

double isAverage(que)
{
	double average;
	while(!que.empty())
	{
		average = average+que.top();
		que.pop();
	}
	average = (average/5);
}


 
map<int, double>  calculateFinalScores (vector<TestResult> results) {
 
unordered_map<int,priority_queue> topFive;
vector<TestResult> results::iterator it;

for( it = results.begin(); it!= results.end(); it++)
{
	que pq;
	unordered_map<int,priority_queue>:: const_iterator found;
	found = topFive.find(it->studentID);
	if(found == results.end())
		{
			/*new student, add to the map*/
			pq.push(it->testScore);
	    	topFive.insert(make_pair<int,que>(it->studentID,pq));
		}
		else
		{
		    pq = found.second();
			if(pq.top() < it->testScore)
				{
					pq.top();
					pq.push(it->testScore);
				}
				it->second = pq;
		}
}

/*now once the hash table is built,  make a map of average value*/

map<int, double> result;
vector<TestResult> results::iterator itr;
for(itr = topFive.begin(); itr != topFive.end(); itr++)
{
	result.insert(make_pair<int,double>(it->first, getAverage(it->second)))
}

return result;
}

int main() {
	// your code goes here
	return 0;
}
