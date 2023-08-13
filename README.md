# Pattern Matching Program

This program checks for the ocuurences of a pattern in a given text and writes the positions where the pattern is found to a 'patternmatch.output' file

## Prerequisites

- C++ Compiler(g++)
- Text and Pattern files pairs (eg :- text1.txt,pattern1.txt,text2.txt,pattern2.txt) for testing.
  
  ## Getting Started

  1. Clone this repository to your local machine.
   
  2. Navigate to the cloned directory.(Or else download the uploaded zip file and extract it and then compile the c++ source code using below mentioned code.)
    ``cd pattern-matching-program``

  3. Compile the program using g++ compiler
    ```g++ patternmatching.cpp -o patternmatching```

## Usage

1. Prepare your text and pattern files. Create text files named 'text1.txt', 'text2.txt', etc., and pattern files named 'pattern1.txt', 'pattern2.txt', etc. Place them in the same directory as the program.

2. Run the program by specifying the number of test cases.
   ```./patternmatching```

3. Follow the on-screen instructions to enter the number of test cases and see the pattern matching results.(If you have 'n' number of text-pattern pairs enter 'n' as the number of test cases.)

## Output

The program will generate output files named 'outputpatternmatch1.output', 'outputpatternmatch2.output', etc., for each test case. These files will contain information about the positions where the patterns were found in the corresponding text files.

General explanation of the code is provided in the 'explanation_of_code.txt' file.