#include "GaleShapley.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>

// Blank Constructor.
GaleShapley::GaleShapley() {};

// Constructor.
GaleShapley::GaleShapley(Graph people) {
  // Print average happiness for each method.
  float maleOnly = galeShapleyHelper(people, true, true);
  printf("Males Only: %f\n", maleOnly);
  float femaleOnly = galeShapleyHelper(people, true, false);
  printf("Females Only: % f\n", femaleOnly);  
  float maleFirstAlternate = galeShapleyHelper( people, false, true);
  printf("Male First Alternating: %f\n", maleFirstAlternate);  
  float femaleFirstAlternate = galeShapleyHelper( people, false, false);
  printf("Female First Alternating: %f\n", femaleFirstAlternate);
  // Print what type of method was most effective.
  if ( maleOnly < femaleOnly && maleOnly < maleFirstAlternate && maleOnly < femaleFirstAlternate ) {
    printf("\nMales alone yield max happiness.\n");
  } else if ( femaleOnly < maleOnly && femaleOnly < maleFirstAlternate && femaleOnly < femaleFirstAlternate ) {
    printf("\nFemales alone yield max happiness.\n");
  } else if ( maleFirstAlternate < maleOnly && maleFirstAlternate < femaleOnly && maleFirstAlternate < femaleFirstAlternate ) {
    printf("\nMales choosing first and alternating yields max happiness.\n");
  } else {
    printf("\nFemales choosing first and alternating yields max happiness.\n");
  }
  // Test pairings by printing 14 pairings (size of the smallest dataset that works with implementation) -- For Testing
  /*
  printPairings(14);
  */
}

// Helper method which executes the Gale-Shapley Algorithm.
const float GaleShapley::galeShapleyHelper(Graph people, bool oneSided, bool guyFirst, bool print) {
  // Initialize values.
  m_happiness = 0;  
  int full = people.size();
  pairings = std::vector<int>(full, -1);
  bool freePeople = true;
  // Iterate through the people until all people have exhausted their preferences or are paired.
  while (freePeople) {
    freePeople = false;
    // Adjust start and length of iteration depending on oneSided and gender preferences.
    int start; int length;
    if (oneSided && guyFirst) {length = full / 2;} else {length = full;}
    if (guyFirst || (!guyFirst && !oneSided)) {start = 0;} else {start = full / 2;}
    // Use these parameters to iterate over the people.
    for(int i = start; i < length; ++i) {
      // Handle female first alternating case.
      if ( !oneSided && !guyFirst ) { i = (i + full / 2) % full;}
      compareMatchings(i, people, freePeople);
      // If person has no match and they haven't maxed out their requests
      // then there are still free people.
      if (pairings[i] == -1 && people[i].happiness != 7) { freePeople = true;}
    }
  }
  // Match the remaining people with the first available person. 
  matchRemaining(int(full/2), people);
  // Potentially print the pairings and return the average happiness.
  if (print) { printPairings( full );}
  return float(m_happiness) / float(full);
}

// Helper method for galeShapleyHelper. A person potentially makes a  partner 
//request and then is accepted or rejected based on comparisons of matchings.
void GaleShapley::compareMatchings(int i, Graph& people, bool& freePeople) {
  int pref = people[i].happiness;
  // Do nothing if current match is ranked higher than next request level
  if (people[i].getRank(pairings[i]) > pref) {
    // Check if desired match prefers them more than their current match
    if (people[people[i][pref]].getRank(people[i].getID()) < people[people[i][pref]].getRank(pairings[people[i][pref]])) {
      // Assign correct matchings in pairings vector.
      if (pairings[i] != -1) { 
	pairings[pairings[i]] = -1;
	freePeople = true;
      }
      pairings[i] = people[i][pref];
      if (pairings[people[i][pref]] != -1) { 
	pairings[pairings[people[i][pref]]] = -1;
	freePeople = true;
      }
      pairings[people[i][pref]] = i;
    }
    // Increment request level if it is not already 7.
    if (pref != 7) {++people[i].happiness;}
  }
}

// Helper method for galeShapleyHelper. Matches a person with the first available partner.
// Calculates overall happiness for the group.
void GaleShapley::matchRemaining(int half, Graph& people) {
   int m = half;
    // Pair each available male with the first available female.
    for(int i = 0; i < half; ++i) {
      while (pairings[i] == -1) {
	if (pairings[m] == -1) {
 	  pairings[m] = i;
	  pairings[i] = m;
	}
	++m;
      }
      // Print Happiness of each person's final pairing (for testing purposes)
      /*
      printf("Person %d happiness = %d\n", i, people[i].getRank(pairings[i])); 
      printf("Person %d happiness = %d\n", pairings[i], people[pairings[i]].getRank(i)); 
      */
      // Add each partners happiness to group happiness (lower scores are beter).
      m_happiness += people[i].getRank(pairings[i]) + people[pairings[i]].getRank(i);
    }
}
