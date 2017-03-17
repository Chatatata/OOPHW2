
//  Buğra Ekuklu, 150120016

#ifndef BaseDeclaration
#define BaseDeclaration

enum class GameResult : unsigned int {
    Lose = 0,
    Tie = 1,
    Win = 2,
};

GameResult reverse(GameResult result) {
    switch (result) {
        case GameResult::Lose:
            return GameResult::Win;
        case GameResult::Tie:
            return GameResult::Tie;
        case GameResult::Win:
            return GameResult::Lose;
    }
}
    
class Red;
class DarkRed;
class Blue;
class Green;

class Base {
public:
    virtual ~Base() { }
    
    virtual GameResult compare(Base &opponent) = 0;
    virtual GameResult compare(Red &opponent) = 0;
    virtual GameResult compare(DarkRed &opponent) = 0;
    virtual GameResult compare(Blue &opponent) = 0;
    virtual GameResult compare(Green &opponent) = 0;
};

#endif