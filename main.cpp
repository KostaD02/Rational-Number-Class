#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

unsigned int GCD(unsigned int a,unsigned int b){
    //GCD function will return GCD of two number
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a==b)
        return a;
    if(a>b)
        return GCD(a - b, b);
    return GCD(a, b - a);
}

class RationalNumber{
    private:
        int m; //numerator 
        unsigned int n; //denominator
    public:
        RationalNumber(int m=0,unsigned int n=1){
            set(m, n); //wraping it to set function to not spaming in constructor
        }
        void set(int m=0,unsigned int n=1){
            if(n==0){ //checking if denominator isn't equal to 0 , bcz we can't division number on zero
                cout << "Denominator can't be 0" << endl; //output for user , to know whats error
                exit(0); //since we can't return in void , we are using exit
            }
            int gcd = GCD(m,n); 
            this->n = n / gcd;
            this->m = m / gcd;
        }
        void Display(){ //displaying the number
            if(this->m==0){
                cout << "0"; 
            }
            else if (this->n == 1){
                cout << this->m;
            }
            else{
                cout << this->m << "/" << this->n;
            }
        }
        int getM(){ //taking m value from private 
            return this->m; 
        }
        unsigned int getN(){ //taking n value from private 
            return this->n;
        }
        double toFLoat(){ //changing number to float
            return 1.0 * this->m / this->n;
        }
    friend ostream& operator<<(ostream& output,const RationalNumber& Number){ //operator overload
        output << Number.m << "/" << Number.n;
        return output;
    }
    friend istream& operator>>(istream& input,RationalNumber& Number){ //operator overload
        cout << "Input numerator = ";
        input >> Number.m;
        cout << "Input denominator = ";
        input >> Number.n;
        return input;
    }
};

RationalNumber operator +(RationalNumber A,RationalNumber B){ 
    /*
        Option 1 where one of number numerator  is equal to 0
        imagine simple example : 0/2 + 1/3 = 1/3
        solve = 0 + 1/3 = 1/3
    */
    if(A.getM()==0 || B.getM()==0){
        if(A.getM()==0){
            return RationalNumber(B.getM(), B.getN());
        }else{
            return RationalNumber(A.getM(), A.getN());
        }
    }
    /*  
        Option 2 where number isn't equal to zero
        imagine simple example : 1/2 + 1/3 = 5/6 
        solve = (1*3+1*2)/(2*3) = 5/6
    */
    return RationalNumber(A.getM() * B.getN() + A.getN() * B.getM(), A.getN() * B.getN());
}

RationalNumber operator -(RationalNumber A,RationalNumber B){
    /*
        Option 1 where one of number numerator  is equal to 0
        imagine simple example : 0/2 - 1/3 = -1/3
        solve = 0 - 1/3 = -1/3
    */
    if(A.getM()==0 || B.getM()==0){
        if(A.getM()==0){
            return RationalNumber(-B.getM(), B.getN());
        }else{
            return RationalNumber(-A.getM(), A.getN());
        }
    }
    /*  
        Option 2 where number isn't equal to zero
        imagine simple example : 1/2 - 1/3 = 1/6 
        solve = (1*3-1*2)/(2*3) = 1/6
    */
    return RationalNumber(A.getM() * B.getN() - A.getN() * B.getM(), A.getN() * B.getN());
}

RationalNumber operator *(RationalNumber A,RationalNumber B){
    /*
        Option 1 where one of number numerator  is equal to 0
        imagine simple example : 0/2 * 1/3 = 0
        solve = 0 * 1/3 = 0
    */
    if(A.getM()==0 || B.getM()==0){
        if(A.getM()==0){
            return RationalNumber(0, B.getN());
        }else{
            return RationalNumber(0, A.getN());
        }
    }
    /*  
        Option 2 where number isn't equal to zero
        imagine simple example : 1/2 * 1/3 = 1/6 
        solve = (1*1)/(2*3) = 1/6
    */
    return RationalNumber(A.getM()*B.getM(),A.getN()*B.getN());
}

RationalNumber operator /(RationalNumber A,RationalNumber B){
    /*
        Option 1 where one of number numerator  is equal to 0
        imagine simple example : 0/2 * 1/3 = 0
        solve = 0 / 1/3 = 0
    */
    if(A.getM()==0 || B.getM()==0){
        if(A.getM()==0){
            return RationalNumber(0, B.getN());
        }else{
            return RationalNumber(0, A.getN());
        }
    }
    /*  
        Option 2 where number isn't equal to zero
        imagine simple example : 1/2 / 1/3 = 3/2 
        solve = (1*3)/(2*1) = 3/2
    */
    return RationalNumber(A.getM()*B.getN(),A.getN()*B.getM());
}

