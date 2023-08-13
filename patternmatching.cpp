#include <iostream>
#include <fstream>
#include <string>

void find_pattern(std::ifstream& text_file,std::ifstream& pattern_file,int outputfile_number);

bool matchPattern(const std::string& text, int textPos, const std::string& pattern, int patternPos);

int main(){
    //Get the user input for the number of text-pattern pairs.
    std::cout<<"The number of test cases :- ";
    int number_of_test_cases;
    std::cin>>number_of_test_cases;

    //This for loop checks whether a pattern can be found in the corresponding textfile
    for(int i=1;i<=number_of_test_cases;i++){
        
        //open the texti.txt file where i can be any value between 1 & number_of_test_cases
        std::ifstream text_file("Text/text"+std::to_string(i)+".txt");
        if(!text_file.is_open()){
            std::cerr<<"Error opening the file text" << i << ".txt" << std::endl;
            continue;
        }

        //open the patterni.txt file where i can be any value between 1 & number_of_test_cases
        std::ifstream pattern_file("Pattern/pattern"+std::to_string(i)+".txt");
        if(!pattern_file.is_open()){
            std::cerr<<"Error opening the file pattern" << i << ".txt" << std::endl;
            continue;
        }

        /*for each text file & pattern file pair, find_pattern() function is called
        which creates a output file that consists of all occurences of pattern found in text file.*/
        find_pattern(text_file,pattern_file,i);
        text_file.close(); 
        pattern_file.close();
    }
    return 0;
}

//This function is used to traverse each line of text and check whether pattern can be found.
void find_pattern(std::ifstream& text_file, std::ifstream& pattern_file, int outputfile_number) {
    std::string pattern;
    /*Here I have assumed that pattern doesn't span across lines.
    If it does, using a while loop we need to read whole pattern.
    But since it is not practical for a pattern to span through several lines I have not used a while loop*/
    std::getline(pattern_file, pattern);

    std::string line;
    std:: string text;
    int line_number = 1;//Used to track the line number of text file.

    std::ofstream outputFile("Output/outputpatternmatch"+std::to_string(outputfile_number)+".output");
    if(!outputFile.is_open()){
        std::cerr<<"Error opening/creating patternmatch" << outputfile_number << ".output file." << std::endl;
        return;
    }

    bool pattern_found = false;

    //read the entire text file including newline character into the variable text
    while (std::getline(text_file, line)) {
        text += line + '\n';
    }
        /*This for loop simply slides pattern along text and check 
        whether pattern can be found at each index of the text*/
        for (int i = 0; i < text.length(); i++) {
            if (matchPattern(text, i, pattern, 0)) {

                //calculating line number and position based on the current index
                int position = i;
                for(int j=0;j<i;j++){
                    if(text[j] == '\n'){
                        line_number++;
                        position = i-j-1;//index within the line. Index of the first character of each line in the text is taken as '0'.
                    }
                }

                std::cout << "Pattern found at line " << line_number << ", position " << position << std::endl;
                outputFile << "Pattern found at line " << line_number << ", position " << position << std::endl;
                pattern_found = true;
            }
        }
    if(!pattern_found){
        outputFile << "Pattern Not Found." << std::endl;
    }

    outputFile.close();
}

bool matchPattern(const std::string& text, int textpos, const std::string& pattern, int patternpos){

    //Pattern is found if all characters of the pattern are matched.
    if(patternpos == pattern.length()){
        return true;
    }

    //Searching across lines. Newline character is considered as a space
    else if(text[textpos] == '\n' && pattern[patternpos] == ' '){
        return matchPattern(text,textpos+1,pattern,patternpos+1);
    }

    //Exact character matching or wildcard.
    else if(textpos <text.length() && (text[textpos] == pattern[patternpos] || pattern[patternpos] == '.')){
        return matchPattern(text,textpos+1,pattern,patternpos+1);
    }

    //Optional Character '?'
    else if(patternpos+1<pattern.length() && pattern[patternpos+1] == '?'){
        return matchPattern(text,textpos,pattern,patternpos+2);
    }
    
    else if(pattern[patternpos] == '^' && patternpos==0){
        return textpos == 0 && matchPattern(text,textpos,pattern,patternpos+1);
    }
    
    else if(pattern[patternpos] == '$' && patternpos == pattern.length()-1 && text[textpos]== '\n'){
        return true;
    }

    return false;
}


