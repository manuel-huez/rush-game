#include "path.hh"

#include <vector>
#include <set>
#include <cmath>
#include <memory>
#include <iostream>

namespace PATH
{
  void Path::fill_heap()
  {
    for (unsigned x = 0; x < map_.size(); x++)
      queue_.insert(x);
  }

  int Path::pop_min_dist()
  {
    int min = -1;
    for (std::set<int>::iterator it = queue_.begin(); it != queue_.end();
        it++)
    {
      int x = *it;
      if (min == -1 || dist_[x] < dist_[min])
        min = x;
    }
    queue_.erase(min);

    return min;
  }

  void Path::check_neighbors(unsigned x, unsigned n)
  {
    if (n > map_.size() || !(queue_.find(n) != queue_.end()))
      return;
    if (dist_[n] > 1000)
    {
      dist_[n] = dist_[x] + map_[n];
      prev_[n] = x;
    }
    else
    {
      int altG = dist_[x] + map_[n];
      if (altG < dist_[n])
      {
        dist_[n] = altG;
        prev_[n] = x;
      }
    }
  }

  void Path::find_path()
  {
    dist_[source_] = 0;
    while (!queue_.empty())
    {
      int x = pop_min_dist();
      check_neighbors(x, x - 1);
      check_neighbors(x, x - size_);
      check_neighbors(x, x + 1);
      check_neighbors(x, x + size_);
    }
  }

  std::shared_ptr<std::vector<int>> Path::get_path(int x, int y) const
  {
    int cur = x + y * size_;
    std::cout << prev_[cur] << std::endl;
    auto path = std::make_shared<std::vector<int>>(dist_[cur]);
    while (cur != source_)
    {
      path->insert(path->begin(), prev_[cur]);
      cur = prev_[cur];

    }
    return path;
  }
}
