#include <iostream>
#include <string>

using namespace std;

class MozeWykBadania{
    public:
        void badania() { cout << "Moge wykonywac badania" << endl; } 
};

class MozeNauczac{
    public:
        void tnauczyciel() { cout << "Moge nauczac" << endl; }
};

class TOsoba{
    public:
        void osoba() { cout << "TOsoba" << endl; }
};

class MozeBycStudentem{
    public:
        void student() { cout << "Moge byc studentem" << endl; }
};

class TNauczyciel : public TOsoba, public MozeNauczac{
    public:
        void nauczyciel() { cout << "Jestem nauczycielem" << endl; }
};

class TStudent : public TOsoba, public MozeBycStudentem{
    public:
        void tstudent() { cout << "Jestem studentem" << endl; }
};

class TDoktorant : public TStudent{
    public:
        void doktorant() { cout << "Jestem doktorantem" << endl; }
};

class TDoktorantNaucz : public TDoktorant, public MozeNauczac{
    public:
        void doktroant_naucz() { cout << "DoktorantNaucz" << endl; }
};

class TAsystentbadan : public MozeWykBadania, public TOsoba{
    public:
        void asystent() { cout << "Jestem asystentem badan" << endl; }
};

class TDoktorantBadacz : public TDoktorant, public TAsystentbadan{
    public: 
        void doktorant_badacz() { cout << "DoktorantBadacz" << endl; }
};

int main(){
    TNauczyciel nauczyciel;
    TStudent student;
    TAsystentbadan asystent;
    TDoktorant doktorant;
    TDoktorantBadacz dok_badacz;
    TDoktorantNaucz dok_naucz;

    nauczyciel.osoba();
    nauczyciel.tnauczyciel();
    nauczyciel.nauczyciel();
    cout << string(40, '-') << endl;
    student.osoba();
    student.student();
    student.tstudent();
    cout << string(40, '-') << endl;
    asystent.osoba();
    asystent.badania();
    asystent.asystent();
    cout << string(40, '-') << endl;
    doktorant.osoba();
    doktorant.student();
    doktorant.tstudent();
    doktorant.doktorant();
    cout << string(40, '-') << endl;
    dok_badacz.TDoktorant::osoba(); // metoda osoba dziedziczona od klasy TDoktorant
    dok_badacz.TAsystentbadan::osoba(); // metoda osoba dziedziczona od klasy TAsystentbadan
    dok_badacz.badania();
    dok_badacz.asystent();
    dok_badacz.student();
    dok_badacz.tstudent();
    dok_badacz.doktorant();
    dok_badacz.doktorant_badacz();
    cout << string(40, '-') << endl;
    dok_naucz.osoba();
    dok_naucz.tnauczyciel();
    dok_naucz.student();
    dok_naucz.tstudent();
    dok_naucz.doktorant();
    dok_naucz.doktroant_naucz();
}