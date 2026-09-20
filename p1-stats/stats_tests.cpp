/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 *
 * EECS 280 Statistics Project
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

const double epsilon = 0.00001;

static bool almost_equal(double x, double y) {
  return abs(x - y) < epsilon;
}

void test_sum_small_data_set();
// Add prototypes for you test functions here.
void test_count();
void test_sum();
void test_mean_1();
void test_mean_2();
void test_median_1();
void test_median_2();
void test_median_3();
void test_min();
void test_max();
void test_stdev();
void test_percentile_1();
void test_percentile_2();
void test_percentile_3();
void test_filter();

int main() {
  test_sum_small_data_set();
  // Call your test functions here
  test_count();
  test_sum();
  test_mean_1();
  test_mean_2();
  test_median_1();
  test_median_2();
  test_median_3();
  test_min();
  test_max();
  test_stdev();
  test_percentile_1();
  test_percentile_2();
  test_percentile_3();
  test_filter();

  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS!" << endl;
}

// Add the test function implementations here.
void test_count() {
  cout << "test_count" << endl;

  vector<double> data;
  data.push_back(18);
  data.push_back(-20);
  data.push_back(35);
  data.push_back(47);
  data.push_back(28);
  data.push_back(73);
  data.push_back(24);
  data.push_back(91);
  data.push_back(-64);
  data.push_back(39);

  assert(count(data) == 10);

  cout << "PASS!" << endl;
}

void test_sum() {
  cout << "test_sum" << endl;

  vector<double> data;
  data.push_back(18);
  data.push_back(-20);
  data.push_back(35);
  data.push_back(47);
  data.push_back(28);
  data.push_back(73);
  data.push_back(24);
  data.push_back(91);
  data.push_back(-64);
  data.push_back(39);

  assert(sum(data) == 271);

  cout << "PASS!" << endl;
}

void test_mean_1() {
  cout << "test_mean_1" << endl;

  vector<double> data;
  data.push_back(18);
  data.push_back(20);
  data.push_back(35);
  data.push_back(47);
  data.push_back(28);
  data.push_back(73);
  data.push_back(24);
  data.push_back(91);
  data.push_back(64);
  data.push_back(39);

  assert(almost_equal(mean(data), 43.9));

  cout << "PASS!" << endl;
}

void test_mean_2() {
  cout << "test_mean_2" << endl;

  vector<double> data;
  data.push_back(23);
  data.push_back(23);
  data.push_back(23);
  data.push_back(23);
  data.push_back(23);
  data.push_back(23);
  data.push_back(23);
  data.push_back(23);
  data.push_back(23);
  data.push_back(23);

  assert(almost_equal(mean(data), 23));

  cout << "PASS!" << endl;
}

void test_median_1() {
  cout << "test_median_1" << endl;

  vector<double> data;
  data.push_back(18);
  data.push_back(20);
  data.push_back(35);
  data.push_back(47);
  data.push_back(28);
  data.push_back(73);
  data.push_back(24);
  data.push_back(91);
  data.push_back(64);
  data.push_back(39);

  // {18, 20, 24, 28, 35, 39, 47, 64, 73, 91}
  // 0->9
  //

  assert(median(data) == 37);

  cout << "PASS!" << endl;
}
  
void test_median_2() {
  cout << "test_median_2" << endl;

  vector<double> data;
  data.push_back(18);

  assert(median(data) == 18);

  cout << "PASS!" << endl;
}
  
void test_median_3() {
  cout << "test_median_3" << endl;

  vector<double> data;
  data.push_back(18);
  data.push_back(20);
  data.push_back(50);
  data.push_back(42);
  data.push_back(28);
  data.push_back(18);
  data.push_back(20);
  data.push_back(50);
  data.push_back(42);
  data.push_back(28);
  data.push_back(18);
  data.push_back(20);
  data.push_back(50);
  data.push_back(42);
  data.push_back(28);

  //[18, 18, 18, 20, 20, 20, 28, 28, 28, 42, 42, 42, 50, 50, 50].

  assert(median(data) == 28);

  cout << "PASS!" << endl;
}
  
