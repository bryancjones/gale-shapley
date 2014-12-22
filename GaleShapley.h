// 16bcj2, Bryan Jones, bcj2@williams.edu
// 17mss3, Melanie Subbiah, mss3@williams.edu

// We used C++ to implement the Graph data structure and Gale-Shapley algorithm
// to achieve a faster run time and greater variable type clarity. 

#ifndef GaleShapley_h
#define GaleShapley_h
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string>
#include "csv.h"

// Each ID identifies a person
typedef size_t ID;

// ************** Graph Class ****************
// The Graph class produces the data structure which holds the people and
// their preferences.
class Graph {
 protected:
  // *********** Person Class ****************
  // The Person class contains information on an individual and their preferences.
  class Person {
  protected:
    // The ID of the person.
    ID m_personID;
    // The vector of IDs corresponding to the person's preferences.
    std::vector<ID> m_preferences;
    // Gender of person (true means male). This variable is not currently used
    // because of how our dataset is structured, but it could be necessary with
    // other datasets.
    bool isMale;
    
  public:
    // The rank of the person's current partner.
    size_t happiness = 0;

    // Empty constructor.
    Person() {}

    // Constructor. Takes a vector of preferences, an ID and a gender.
    Person (std::vector<ID> input, ID newID, bool gender = true) {
      m_preferences = input;
      m_personID = newID;
      isMale = gender;
    }
    
    // Destructor. Swaps preference vector memory with a blank vector.
    ~Person() {
      std::vector<ID>().swap(m_preferences);
    }
    
    // Returns the person's ID.
    const ID getID() {
      return m_personID;
    }

    // Sets a vector of IDs as the person's preferences vector.
    void setPreferences(std::vector<ID> input) {
      m_preferences = input;
    }

    // Returns the person's preference corresponding to a rank. 
    const ID operator[](size_t rank) {
      return m_preferences[rank];
    }

    // Returns the person's gender.
    const bool gender() {
      return isMale;
    }
    
    // Returns the rank in the person's preferences of a given ID.
    // Returns 7 if the ID is not listed in the preferences.
    const int getRank(ID id) {
      // Check if each rank matches the given ID.
      for(int i = 0; i < 7; ++i) {
	if (m_preferences[i] == id) {
	  return i;
	}
      }
      return 7;
    }
  };
    // *************************************

  // The vector of people.
  std::vector<Person> m_people;
  // The number of people in the graph.
  size_t m_size = 0;
   
 public :
  // Blank constructor.
  Graph() {}
  
  // Constructor. Takes a csv file and imports the preference information
  // into a graph of people.
  Graph(const std::string& filename) {
    // Use CSVReader (in "csv.h" from https://code.google.com/p/fast-cpp-csv-parser) to open the file.
    io::CSVReader<7> in(filename);
    // Create a blank variables to use.
    std::vector<ID> preferences(7,0);
    Person student;
    // Parse each row and assign each column value to a spot in the preference vector.
    while(in.read_row(preferences[0], preferences[1], preferences[2], preferences[3], preferences[4], preferences[5], preferences[6])) {
      // Create a new person and add it to the vector of people.
      student = Person(preferences, m_size);
      m_people.push_back(student);
      // Increment the size of the graph.
      ++m_size;
    }
  }

  // Returns the number of people in the graph.
  size_t size() {
    return m_size;
  }
  
  // Returns a reference to the person corresponding to a given ID.
  Person& operator[]( ID index ) {
    return m_people[index];
  }
}; 
// **************************************


// ************* Gale-Shapley Algorithm Implementation *****************
class GaleShapley{
 protected:
  // Vector of final pairings. The values end up being IDs but must be defined as
  // ints because they are initialized as -1/
  std::vector<int> pairings;
  size_t m_happiness;

  // Prints a given number of pairings for testing purposes.
  void printPairings( int num ) {
    for( int i = 0; i < num ; ++i) {
      printf("Person # %d = %d\n", i, pairings[i]);
    }
  }
  
 public:
  GaleShapley();
  GaleShapley(Graph people);
  const float galeShapleyHelper(Graph people, bool oneSided = true, bool guyFirst = true, bool print = false);
  void compareMatchings(int i, Graph& people, bool& freePeople);
  void matchRemaining(int half, Graph& people);
};
// *****************************************
#endif
