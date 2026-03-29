#include <concepts> 
#include <iostream> 
#include <numeric> 

template<typename I> 
    requires std::integral<I>
class rational
{
    /*Numeratore e denominatore della frazione. Sono privati per evitare modifiche dirette dall'esterno*/
    I num_;
    I den_; 

    /*funzione interna che semplifica la frazione dividendo numeratore e denominatore per il loro massimo comune divisore (gcd)*/
    void simplify()
    {
        if (den_ == 0) return;

        I g = std::gcd(num_,den_);
        num_ /= g;
        den_ /=g;

        if (den_<0)
        {
            num_=-num_;
            den_=-den_;
        }
    }      

public:
    /*Costruttore di default. Inizializza il numero razionale a 0/1*/
    rational()
        :num_(0),den_(1)
    {}
    /*Costruttore user-defined*/
    rational(I n, I d) 
        : num_(n),den_(d)
    {
        if (d != 0)       
            simplify();    /*se il denominatore è diverso da zero la frazione viene automaticamente semplicifata*/
    }
    
    /*Restituisco i valori di num e den senza modificarli*/
    I num() const { return num_; }
    I den() const { return den_; }

    /*Implementazione la somma la somma tra due numeri razionali modificando direttamente l'oggetto corrente.
    a/b + c/d = (ad + bc)/bd*/
    rational& operator+=(const rational& other) {
        num_ = num_ * other.den_ + other.num_ * den_;
        den_ = den_ * other.den_;
        simplify();
        return *this;
    }
    
    /*implementazione canonica: crea una copia dell'oggetto, applica += e restituisce il risultato*/
    rational operator+(const rational& other) const
    {
        rational ret = *this;
        ret += other;
        return ret;
    }

    /*implementazione la sottrazione tra due numeri razionili.
    a/b - c/d = (ad - bc)/bd*/
    rational& operator-=(const rational& other) 
    {
        num_ = num_ * other.den_ - other.num_ * den_;
        den_ = den_ * other.den_;
        simplify();
        return *this;
    }

    /*implementazione canonica: crea una copia dell'oggetto, applica -= e restituisce il risultato*/
    rational operator-(const rational& other) const
    {
        rational ret = *this;
        ret -= other;
        return ret;
    }
   
    /*implementazione del prodotto
    a/b * c/d = ac/bd*/
    rational& operator*=(const rational& other) 
    {
        num_ *= other.num_;
        den_ *= other.den_;
        simplify();
        return *this;
    }
    
    /*implementazione canonica: crea una copia dell'oggetto, applica *= e restituisce il risultato*/
    rational operator*(const rational& other) const 
    {
        rational ret = *this;
        ret *= other;
        return ret;
    }

    /*implementazione della divisione
    a/b / c/d = ad/bc*/
    rational& operator/=(const rational& other) 
    {
        num_ *= other.den_;
        den_ *= other.num_;
        simplify();
        return *this;
    }
    /*implementazione canonica: crea una copia dell'oggetto, applica /= e restituisce il risultato*/
    rational operator/(const rational& other) const 
    {
        rational ret = *this;
        ret /= other;
        return ret;
    } 
};


template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r)
{   /*gestione casi speciali*/
    if (r.den() == 0)
    {
        if (r.num() == 0)
            os << "NaN";
        else
            os << "Inf";
    }
    else
    {
        os << r.num() << "/" << r.den();
    }

    return os;
};
