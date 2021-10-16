#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
#include <bitset>

using namespace std;

//find gcd
//euclids algorithm
int gcd(int x, int y) {
   int temp;
   while(1) {
        temp= x % y;
        if(temp==0){    //if x%y ==0, then y is the gcd
            return y;
        }
        x = y;
        y = temp;
   }
}

//check if is prime
bool checkPrime(int x){
    bool isPrime = true;
    //0 and 1 are not prime
    if(x == 0 || x == 1){
        isPrime = false;
    } else {
        for(int i = 2; i <= x/2; i++){   //check from 2 up to x/2,
            if(x % i == 0){              //whenever a remainder other than 0 is found, then x is not a prime
                isPrime = false;
                break;                   //get out of the loop
            }
        }
    }
    if(isPrime){
            cout << x << " is a prime number" << endl;

    } else{
            cout << x << " is not a prime number" << endl;
    }
    return isPrime;                 //return the boolean value
}


int squareMultiply(int a, int b, int n){
        int c = 0, d = 1;
        //first convert b to binary and find k
        bitset<32> x(b);
        string binary = x.to_string();  //conver the binary number to a string
        int first = binary.find('1');   //find first occureance of 1

        for(int i = first; i <= 31; i++){   //from first occrureance of 1 up to 31, go through the square multiply algorithm
            c = 2 * c;                      //instead of using k to 0, i use first to 31, this achieve the same result
            d = (d * d) % n;
            if(binary[i] == '1'){
                c = c+1;
                d = (d * a) %n;
            }
        }
        return d;
}

void rsa(int x){
    int action = x;
    cout << action << endl;
    bool flag;
    //input p and q, must be prime integer
    int p, q;
    do{
        cout << "input p, must be a prime integer\n";
        cin >> p;
        flag = checkPrime(p);
    } while (flag != true);

    do{
        cout << "input q, must be a prime integer\n";
        cin >> q;
        if( q == p){
            flag = false;
            cout << "q must be different from p" << endl;
        } else {
            flag = checkPrime(q);
        }
    } while (flag != true);

    cout << "\ninput for p and q done\np: " << p << " q: " << q << endl;
    //calculate n, n = p * q
    int n = p * q;
    cout << "n: " << n << endl;
    //calculate phi(n), phi = (p-1) * (q-1)
    int phi = (p-1) * (q-1);
    cout << "phi: " << phi << endl;

    //input e,  1 < e < phi(n) and gcd(e, phi(n) = 1. e and phi(n) are relative prime
    //gcd(e,phi) must be equal to 1
    flag = false;
    int e,temp;
    do{
        cout << "\ninput e, must be between 1 and " << phi << ", and also must be relatively prime with " << phi << ".\n";
        cin >> e;
        if(e < 1 || e > phi){
            cout << "e must be between 1 and " << phi<< endl;
            flag = false;
        } else {
            //check if gcd(e, phi) = 1
            temp = gcd(e, phi);
            if(temp == 1){
                flag = true;
                cout << "e: " << e << endl;
            }
        }
    } while (flag != true);

    //get input. check if integer
    int input;
    flag = false;
    do{
        if(x == 1){
            cout << "input message, must be a natural integer\n";
        } else{
            cout << "input ciphertext, must be a natural integer\n";

        }
        cin >> input;
        if(input >= 1){
            flag = true;
            if(x == 1){
                cout << "Message: " << input << endl;
            } else{
                cout << "Cipher: " << input << endl;
            }
        }
    } while (flag != true);

    //calculate d
    //de = 1 mod phi(n)
    //d = n+1/e
    int de;
    de = (phi + 1)/e;
    cout << "d: " << de << endl;

    int output;
    if(x == 1){
        output = squareMultiply(input,e,n);
        cout << "cipher: " << output << endl;
    } else{
        output = squareMultiply(input,de,n);
        cout << "Message: " << output << endl;
    }


    //finding d, using eculids algo, ed mod phi(n) = 1
    //or ed = 1 mod phi(n)

}

void rsaDecrypt(){

}

int main(){
    int action;

    do
    {
        cout << "\n========Welcome to RSA========\n\n"
             << "Input action to be taken\n"
             << "1: Encrypt\n"
             << "2: Decrypt\n"
             << "0: Quit\n"
             << endl;

        cin.clear();
        cin >> action;
        switch (action) {
            case 0:
                cout << "Exiting RSA..." << endl;
                break;
            case 1:
                cin.ignore();
                rsa(1);

                break;
            case 2:
                rsa(2);

                break;
            default:
                cout << "Invaild action" << endl;
                break;
        }

    }while (action != 0);


    return 0;

}


