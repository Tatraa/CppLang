#include <iostream>
#include <memory>

using namespace std;

class DisplayDrv{
    public:
        DisplayDrv() {}
        virtual ~DisplayDrv() {}
        virtual void wykonaj() {}
};

class PrinterDrv{
    public:
        PrinterDrv() {}
        virtual ~PrinterDrv() {}
        virtual void wykonaj() {}
};
//--------------------------------------------------------------
class LRDD : public DisplayDrv{
    public:
        LRDD() {}
        virtual ~LRDD() {}
        void wyswietl(){
            cout << "LRDD" << endl;
        }
};

class LowResDispDrv : public DisplayDrv{
    public:
        LowResDispDrv() {}
        virtual ~LowResDispDrv() {}
        void wykonaj() override{
            dsp.wyswietl();
        }
    private:
        LRDD dsp;
};
//--------------------------------------------------------------
class HRDD : public DisplayDrv{
    public:
        HRDD() {}
        virtual ~HRDD() {}
        void wyswietl(){
            cout << "HRDD" << endl;
        }
};

class HighResDispDrv : public DisplayDrv{
    public:
        HighResDispDrv() {}
        virtual ~HighResDispDrv() {}
        void wykonaj() override{
            dsp.wyswietl();
        }
    private:
        HRDD dsp;
};
//--------------------------------------------------------------
class LRPD : public PrinterDrv{
    public:
        LRPD() {}
        virtual ~LRPD() {}
        void wyswietl(){
            cout << "LRPD" << endl;
        }
};

class LowResPrtDrv : public PrinterDrv{
    public:
        LowResPrtDrv() {}
        virtual ~LowResPrtDrv() {}
        void wykonaj() override{
            dsp.wyswietl();
        }
    private:
        LRPD dsp;
};
//--------------------------------------------------------------
class HRPD : public PrinterDrv{
    public:
        HRPD() {}
        virtual ~HRPD() {}
        void wyswietl(){
            cout << "HRPD" << endl;
        }
};

class HighResPrtDrv : public PrinterDrv{
    public:
        HighResPrtDrv() {}
        virtual ~HighResPrtDrv() {}
        void wykonaj() override{
            dsp.wyswietl();
        }
    private:
        HRPD dsp;
};
//--------------------------------------------------------------
class ResFactory{
    public:
        ResFactory() {}
        virtual ~ResFactory() {}
        virtual unique_ptr<DisplayDrv> getDispDrv() { return nullptr; }
        virtual unique_ptr<PrinterDrv> getPrintDrv() { return nullptr; }
};

class LowResFactory : public ResFactory{
    public:
        LowResFactory() {}
        virtual ~LowResFactory() {}
        unique_ptr<DisplayDrv> getDispDrv() { return unique_ptr<DisplayDrv> (new LowResDispDrv); }
        unique_ptr<PrinterDrv> getPrintDrv() { return unique_ptr<PrinterDrv> (new LowResPrtDrv); }
};

class HighResFactory : public ResFactory{
    public:
        HighResFactory() {}
        virtual ~HighResFactory() {}
        unique_ptr<DisplayDrv> getDispDrv() { return unique_ptr<DisplayDrv> (new HighResDispDrv); }
        unique_ptr<PrinterDrv> getPrintDrv() { return unique_ptr<PrinterDrv> (new HighResPrtDrv); }
};

int main(){
    unique_ptr<ResFactory> fabryka(new LowResFactory); 
    unique_ptr<DisplayDrv> ddrv = fabryka->getDispDrv(); 
    unique_ptr<PrinterDrv> pdrv = fabryka->getPrintDrv(); 
    ddrv->wykonaj(); 
    pdrv->wykonaj(); 
    
    fabryka.reset(new HighResFactory); 
    ddrv = fabryka->getDispDrv(); 
    pdrv = fabryka->getPrintDrv(); 
    ddrv->wykonaj(); 
    pdrv->wykonaj();
}