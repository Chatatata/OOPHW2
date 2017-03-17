
//  Buğra Ekuklu, 150120016

#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <stdexcept>

#include "DarkRed.hpp"
#include "Blue.hpp"
#include "Green.hpp"
#include "List.hpp"

int main(int argc, const char * argv[]) {
    try {
        std::ifstream file("deck.txt");
        std::string inputString;
        
        file.seekg(0, std::ios::end);
        inputString.reserve(file.tellg());
        file.seekg(0, std::ios::beg);
        
        inputString.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        
        std::cout << "PLAYERS: " << std::endl << inputString << std::endl;
        
        List<char> firstPlayer;
        List<char> secondPlayer;
        
        for (unsigned int i = 0; i < inputString.length() / 2; ++i) {
            if (i % 2 == 0) {
                firstPlayer.append(inputString[i]);
            } else if (inputString[i] != ' ') {
                throw std::runtime_error("Expected blankspace after card identifier.");
            }
        }
        
        for (unsigned long i = ((inputString.length() / 2) + 1); i < inputString.length(); ++i) {
            if (i % 2 == 0) {
                secondPlayer.append(inputString[i]);
            } else if (inputString[i] != ' ') {
                throw std::runtime_error("Expected blankspace after card identifier.");
            }
        }
        
        std::cout << "Score 1: ";
        
        List<GameResult> firstPlayerResult;
        
        for (unsigned int i = 0; i < firstPlayer.count(); ++i) {
            Base *challengersCard = nullptr;
            
            switch (firstPlayer[i]) {
                case 'R':
                    challengersCard = new Red();
                    break;
                    
                case 'D':
                    challengersCard = new DarkRed();
                    break;
                    
                case 'B':
                    challengersCard = new Blue();
                    break;
                    
                case 'G':
                    challengersCard = new Green();
                    break;
                    
                default:
                    throw std::runtime_error("Unknown card identifier.");
            }
            
            Base *opponentsCard = nullptr;
            
            switch (secondPlayer[i]) {
                case 'R':
                    opponentsCard = new Red();
                    break;
                    
                case 'D':
                    opponentsCard = new DarkRed();
                    break;
                    
                case 'B':
                    opponentsCard = new Blue();
                    break;
                    
                case 'G':
                    opponentsCard = new Green();
                    break;
                    
                default:
                    throw std::runtime_error("Unknown card identifier.");
            }
            
            firstPlayerResult.append(challengersCard->compare(*opponentsCard));
            
            std::cout << static_cast<unsigned int>(firstPlayerResult[firstPlayerResult.count() - 1]) << " ";
            
            delete challengersCard;
            delete opponentsCard;
        }
        
        std::cout << std::endl << "Score 2: ";
        
        List<GameResult> secondPlayerResult;
        
        for (unsigned int i = 0; i < firstPlayer.count(); ++i) {
            Base *challengersCard = nullptr;
            
            switch (secondPlayer[i]) {
                case 'R':
                    challengersCard = new Red();
                    break;
                    
                case 'D':
                    challengersCard = new DarkRed();
                    break;
                    
                case 'B':
                    challengersCard = new Blue();
                    break;
                    
                case 'G':
                    challengersCard = new Green();
                    break;
                    
                default:
                    throw std::runtime_error("Unknown card identifier.");
            }
            
            Base *opponentsCard = nullptr;
            
            switch (firstPlayer[i]) {
                case 'R':
                    opponentsCard = new Red();
                    break;
                    
                case 'D':
                    opponentsCard = new DarkRed();
                    break;
                    
                case 'B':
                    opponentsCard = new Blue();
                    break;
                    
                case 'G':
                    opponentsCard = new Green();
                    break;
                    
                default:
                    throw std::runtime_error("Unknown card identifier.");
            }
            
            secondPlayerResult.append(challengersCard->compare(*opponentsCard));
            
            std::cout << static_cast<unsigned int>(secondPlayerResult[secondPlayerResult.count() - 1]) << " ";
            
            delete challengersCard;
            delete opponentsCard;
        }
        
        std::cout << std::endl;
        
        unsigned int firstPlayerPoint = 0;
        unsigned int firstPlayerCounters[3] = {0};
        
        for (unsigned int i = 0; i < firstPlayerResult.count(); ++i) {
            firstPlayerPoint += static_cast<unsigned int>(firstPlayerResult[i]);
            
            firstPlayerCounters[static_cast<unsigned int>(firstPlayerResult[i])] += 1;
        }
        
        unsigned int secondPlayerPoint = 0;
        unsigned int secondPlayerCounters[3] = {0};
        
        for (unsigned int i = 0; i < secondPlayerResult.count(); ++i) {
            secondPlayerPoint += static_cast<unsigned int>(secondPlayerResult[i]);
            
            secondPlayerCounters[static_cast<unsigned int>(secondPlayerResult[i])] += 1;
        }
        
        std::cout << "Total score 1: Lose: " << firstPlayerCounters[0] << " Tie: " << firstPlayerCounters[1] << " Win: " << firstPlayerCounters[2] << std::endl
        << "Total score 2: Lose: " << secondPlayerCounters[0] << " Tie: " << secondPlayerCounters[1] << " Win: " << secondPlayerCounters[2] << std::endl;
        
        if (firstPlayerPoint > secondPlayerPoint) {
            std::cout << "Winner: Player1" << std::endl;
        } else if (firstPlayerPoint < secondPlayerPoint) {
            std::cout << "Winner: Player2" << std::endl;
        } else {
            std::cout << "Winner: Tie" << std::endl;
        }
        
        file.close();
    } catch (std::exception &err) {
        std::cout << "Error occurred: " << err.what() << std::endl;
    }
    
    return 0;
}
