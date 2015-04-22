
#include <string>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;
class Movie
{
public:	
	
	string name;
	double rating;

	Movie(string  newname, double newRating)
	{
		name = newname;
		rating = newRating;
	}

};

bool operator < (const Movie& movie1, const Movie& movie2)
{
	return movie1.rating  > movie2.rating;
}

bool operator > (const Movie& movie1, const Movie& movie2)
{
	return movie1.rating < movie2.rating;
}


struct compare
{
public:
	bool operator() (const Movie& m1, const Movie& m2)
	{
		return m1.rating < m2.rating;
	}
};

int main()
{
	priority_queue<Movie, vector<Movie>, less<vector<Movie>::value_type >  > movieQueue;
	priority_queue<Movie, vector<Movie>, compare  > movieQueue2;


	movieQueue.push(Movie("A", 1.2));
	movieQueue.push(Movie("B", 4.2));
	movieQueue.push(Movie("C", 2.7));
	movieQueue.push(Movie("D", 3.2));
	movieQueue.push(Movie("E", 3.5));
	movieQueue.push(Movie("F", 5.2));


	while (!movieQueue.empty())
	{
		cout << movieQueue.top().name << endl;
		movieQueue.pop();
	}
	cout << endl;

	movieQueue2.push(Movie("A", 1.2));
	movieQueue2.push(Movie("B", 4.2));
	movieQueue2.push(Movie("C", 2.7));
	movieQueue2.push(Movie("D", 3.2));
	movieQueue2.push(Movie("E", 3.5));
	movieQueue2.push(Movie("F", 5.2));
	

	while (!movieQueue2.empty())
	{
		cout << movieQueue2.top().name << endl;
		movieQueue2.pop();
	}


	return 0;
}