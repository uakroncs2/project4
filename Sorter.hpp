#ifndef SORTER_HPP
#define SORTER_HPP

#include <vector>
#include <queue>

// A class for sorting!
// You will finish this for project 4
// Yay
// All of the sorts will take a std::vector<int> and return a sorted std::vector<int>

struct Sorter {

  // sort a vector using bubble sort
  static std::vector<int> bubblesort(const std::vector<int>&); 

  // sort a vector using insertion sort
  static std::vector<int> insertionsort(const std::vector<int>&); 

  // sort a vector using radix sort
  static std::vector<int> radixsort(const std::vector<int>&); 

  // sort a vector using quicksort
  static std::vector<int> quicksort(const std::vector<int>&); 
  
  // sort a vector using mergesort
  static std::vector<int> mergesort(const std::vector<int>&); 

};

std::vector<int> Sorter::bubblesort(const std::vector<int>& vec) {
  // you need to change this
  return vec;
}

std::vector<int> Sorter::insertionsort(const std::vector<int>& vec) {
  // you need to change this
  return vec;
}

std::vector<int> Sorter::radixsort(const std::vector<int>& vec) {
  
  // our main queue that will be turned into a vector at the end
  // also temporary storage as we move along the digits
  std::queue<int> main_queue;

  // see if the vector is empty
  if (vec.size() > 0) {
    
    // fill our main queue with the numbers in the vector
    // also find the largest value in the vector
    int largest = vec[0];
    for (int i = 0; i < vec.size(); ++i) {
      main_queue.push(vec[i]);
      largest = largest < vec[i] ? vec[i] : largest;
    }
    
    // compute the number of digits in the largest value
    int digits = 0;
    do {
      largest /= 10;
      ++digits;
    } while (largest != 0);
    
    // we need an array of queues for our buckets
    std::queue<int> buckets[10];
    
    //set a variable to hold the denominator
    int den = 1;
    
    // evaluate each digit for each number in the main_queue and put them
    // in the correct bucket for that digit's value
    for (int i = 0; i < digits; ++i) {
      // while the main queue has elements in it
      while(main_queue.size() > 0) {
	// store the number for storage later
	int temp = main_queue.front();
	main_queue.pop();
	// store the temp in the correct bucket
	buckets[(temp / den) % 10].push(temp);
      }
      
      // for each bucket
      for (int j = 0; j < 10; ++j) {
	// while there is something in the bucket
	while (buckets[j].size() > 0) {
	  // enqueue the value into our main queue
	  main_queue.push(buckets[j].front());
	  buckets[j].pop();
	}
      }
      
      // adjust the denominator for digit lookup later
      den *= 10;
    }
  }

  // move the sorted main queue into the return vector
  std::vector<int> ret;
  while(main_queue.size() > 0) {
    ret.push_back(main_queue.front());
    main_queue.pop();
  }
  return ret;
}

std::vector<int> Sorter::quicksort(const std::vector<int>& vec) {
  // you need to change this
  return vec;
}

std::vector<int> Sorter::mergesort(const std::vector<int>& vec) {
  // you need to change this
  return vec;
}

#endif
