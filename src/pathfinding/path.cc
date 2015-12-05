#include "path.hh"

#include <vector>
#include <set>
#include <cmath>
#include <memory>

namespace PATH
{
  void Path::fill_heap()
  {
    for (unsigned x = 0; x < map_.size() * map_.size(); x++)
      queue_.insert(x);
  }

  int Path::pop_min_dist()
  {
    int min = dist_[0];
    for (unsigned x = 0; x < map_.size() * map_.size(); x++)
    {
      if (dist_[x] < min)
        min = dist_[x];
    }
    queue_.erase(min);
    return min;
  }

  void Path::check_neighbors(unsigned x, unsigned n)
  {
    if (n < map_.size())
      return;
    int altG = dist_[n] + map_[x];
    if (altG < dist_[n])
    {
      dist_[n] = altG;
      prev_[n] = x;
    }
  }

  void Path::find_path()
  {
    dist_[source_] = 0;
    while (!queue_.empty())
    {
      int x = pop_min_dist();
      check_neighbors(x, x - 1);
      check_neighbors(x, x - sqrt(map_.size()));
      check_neighbors(x, x + 1);
      check_neighbors(x, x + sqrt(map_.size()));
    }
  }

  std::shared_ptr<std::vector<int>> Path::get_path(int x, int y) const
  {
    int cur = x + y * sqrt(map_.size());
    auto path = std::make_shared<std::vector<int>>(dist_[cur]);
    while (cur != source_)
    {
      path->insert(path->begin(), prev_[cur]);
      cur = prev_[cur];
    }
    return path;
  }
}
