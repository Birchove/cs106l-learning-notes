#include <ostream>
#include <string>

class Hero {
private:
    std::string name;
    int power;
    inline static int hero_count = 1;   // belongs to the class, rather than the object

public:
    Hero(std::string name, int power);
    std::string describe() const;

    bool operator < (const Hero& other) const;
    // operator overload, decalred in the class

    friend std::ostream& operator << (std::ostream& out, const Hero& hero);
    // friend func: non-member function, access to private
};