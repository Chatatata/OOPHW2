
//  Buğra Ekuklu, 150120016

#ifndef BlueDeclaration
#define BlueDeclaration

#include "Base.hpp"

class Red;
class DarkRed;
class Green;

class Blue : public Base {
public:
    ~Blue() { }
    
    virtual GameResult compare(Base &opponent) override {
        return reverse(opponent.compare(*this));
    }
    
    virtual GameResult compare(DarkRed &opponent) override {
        return GameResult::Lose;
    }
    
    virtual GameResult compare(Red &opponent) override {
        return GameResult::Win;
    }
    
    virtual GameResult compare(Blue &opponent) override {
        return GameResult::Tie;
    }
    
    virtual GameResult compare(Green &opponent) override {
        return GameResult::Lose;
    }
};

#endif
