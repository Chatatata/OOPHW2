
//  Buğra Ekuklu, 150120016

#ifndef GreenDeclaration
#define GreenDeclaration

#include "Base.hpp"

class DarkRed;
class Red;
class Blue;

class Green : public Base {
public:
    ~Green() { }
    
    virtual GameResult compare(Base &opponent) override {
        return reverse(opponent.compare(*this));
    }
    
    virtual GameResult compare(DarkRed &opponent) override {
        return GameResult::Win;
    }
    
    virtual GameResult compare(Red &opponent) override {
        return GameResult::Lose;
    }
    
    virtual GameResult compare(Blue &opponent) override {
        return GameResult::Win;
    }
    
    virtual GameResult compare(Green &opponent) override {
        return GameResult::Tie;
    }
};

#endif /* GreenDeclaration */
