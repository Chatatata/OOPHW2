
//  Buğra Ekuklu, 150120016

#ifndef DarkRedDeclaration
#define DarkRedDeclaration

#include "Red.hpp"

class Red;
class Blue;
class Green;

class DarkRed : public Red {
public:
    ~DarkRed() { }
    
    virtual GameResult compare(DarkRed &opponent) override {
        return GameResult::Tie;
    }
    
    virtual GameResult compare(Red &opponent) override {
        return GameResult::Win;
    }
    
    virtual GameResult compare(Blue &opponent) override {
        return GameResult::Win;
    }
    
    virtual GameResult compare(Green &opponent) override {
        return GameResult::Lose;
    }
    
    virtual GameResult compare(Base &opponent) override {
        return reverse(opponent.compare(*this));
    }
};

#endif
