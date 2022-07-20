/*

Program Name: Complex number calculator
Author 1: Sohaila Abdelazim Khalifa
Author 2: Mariam Ayman Taha
Author 3: Abdelrhman Mohamed Ezzat
 */
#include <bits/stdc++.h>
using namespace std;

bool is_valid(string& str);
void parse_complex(string& str, float& r, float& img);
void addition(float& r1,float& img1,float& r2,float& img2);
void subtraction(float& r1,float& img1,float& r2,float& img2);
void multiplication(string& s1, string& s2, float& r1, float& img1, float& r2, float& img2);
void Division(string& s1, string& s2, string str, float& r1, float& img1, float& r2, float& img2, float r, float img);
string Conjugate(string s2);

int main(){
    string str1,str2;
    float r1,r2,img1,img2;
    cout << "______Welcome to Complex Number Calculator______" << endl;
    int operation = 0;
    while(operation != 5){ // Program Loop
        cout << "Dear user which operation would you like to do : " << endl ;
        cout << "1- Addition " << endl << "2- Subtraction" << endl;
        cout << "3- Multiplication" << endl << "4- Division" << endl << "5- Exit" << endl;
        cin >> operation;

        while (operation > 5 || cin.fail()){ // Defensive to make sure the user enter a valid number
            cout << "please enter a valid number\n";
            cin >> operation;
        }

        if(operation == 5){ // Break from the loop if the user enters 5
            break;
        }

        cin.ignore();
        cout << "Please enter the first complex number in the format '(n1+n2i)' : " << endl;
        getline(cin,str1,'\n');
        while(!is_valid(str1)){ // To make sure that the user entered this formula (n1+n2i)
            cout << "Please enter the first complex number in the format '(n1+n2i)' : " << endl;
            getline(cin,str1,'\n');
        }

        cout << "Please enter the second complex number in the format '(n1+n2i)' : " << endl;
        getline(cin,str2,'\n');
        while(!is_valid(str2)){ // To make sure that the user entered this formula (n1+n2i)
            cout << "Please enter the second complex number in the format '(n1+n2i)' : " << endl;
            getline(cin,str2,'\n');
        }

        parse_complex(str1,r1,img1);
        parse_complex(str2,r2,img2);
        // Function to parse this formula "(n1+n2i)" to its components
        if (operation == 1){
            addition(r1,img1,r2,img2);
            // Addition Function
        }
        else if (operation == 2){
            subtraction(r1,img1,r2,img2);
            // Subtraction Function
        }
        else if (operation == 3){
            multiplication(str1, str2, r1, img1, r2, img2);
            // Multiplication Function
        }
        else if(operation == 4){
            string str = Conjugate(str2); // Function which return the conjugate of str2 as a string
            int p_plus = str.find('+'); // To find the index of the + sign if exists
            int p_minus = str.find('-', 2); // To find the index of the - sign if exists
            int p_img = str.find('i'); // To find the index of the i in the string
            int p_sign = max(p_plus, p_minus); // To know which sign exists and put it in another variable
            float r = stof(str.substr(1, p_sign)); // To get the real value from the string
            float img = stof(str.substr(p_sign, p_img)); // To get the imaginary part from the string
            Division(str1, str2, str, r1, img1, r2, img2, r, img);
            // Division Function
        }
        cout << endl << ("_________________________________") << endl;
    }
    cout << "Program End";
    return 0;
}

bool is_valid(string& str){ // Function to make sure that the user entered "(n1+n2i)" in this format
    regex formula("[(][-]?[0-9]+(.[0-9]+)?[+-][0-9]+(.[0-9]+)?[i][)]");
    return regex_match(str,formula); // Return true if the string matches the formula and false otherwise
}

void parse_complex(string& str, float& r, float& img){
    // Function to know the index of + , - , i , and to know which sign exists and get real part and imaginary part
    int p_plus = str.find('+');
    int p_minus = str.find('-', 2);
    int p_img = str.find('i');
    int p_sign = max(p_plus, p_minus);
    r = stof(str.substr(1, p_sign));
    img = stof(str.substr(p_sign, p_img));
}
void addition(float& r1,float& img1,float& r2,float& img2) {
    // Add the real part with the real part and imaginary part with imaginary part
    if (img1 + img2 > 0){
        cout << "Result: " << "(" << r1 + r2 << '+' << img1 + img2 << "i)\n";
    }
    else if (img1 + img2 < 0){
        cout << "Result: " << "(" << r1 + r2 <<  img1 + img2 << "i)\n";
    }
    else{
        cout << "Result: " << r1 + r2 << endl;
    }
}
void subtraction(float& r1,float& img1,float& r2,float& img2){
    // Subtract the real part from the real part and imaginary part from imaginary part
    if (img1 - img2 > 0){
        cout << "Result: " << "(" << r1 - r2 << '+' << img1 - img2 << "i)\n";
    }
    else if (img1 - img2 < 0){
        cout << "Result: " << "(" << r1 - r2 << img1 - img2 << "i)\n";
    }
    else{
        cout << "Result: " << r1 - r2 << endl;
    }
}
void multiplication(string& s1, string& s2, float& r1, float& img1, float& r2, float& img2){
    // Multiplication Function
    float real_part, imaginary_part;
    real_part = (r1 * r2) + (img1 * img2 * (-1));
    imaginary_part = (r1 * img2) + (r2 * img1);
    if (imaginary_part > 0) {
        cout << "Result = " << "(" << real_part << "+" <<  imaginary_part << 'i' << ")";
    } else if(imaginary_part < 0){
        cout << "Result = " << "(" << real_part << "-" << abs(imaginary_part) << 'i' << ")";
    }
    else {
        cout << real_part << endl;
    }
}
string Conjugate(string s){ // Returns the conjugate of the string to use in Division function
    string str;
    int p_plus = s.find('+');
    int p_minus = s.find('-', 2);
    if(p_plus > p_minus){
        str += s.substr(0, p_plus);
        str += "-";
        str += s.substr(p_plus+1, s.length());
    }
    else{
        str += s.substr(0, p_minus);
        str += "+";
        str += s.substr(p_minus+1, s.length());
    }
    return str;
}
void Division(string& s1, string& s2, string str, float& r1, float& img1, float& r2, float& img2, float r, float img){
    // Division Function
    multiplication(s1, str, r1, img1, r, img);
    cout << " " << "/ ";
    multiplication(s2, str, r2, img2, r, img);
}
