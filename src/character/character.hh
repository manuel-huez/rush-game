namespace P
{
  class Character
  {
    public:
      Character(int level)
        : level_(level);
      {}
      virtual void start() = 0;
      virtual void update() = 0;
      virtual void die() = 0;
    protected:
      int level_;
  };
}
