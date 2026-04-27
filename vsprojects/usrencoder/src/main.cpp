#include <iostream>
#include <string>
#include <vector>
#include <random>

class RotatingText {
private:
    std::vector<std::string> charBank;

public:

    std::string userName;

    RotatingText() {
        charBank = { "a","b","c","d","e","f","g","h","i","j",
                     "k","l","m","n","o","p","q","r","s","t",
                     "u","v","w","x","y","z","1","2","3","4",
                     "5","6","7","8","9","!","@","#","$","%",
                     "^","&","*","(",")","-","=","+","/", "~" };

    }

    int randomShift() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, charBank.size()-1);
        return dist(gen);
    }

    void getUserName() {
        std::cout << "Please input username to be encoded: ";
        std::getline(std::cin, userName);
    }

    std::string rotateCharacters(int randomShift) {
        std::string encoded;
        
        for (char c : userName) {
            std::string charStr(1, c);
            
            // Find current position
            int currentPos = -1;
            for (int i = 0; i < charBank.size(); i++) {
                if (charBank[i] == charStr) {
                    currentPos = i;
                    break;
                }
            }
            
            
            if (currentPos != -1) {
                int newPos = (currentPos + randomShift) % charBank.size();
                encoded += charBank[newPos];
            } else {
                encoded += c;
            }
        }
        return encoded;
    }
};


int main() {
    RotatingText encoder;
    encoder.getUserName();
    
    int shift = encoder.randomShift();
    std::string encoded = encoder.rotateCharacters(shift);
    std::cout << "\nOriginal Username: " << encoder.userName << std::endl;
    std::cout << "Encoded Username:  " << encoded << std::endl;
    
    return 0;
}