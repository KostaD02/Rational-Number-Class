#include <iostream>

using namespace std;

class RationalNumber{
    private:
        int m; //integer
        unsigned int n; //denominator
    public:
        RationalNumber(int m=0,unsigned int n=1){
            set(m, n);
        }
        void set(int m=0,unsigned int n=1){
            this->m = m;
            if(n!=0){
                this->n = n;
            }else{
                cout << "Denominator can't be 0" << endl;
                exit(0);
            }
        }
        void Display(){
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
        int getM(){
            return this->m;
        }
        unsigned int getN(){
            return this->n;
        }
};

RationalNumber operator +(RationalNumber A,RationalNumber B){
    /*
        Option 1 where one of number integer is equal to 0
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
        Option 1 where one of number integer is equal to 0
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


int main(int argc, char** argv) {
    RationalNumber A(1,2);
    A.Display();
    cout << endl;
    RationalNumber B(3, 3);
    B.Display();
    cout << endl;
    RationalNumber C;
    C = A + B;
    C.Display();
    cout << endl;
    C = A - B;
    C.Display();
    return 0;
}