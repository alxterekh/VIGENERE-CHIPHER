//
//  VigenereAnalyser.hpp
//  cipherOfVzhiner
//
//  Created by Alexander on 06/12/15.
//  Copyright © 2015 Alexander. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <array>

using namespace std;

typedef array <pair <char, double>, 26> frequencies;

class VigenereAnalyser
{
    private:
        array <double, 26> targets;
        array <double, 26> sortedTargets;
        frequencies freq;
    
        frequencies& frequency(const string& input);
        double correlation(const string& input);
        string leadToUppercase(string input);
    
    public:
        VigenereAnalyser(const array <double, 26> &targetFreqs);
        pair <string, string> analyze(string input);
};