bool operator ==(RationalNumber A,RationalNumber B){
    //checking numerator  and denominator are same
    if(A.getM()==B.getM() && A.getN() == B.getN())
        return true;
    else
        return false;
}

bool operator !=(RationalNumber A,RationalNumber B){
    //according to the overloaded == we can simple check != equation
    if(A==B)
        return false;
    else
        return true; 
}

bool operator >(RationalNumber A,RationalNumber B){
    //according to the > operator we can simple check two number equation
    if(A.toFLoat()-B.toFLoat()>0)
        return true;
    else
        return false;
}

bool operator <(RationalNumber A,RationalNumber B){
    //according to the < operator we can simple check two number equation
    if(A.toFLoat()-B.toFLoat()<0)
        return true;
    else
        return false;
}

bool operator >=(RationalNumber A,RationalNumber B){
    /*  according to the == we can simple check firstly numbers are equal or not
        then checking first number is more or not 
        if above two statement wasn't true we are returning false
    */
    if(A==B)
        return true;
    else if(A>B)
        return true;
    else
        return false;
}

bool operator <=(RationalNumber A,RationalNumber B){
    /*  according to the == we can simple check firstly numbers are equal or not
        then checking second number is more or not 
        if above two statement wasn't true we are returning false
    */
    if(A==B)
        return true;
    else if(A<B)
        return true;
    else
        return false;
}

RationalNumber floatToRational(double number){
    ostringstream NumberString; 
    NumberString << number; 
    unsigned int pointPlace = 0; //start pointplace 0 index
    string Number = NumberString.str(); //changing number to string
    for (int i = 1; i <= Number.length();i++){
        if(Number[i]==char(46))
            pointPlace = i + 1; //finding point place
    }
    if(pointPlace == 0){ //if number doesn't have zero we are returning numerator=number and denominator = 1
        return RationalNumber(number, 1);
    }
    unsigned int zeroNumbers = Number.length() - pointPlace; //calculating how many zero do we need in denominator
    // cout << "Number = " << Number << endl; //testing
    // cout << "Length = " << Number.length() << endl; //testing
    // cout << "PointPlace = " << pointPlace << endl; //testing
    // cout << "Zero = " << zeroNumbers << endl; //testing 
    Number.erase(Number.begin()+pointPlace-1); //taking zero char from string 
    // cout << "String = "<< Number << endl; //testing 
    int numerator = stod(Number); //giving numerator value of string without zero character in double
    int denominator = pow(10, zeroNumbers); //giving denominator value
    return RationalNumber(numerator, denominator);
}

int main(int argc, char** argv) {
    int numerator = 0;cout << "Input first number numerator = ";cin >> numerator;
    unsigned int denominator = 1;cout << "Input first number denominator = ";cin >> denominator;
    RationalNumber A(numerator, denominator);
    numerator = 0;
    denominator = 1;
    cout << "Input second number numerator = ";cin >> numerator;
    cout << "Input second number denominator = ";cin >> denominator;
    RationalNumber B(numerator, denominator);
    cout << "First number = ";
    A.Display();
    cout << endl;
    cout << "Second number = ";
    B.Display();
    cout << endl;
    cout << "Some calculate :" << endl;
    cout << A << " + " << B << " = " << A + B << endl;
    cout << A << " - " << B << " = " << A - B << endl;
    cout << A << " * " << B << " = " << A * B << endl;
    cout << A << " / " << B << " = " << A / B << endl;
    cout << "Now compare numbers :" << endl;
    cout << "Is ";
    A.Display();
    cout << " bigger than ";
    B.Display();
    cout << " ? ";
    if(A>B)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << "Is ";
    A.Display();
    cout << " less than ";
    B.Display();
    cout << " ? ";
    if(A<B)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << "Is ";
    A.Display();
    cout << " equal to ";
    B.Display();
    cout <<" ? ";
    if(A==B)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    double Number = 0;cout << "Input double number : ";cin >> Number;
    RationalNumber FloatToRational = floatToRational(Number);
    cout << "Rational Number : ";
    FloatToRational.Display();
    cout << endl;
    return 0;
}