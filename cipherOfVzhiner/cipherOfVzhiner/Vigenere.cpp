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
    for(int numberOfCharacterInKey = 0; numberOfCharacterInKey < key.size(); ++numberOfCharacterInKey)
    {
        if (key[numberOfCharacterInKey] >= 'A' && key[numberOfCharacterInKey] <= 'Z')
        {
            this->key += key[numberOfCharacterInKey];
        }
        else if (key[numberOfCharacterInKey] >= 'a' && key[numberOfCharacterInKey] <= 'z')
        {
            this->key += key[numberOfCharacterInKey] + 'A' - 'a';
        }
    }
}

string Vigenere:: encrypt(string text)
{
    char character;
    string encryptedString;
    int numberOfCharacterInKey = 0;
    
    for(int numberOfCharacterInText = 0; numberOfCharacterInText < text.length(); ++numberOfCharacterInText)
    {
        character = text[numberOfCharacterInText];
        if(character >= 'a' && character <= 'z')
        {
            character += 'A' - 'a';
        }
        else if((character < 'A' || character > 'Z') && character != ' ')
        {
            continue;
        }
        if (character == ' ')
        {
            encryptedString += character;
        }
        else
        {
            encryptedString += (character + key[numberOfCharacterInKey] - 2*'A') % 26 + 'A';
            numberOfCharacterInKey = (numberOfCharacterInKey + 1) % key.length();
        }
    }
    
    return encryptedString;
}

string Vigenere:: decrypt(string text)
{
    char character;
    string decryptedString;
    int numberOfCharacterInKey = 0;
    
    for(int numberOfCharacterInText = 0; numberOfCharacterInText < text.length(); ++numberOfCharacterInText)
    {
        character = text[numberOfCharacterInText];
        if(character >= 'a' && character <= 'z')
        {
            character += 'A' - 'a';
        }
        else if((character < 'A' || character > 'Z') && character != ' ')
        {
            continue;
        }
        if (character == ' ')
        {
            decryptedString += character;
        }
        else
        {
            decryptedString += (character - key[numberOfCharacterInKey] + 26) % 26 + 'A';
            numberOfCharacterInKey = (numberOfCharacterInKey + 1) % key.length();
        }
    }
    
    return decryptedString;
}
