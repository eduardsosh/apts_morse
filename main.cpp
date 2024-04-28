#include<iostream>
#include<fstream>


using namespace std;

const int BUFFER_LENGHT = 7;

// Endoce morse charecters by lenght and in 0/1 '.'=0  '-'=1
class Morsemap{
    char charmap1[2] = {'E','T'};
    char charmap2[4] = {'I','A','N','M'};
    char charmap3[8] = {'S','U','R','W','D','K','G','O'};
    char charmap4[16] = {'H','V','F',0,'L',0,'P','J','B','X','C','Y','Z',0,0,0};
    char charmap5[32] = {};
    char charmap6[64] = {};
    
    public:
    Morsemap(){
        charmap5[31] = '0';
        charmap5[15] = '1';
        charmap5[7] = '2';
        charmap5[3] = '3';
        charmap5[1] = '4';
        charmap5[0] = '5';
        charmap5[16] = '6';
        charmap5[24] = '7';
        charmap5[28] = '8';
        charmap5[30] = '9';

        charmap6[21] = '.';
        charmap6[51] = ',';
        charmap6[56] = ':';
        charmap6[12] = '?';
        charmap6[33] = '-';
        charmap6[18] = '/';
        charmap6[30] = ' ';
        //charmap6[63] = 0;

    }

    char get_char(int encoded,int lenght){
        switch (lenght)
        {
        case 1:
            return charmap1[encoded];
        case 2:
            return charmap2[encoded];
        case 3: 
            return charmap3[encoded];
        case 4:
            return charmap4[encoded];
        case 5: 
            return charmap5[encoded];
        case 6:
            return charmap6[encoded];
        default:
            return 0;
        }
    }
};

void printCharInBinary(char c) {
    // Iterate through each bit of the char
    for (int i = 7; i >= 0; --i) {
        // Use bitwise AND with 1 to check the value of the current bit
        std::cout << ((c >> i) & 1);
    }
    std::cout << std::endl;
}

void printNumberInBinary(int num) {
    // Iterate through each bit of the number
    for (int i = sizeof(num) * 8 - 1; i >= 0; --i) {
        // Use bitwise AND with 1 to check the value of the current bit
        std::cout << ((num >> i) & 1);
    }
    std::cout << std::endl;
}


void solve(char* infilename, char* outfilename){
    ifstream infile;
    ofstream outfile;

    infile.open(infilename);
    outfile.open(outfilename);

    if(!infile.is_open() || !outfile.is_open()){
        cerr<<"Error opening file/s"<<endl;
        return;
    }

    Morsemap map;
    char c;
    char outc = 0;
    int buffsize = 0;
    int buffer = 0;

    // MAIN LOOP
    // if not 

    while (infile.get(c)){

        if(c == '|' && buffsize == 0){
            continue;
        }
        if(c == '|' && buffsize < 7){
            outc = map.get_char(buffer, buffsize);

            if(outc == '\0'){
                outfile<<'!';
            }else{
                outfile<<outc;
            }

            buffsize = 0;
            buffer = 0;
            continue;
        }
        if(c == '|' && buffsize > 6){
            outfile<<'!';
            buffer = 0;
            buffsize = 0;
        }


        

        //Check if it exceeds max size and fix...

        // Shift position left therefore new bit is just 0
        if(c == '.'){
            buffer = buffer << 1;
            buffsize++;
            continue;
        }
        // Shift left and make first bit 1 
        if(c == '-'){
            buffer = buffer << 1;
            buffer |= 1;
            buffsize++;
            continue;
        }
        
    }

    if(buffer){
        outfile<<'!';
    }


    outfile<<endl;
    outfile.close();
    infile.close();   
    

    

}

int main(){
    solve("test_files/morse.i1","outputs/morse.o1");
    solve("test_files/morse.i2","outputs/morse.o2");
    solve("test_files/morse.i3","outputs/morse.o3");
    solve("test_files/morse.i4","outputs/morse.o4");
    solve("test_files/morse.i5","outputs/morse.o5");
    solve("test_files/morse.i6","outputs/morse.o6");
    solve("test_files/morse.i7","outputs/morse.o7");
    solve("test_files/morse.i8","outputs/morse.o8");
    solve("test_files/morse.i9","outputs/morse.o9");
    solve("test_files/morse.i10","outputs/morse.o10");
    solve("test_files/morse.i11","outputs/morse.o11");

    cout<< endl;
    cout<< endl;



    // if(!infile.is_open()){
    //     cerr<<"Error opening file";
    //     return;
    // }



    return 0;
}