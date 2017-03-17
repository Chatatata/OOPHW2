
//  Buğra Ekuklu, 150120016

#ifndef RedDeclaration
#define RedDeclaration

#include "Base.hpp"

class DarkRed;
class Blue;
class Green;

class Red : public Base {
public:
    virtual ~Red() {}
    
    virtual GameResult compare(DarkRed &opponent) override {
        return GameResult::Lose;
    }
    
    virtual GameResult compare(Red &opponent) override {
        return GameResult::Tie;
    }
    
    virtual GameResult compare(Blue &opponent) override {
        return GameResult::Lose;
    }
    
    virtual GameResult compare(Green &opponent) override {
        return GameResult::Win;
    }
    
    virtual GameResult compare(Base &opponent) override {
        return reverse(opponent.compare(*this));
    }
};

#endif
