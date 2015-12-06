//
//  Vigenere.hpp
//  cipherOfVzhiner
//
//  Created by Alexander on 06/12/15.
//  Copyright © 2015 Alexander. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Vigenere
{
    private:
        string key;
    
    public:
        Vigenere (string key);
        string encrypt(string text);
        string decrypt(string text);
};
