
class Widget {
  public:
    Widget();       // default constructor
    Widget (const Widget& w) = delete;  // copy constructor(disabled)
    Widget& operator = (const Widget& w) = delete;   // copy assignment constructor (disabled)
    ~Widget();         // destructor
    Widget (Widget&& rhs) noexcept ;        // move constructor
    Widget& operator = (Widget&& rhs) noexcept ;    // move assignment constructor
    // no except: 不会抛出异常
};

// 可以看到, assignment 函数是拥有返回类型的, 但是非赋值的smf是不需要返回值的