
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

int main()
{

	priority_queue<Movie, vector<Movie>, less<vector<Movie>::value_type >  > movieQueue;

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

	return 0;
}