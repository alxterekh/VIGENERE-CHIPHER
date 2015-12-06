//
//  Vigenere.cpp
//  cipherOfVzhiner
//
//  Created by Alexander on 06/12/15.
//  Copyright © 2015 Alexander. All rights reserved.
//

#include "Vigenere.hpp"

Vigenere:: Vigenere (string key)
{
    for(int i = 0; i < key.size(); ++i)
    {
        if (key[i] >= 'A' && key[i] <= 'Z')
        {
            this->key += key[i];
        }
        else if (key[i] >= 'a' && key[i] <= 'z')
        {
            this->key += key[i] + 'A' - 'a';
        }
    }
}

string Vigenere:: encrypt(string text)
{
    string out;
    int j = 0;
    for(int i = 0; i < text.length(); ++i)
    {
        char c = text[i];
        
        if(c >= 'a' && c <= 'z')
        {
            c += 'A' - 'a';
        }
        else if(c < 'A' || c > 'Z')
        {
            continue;
        }
        out += (c + key[j] - 2*'A') % 26 + 'A';
        j = (j + 1) % key.length();
    }
    
    return out;
}

string Vigenere:: decrypt(string text)
{
    string out;
    int j = 0;
    for(int i = 0; i < text.length(); ++i)
    {
        char c = text[i];
        
        if(c >= 'a' && c <= 'z')
        {
            c += 'A' - 'a';
        }
        else if(c < 'A' || c > 'Z')
        {
            continue;
        }
        
        out += (c - key[j] + 26) % 26 + 'A';
        j = (j + 1) % key.length();
    }
    
    return out;
}
