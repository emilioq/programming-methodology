//Emilio Quiambao | 915372476 | emilioquiambao@gmail.com
//IDE: Code::Blocks
//CSC 340-01 | Assignment 1, Problem 1
//
//This program reads in a paragraph with a maximum of 100 words.
//It will give statistics of the paragraph:
// - the least frequent letter(s) and its frequency.
// - the frequency of each unique word.
// - the most frequent word.
//
/* ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ */

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct Word
{
    string word;
    int count;
};

vector<Word> collection;
int maxCount = 0;           //the count of the most freq word
int maxCountWordLoc;        //the location in the vector of the most freq word


bool isLessThan100 (string str)         //checks if paragraph is less than 100 words
{
    int count;
    char currentChar;

    for (unsigned int i=0; i < str.size(); i++)
    {
        currentChar = str[i];
        if (currentChar == ' ')         //when a space is spotted the count will increase
        {
            count++;
        }
    }
    return count<=100;                  //if the count reaches above 100, there is guaranteed to be over 100 words in the paragraph since there is over 100 spaces.
}

bool hasLetters(string str)             //checks if the paragraph has letters.
{
    int count = 0;
    if(str.find_first_of("abcdefghijklmnopqrstuvxyz") != string::npos)
    {
        count++;
    }

    return count > 0;
}

string replacePunctuation(string str)   //replaces punctuation and non-letters to spaces
{
    replace(str.begin(), str.end(), '.', ' ');
    replace(str.begin(), str.end(), ',', ' ');
    replace(str.begin(), str.end(), '!', ' ');
    replace(str.begin(), str.end(), '?', ' ');
    replace(str.begin(), str.end(), ';', ' ');

    replace(str.begin(), str.end(), '"', ' ');
    replace(str.begin(), str.end(), '@', ' ');
    replace(str.begin(), str.end(), '#', ' ');
    replace(str.begin(), str.end(), '$', ' ');
    replace(str.begin(), str.end(), '%', ' ');

    replace(str.begin(), str.end(), '^', ' ');
    replace(str.begin(), str.end(), '&', ' ');
    replace(str.begin(), str.end(), '*', ' ');
    replace(str.begin(), str.end(), ')', ' ');
    replace(str.begin(), str.end(), '(', ' ');

    replace(str.begin(), str.end(), '|', ' ');
    replace(str.begin(), str.end(), '\\', ' ');
    replace(str.begin(), str.end(), '/', ' ');
    replace(str.begin(), str.end(), '[', ' ');
    replace(str.begin(), str.end(), ']', ' ');

    replace(str.begin(), str.end(), '~', ' ');
    replace(str.begin(), str.end(), '1', ' ');
    replace(str.begin(), str.end(), '2', ' ');
    replace(str.begin(), str.end(), '3', ' ');
    replace(str.begin(), str.end(), '4', ' ');
    replace(str.begin(), str.end(), '5', ' ');
    replace(str.begin(), str.end(), '6', ' ');
    replace(str.begin(), str.end(), '7', ' ');
    replace(str.begin(), str.end(), '8', ' ');
    replace(str.begin(), str.end(), '9', ' ');
    replace(str.begin(), str.end(), '0', ' ');

    return str;
}

string lowercaseString(string str)      //makes the string all lowercase
{
    for(unsigned int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }

    return str;
}

void getLeastFreqLetter(string str)     //gets least frequent letter in the inputed paragraph
{
    int minCount = 0;
    char cArray[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int iArray[26] = { 0 };                         //this array keeps count of the frequency of letters

    for(unsigned int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if(str[i] == cArray[j])                 //If the current char i matches a char j in the string, the counter adds 1.
            {
                iArray[j]++;
            }
        }
    }

    for(int k = 0; k < 26; k++)
    {
        if ((minCount == 0) && (iArray[k] >= 1) || iArray[k] < minCount && iArray[k] >= 1)
        {
            minCount = iArray[k];                   //this loop tries to find the lowest count.
        }
    }

    for(int l = 0; l < 26; l++)
    {
        if(iArray[l] == minCount)
        {
            cout << cArray[l] << " ";               //once the lowest count is found, this loop prints out letters whose count is equal to the lowest count.
        }
    }
    cout << endl;
    cout << "Freq: " << minCount << endl << "\n";
}

void countWordFreq(string str)          //counts the frequency of words in the inputted paragraph
{
    vector<string> words;
    stringstream ss;
    ss << str;

    while (true)
    {
        string next_word;
        ss >> next_word;
                            //this loop stores words in a vector
        if (ss.fail())
        {
            break;
        }

        words.push_back(next_word);
    }

    for(unsigned int i = 0; i < words.size(); i++)
    {
        int count = 1;
        string currentWord = words[i];                      //if the current word is the same as another word,
        for(unsigned int j = i+1; j < words.size(); j++)    //the count for that word increases and the other word is destroyed.
        {
            if (currentWord == words[j])
            {
                count++;
                words.erase(words.begin()+j);
                j--;
            }
        }
        Word currentWordData;                               //the current word and its count is stored in a Word vector...
        currentWordData.word = currentWord;                 //the vector holds all words and their count.
        currentWordData.count = count;
        collection.push_back(currentWordData);
    }

    for(unsigned int i = 0; i < collection.size(); i++)     //then this loop goes through the vector and prints the data.
    {                                                       //at the same time, it finds the word with the most counts.
        cout << collection[i].word << endl;
        cout << "Freq: " << collection[i].count << endl << "\n";

        if (collection[i].count > maxCount)
        {
            maxCount = collection[i].count;
            maxCountWordLoc = i;
        }
    }
}

void getMostFreqWord()                  //prints most frequent word based on data received in countWordFreq
{
    cout << collection[maxCountWordLoc].word << endl;
    cout << "Freq: " << collection[maxCountWordLoc].count << endl << "\n";
}

int main()
{
    //User enters paragraph. Checks if its 100 words or less.
    string paragraph;
    int check = 0;
    while(check <= 1)
    {
        cout << "Enter a paragraph (100 words max) :  " << endl;
        getline(cin, paragraph);
        if(isLessThan100(paragraph))
        {
            check++;
        }
        else
        {
            check = 0;
            cout << "\n" << "Paragraph exceeds 100 words." << endl << "\n";
        }

        if(hasLetters(paragraph))
        {
            check++;
        }
        else
        {
            check = 0;
            cout << "\n" << "Paragraph has no letters." << endl << "\n";
        }

    }

    //prints LEAST FREQUENT LETTER(S)
    cout << "\n" <<"// Least frequent letter(s): " << endl << "\n";
    getLeastFreqLetter(lowercaseString(paragraph));
    cout << "___________________________________" << endl << "\n";

    //prints WORD FREQUENCY
    cout << "// Word Frequency: " << endl << "\n";
    countWordFreq(replacePunctuation(lowercaseString(paragraph)));
    cout << "___________________________________" << endl << "\n";

    //prints MOST FREQUENT WORD
    cout << "// Most frequent word: " << endl << "\n";
    getMostFreqWord();
    cout << "___________________________________" << endl << "\n";

    return 0;
}
