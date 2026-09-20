// stats.cpp
#include "stats.hpp"
#include <cassert>
#include <vector>
#include <algorithm> // sort
#include <cmath>     // sqrt, modf
#include <iostream>

using namespace std;

int count(vector<double> v)
{
  int result = 0;
  for (size_t i = 0; i < v.size(); ++i)
  {
    result++;
  }
  return result;
}

double sum(vector<double> v)
{
  double result = 0;
  for (size_t i = 0; i < v.size(); ++i)
  {
    result += v[i];
  }
  return result;
}

double mean(vector<double> v)
{
  return (sum(v) / count(v));
}

double median(vector<double> v)
{
  std::sort(v.begin(), v.end());
  int v_size = v.size();
  if (v_size % 2 != 0)
  {
    return v[(v_size - 1) / 2];
  }
  else if (v_size % 2 == 0)
  {
    return ((v[(v_size - 1) / 2] + v[(v_size) / 2]) / 2);
  }
  else
  {
    return 0.0;
  }
}

double min(vector<double> v)
{
  double min_value = v[0];
  for (size_t i = 1; i < v.size(); ++i)
  {
    if (min_value > v[i])
    {
      min_value = v[i];
    }
  }
  return min_value;
}

double max(vector<double> v)
{
  double max_value = v[0];
  for (size_t i = 1; i < v.size(); ++i)
  {
    if (max_value < v[i])
    {
      max_value = v[i];
    }
  }
  return max_value;
}

double stdev(vector<double> v)
{
  double sum_diff_mean = 0.0;
  for (size_t i = 0; i < v.size(); ++i)
  {
    sum_diff_mean += std::pow((v[i] - mean(v)), 2);
  }
  return sqrt((sum_diff_mean) / (count(v) - 1)) * 1.0;
}

double percentile(vector<double> v, double p)
{
  std::sort(v.begin(), v.end());
  int n = count(v);
  double rank = p * (n - 1) + 1;
  int k = floor(rank);
  double d = rank - k;
  if (k == n)
  {
    return v[k - 1];
  }
  return (v[k - 1] + d * (v[k] - v[k - 1]));
}

vector<double> filter(vector<double> v, vector<double> criteria, double target)
{
  vector<double> result;
  for (size_t i = 0; i < v.size(); ++i)
  {
    if (criteria[i] == target)
    {
      result.push_back(v[i]);
    }
  }
  return result;
}
