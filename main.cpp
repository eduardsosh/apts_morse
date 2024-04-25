#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>

using namespace std;

const int BUFFER_LENGHT = 7;

void populate_map(unordered_map<string, char> &umap) {
    string morseLetters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-.-.-","--..--","---...","..--..","-....-","-..-.",".----."};

    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0','1','2','3','4','5','6','7','8','9','.',',',':','?','-','/',' '};

    for (int i = 0; i < 43; ++i) {
        umap[morseLetters[i]] = alphabet[i];
    }
}



void solve(string infilename, string outfilename){
    ifstream infile;
    ofstream outfile;

    infile.open(infilename);
    outfile.open(outfilename);

    if(!infile.is_open() || !outfile.is_open()){
        cerr<<"Error opening file/s"<<endl;
        return;
    }

    unordered_map<string,char> morse_map;
    populate_map(morse_map);
    string code;

    string buffer;
    char c;
    int i = 0;

    while (infile.get(c)){
        buffer.push_back(c);
        if(buffer.back() == '|'){
            if(buffer.front() == '|'){
                buffer.clear();
                continue;
            }
            buffer.pop_back();

            auto it = morse_map.find(buffer);
            if(it == morse_map.end()){
                outfile<<"!";
            }else{
                outfile<< morse_map[buffer];
            }
            buffer.clear();
        }

    }   
    

    

}

int main(){
    solve("test_files/morse.i1","outputs/morse.o1");
    cout<< endl;
    cout<< endl;



    // if(!infile.is_open()){
    //     cerr<<"Error opening file";
    //     return;
    // }



    return 0;
}