//
//  main.cpp
//  cipherOfVzhiner
//
//  Created by Alexander on 06/12/15.
//  Copyright © 2015 Alexander. All rights reserved.
//

#include <iostream>
#include "Vigenere.hpp"
#include "VigenereAnalyser.hpp"

int main()
{
    Vigenere scrambler("KEY");
    
    string original = "The Vigenère cipher is a method of encrypting alphabetic text by using a series of different Caesar ciphers based on the letters of a keyword";
    string encrypted = scrambler.encrypt(original);
    string decrypted = scrambler.decrypt(encrypted);
    
    cout << "Original: " <<original << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;
    
    array <double, 26> englishAlphabetfrequencies =
    {
        0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228,
        0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025,
        0.02406, 0.06749, 0.07507, 0.01929, 0.00095, 0.05987,
        0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150,
        0.01974, 0.00074
    };
 
    VigenereAnalyser decoder(englishAlphabetfrequencies);
    pair <string, string> output = decoder.analyze(encrypted);
 
    cout << "Key: " << output.second << endl;
    cout << "Text: " << output.first << endl;
 }
 