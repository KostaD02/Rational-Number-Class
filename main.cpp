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
            }else{
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

int main(int argc, char** argv) {
    RationalNumber A(2,3);
    A.Display();
    cout << endl;
    RationalNumber B(0, 4);
    B.Display();
    cout << endl;
    RationalNumber C(1, 0);
    C.Display();
    return 0;
}