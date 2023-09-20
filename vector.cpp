#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void passByRef(const T& arr) // will accept any type of object that has an overloaded operator[]
{
    std::cout << arr[0] << '\n';
}

// accepts vector of any type
template <typename T>
void passByRef(const std::vector<T>& arr)
{
    std::cout << arr[0] << '\n';
}


void passVector(const vector<int>& array) {
  cout << array[0] << endl;
}


int main() {
  vector<int> v1 = {1, 2, 3, 4};
  v1.front(); // first element
  v1.back(); // last element 
  v1.push_back(5); // adding element to the end (append)
  v1.pop_back(); // taking out an element from the end
  size_t length = v1.size(); // 

  v1.shrink_to_fit(); // capacity becomes equal to size
  v1.insert(v1.begin(), 0); // inserts 0 at the beginning of vector
  v1.erase(v1.begin()); // deletes first element

  v1.at(0); //
  v1.at(0) = 9; // change first element of the vector to 9
  // empty(); // returns true if the vector is empty
  // clear(); // removes all the elements of the vector

  cout << v1.capacity() << "\n";
  cout << v1.size() << "\n";

  // declare iterator
  vector<int>::iterator iter;

  // use iterator with for loop
  for (iter = v1.begin(); iter != v1.end(); ++iter) {
    cout << *iter << " ";
  }

  cout << "\n";

  // vector containing 10 elements, value initialised to 0
  vector<int> data(10);

  passVector(v1);
 
  return 0;
}