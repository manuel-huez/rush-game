namespace P
{
  class Pnj : public Character
  {
    public:
      Pnj(int level)
        : level_(level)
      {}
      virtual void start();
      virtual void update();
      virtual void die();
  };
}