void test_min() {
  cout << "test_min" << endl;

  vector<double> data;
  data.push_back(18);
  data.push_back(20);
  data.push_back(35);
  data.push_back(47);
  data.push_back(28);
  data.push_back(73);
  data.push_back(24);
  data.push_back(91);
  data.push_back(64);
  data.push_back(39);

  assert(min(data) == 18);

  cout << "PASS!" << endl;
}

void test_max() {
  cout << "test_max" << endl;

  vector<double> data;
  data.push_back(18);
  data.push_back(20);
  data.push_back(35);
  data.push_back(47);
  data.push_back(28);
  data.push_back(73);
  data.push_back(24);
  data.push_back(91);
  data.push_back(64);
  data.push_back(39);

  assert(max(data) == 91);

  cout << "PASS!" << endl;
}

void test_stdev() {
  cout << "test_stdev" << endl;

  vector<double> data;
  data.push_back(18);
  data.push_back(20);
  data.push_back(35);
  data.push_back(47);
  data.push_back(28);
  data.push_back(73);
  data.push_back(24);
  data.push_back(91);
  data.push_back(64);
  data.push_back(39);

  assert(almost_equal(stdev(data), (24.6596837)));

  cout << "PASS!" << endl;
}

void test_percentile_1() {
  cout << "test_percentile_1" << endl;

  vector<double> data;
  data.push_back(18);
  data.push_back(20);
  data.push_back(35);
  data.push_back(47);
  data.push_back(28);
  data.push_back(73);
  data.push_back(24);
  data.push_back(91);
  data.push_back(64);
  data.push_back(39);

  // {18, 20, 24, 28, 35, 39, 47, 64, 73, 91}
  //   0   1   2   3   4  5   6   7   8   9
  assert(almost_equal(percentile(data, 0.8), 65.8));

  cout << "PASS!" << endl;
}

void test_percentile_2() {
  cout << "test_percentile_2" << endl;

  vector<double> data;
  data.push_back(5);
  data.push_back(5);
  data.push_back(5);
  data.push_back(5);
  data.push_back(5);
  data.push_back(5);
  data.push_back(5);
  data.push_back(5);
  data.push_back(5);
  data.push_back(5);

  // {18, 20, 24, 28, 35, 39, 47, 64, 73, 91}
  //   0   1   2   3   4  5   6   7   8   9
  assert(almost_equal(percentile(data, 0.2), 5));

  cout << "PASS!" << endl;
}

void test_percentile_3() {
  cout << "test_percentile_3" << endl;

  vector<double> data = {};
  data.push_back(5);
  data.push_back(2);
  data.push_back(6);
  data.push_back(7);
  data.push_back(10);

  //Sorted vector: {2, 5, 6, 7, 10}
  //Fixed exit status error 250 -> out of bound error for this vector when p = 1.0 => k = 5. If k = 5,
  //v[5] violates the "index out of bound rule".
  //Previously had an if-condition if (k > n), where n is the number of items in the vector.
  //Now if (k == n), since k can't never be greater than n, just equal and that is when the error appears.
  assert(almost_equal(percentile(data, 1.0), 10));

  cout << "PASS!" << endl;
}


void test_filter() {
  cout << "test_filter" << endl;

  vector<double> data;
  data.push_back(18);
  data.push_back(20);
  data.push_back(35);
  data.push_back(47);
  data.push_back(28);
  data.push_back(73);
  data.push_back(24);
  data.push_back(91);
  data.push_back(64);
  data.push_back(39);

  vector<double> criteria = {0, 0, 1, 0, 0, 0, 0, 1, 0, 0};
  assert(filter(data, criteria, 1) == vector<double>({35, 91}));

  cout << "PASS!" << endl;
}

