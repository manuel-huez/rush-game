#ifndef PATH_H
# define PATH_H

# include <vector>
# include <set>
# include <memory>
namespace PATH
{
  class Path
  {
    public:
      Path(std::vector<int>& map, int source, int size)
        : source_(source)
        , map_(map)
        , size_(size)
      {
        std::vector<int> prev(map.size(), -1);
        prev_ = prev;
        std::vector<int> dist(map.size(), 100000);
        dist_ = dist;
        fill_heap();
      }
      std::shared_ptr<std::vector<int>> get_path(int x, int y) const;
      void find_path();
    private:
      void fill_heap();
      int pop_min_dist();
      void check_neighbors(unsigned x, unsigned n);
      int source_;
      std::set<int> queue_;
      std::vector<int>& map_;
      std::vector<int> prev_;
      std::vector<int> dist_;
      int size_;
  };
}

#endif
