#include<iostream>
#include<iomanip>

struct Fraction{
    int num;
    int  denum;

    void affiche(){
        std::cout<<"Fraction= "<<num<<"/"<<denum<<std::endl;
    }

    double valeurApprochee(){
        return double(num)/denum;
    }

    Fraction opposee(){
        Fraction fractionopposee;
        fractionopposee.num = -num;
        fractionopposee.denum = denum;
        return fractionopposee;
    }

    Fraction inverse(){
        Fraction fractionInverse;
        fractionInverse.num = denum;
        fractionInverse.denum = num;
        return fractionInverse;
    }

    Fraction multiplier(Fraction autreFraction){
        Fraction resultatMultiplier;
        resultatMultiplier.num = num*autreFraction.num;
        resultatMultiplier.denum = denum*autreFraction.denum;
        return resultatMultiplier;
    }
    Fraction division(Fraction autreFraction){
        Fraction resultatDivision;
        resultatDivision = (*this).multiplier(autreFraction.inverse());
        return resultatDivision;

    }
};

int main(){
    Fraction f1, f2, f3, f4,f5,f6;
    
    std::cout<<"Donner deux entiers svp"<<std::endl;
    std::cin>>f1.num>>f1.denum;

    f3 = f1.opposee();
    f4 = f1.inverse();

    //std::cout<<"Fraction="<<f1.num<<"/"<<f1.denum<<std::endl;
    std::cout<<"La fraction saisie est \t"<<f1.num<<"/"<<f1.denum<<std::endl;
    std::cout<<"Sa valeur approchée est \t"<<std::setprecision(4)<<f1.valeurApprochee()<<std::endl;
    std::cout<<" Son  opposée est \t"<<f3.num<<"/"<<f3.denum<<std::endl;
    std::cout<<" L'inverse de la fraction est \t"<<f4.num<<"/"<<f4.denum<<std::endl;

    std::cout<<" Pour une nouvelle fraction donner deux autres entiers svp"<<std::endl;
    std::cin>>f5.num>>f5.denum;
    std::cout<<"La fraction saisie est \t"<<f5.num<<"/"<<f5.denum<<std::endl;
    std::cout<<"Le produit des deux fractions  est \t"<<f1.num*f5.num<<"/"<<f1.denum*f5.denum<<std::endl;
    std::cout<<"Le quotient des deux fractions  est \t"<<f1.num*f5.denum<<"/"<<f1.denum*f5.num<<std::endl;
    return 0;
}
