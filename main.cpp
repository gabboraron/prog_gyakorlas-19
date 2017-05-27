#include <iostream>
#include "enor.h"


using namespace std;

int main()
{
    cout << endl<< "feladat: http://people.inf.elte.hu/gt/prog/hf2_CE.pdf   - 19" << endl;
    cout << "   -listazz azokat mikor nem vettek 'arukod22'-t - ki, mikor" << endl;
    cout << "   -keres mikor a legkevesebbet vettek - hanyfelet, ki, mikor" << endl;

    string fname;
    bool hiba;
    do{
        try{
            hiba=false;
            cout<<"Add meg a fajl nevet: ";
            cin>>fname;
            enor t(fname);
            //k�t �sszegz�s
            bool l=false;
            //for(t.first(); !t.end(); t.next())
            //Ha az ures fajlra hibat kell jelezni
            t.first();
            if(t.end())
            {
                cout<<"Ures a fajl, nem lehet feldolgozni!\n";
                hiba=true;
                break;
            }
            for(;!t.end(); t.next())
            {

            }

        }catch(enor::enorerror err)
        {
            if(err==enor::OpenError)
            {
                cerr<<fname<<" nem nyithato meg!\n";
                hiba=true;
            }
        }
    }while(hiba);
    return 0;
}
