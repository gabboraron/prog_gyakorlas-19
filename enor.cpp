#include "enor.h"
#include <iostream>
#include <sstream>

using namespace std;

enor::enor(const string& fname)
{
    x.open(fname.c_str());
    if(x.fail()) throw OpenError;
    cout<<fname<<" file feldolgozasa megkezdodott.\n";
}

void enor::first()
{
    next();
}

void enor::next()
{
    read();
//    osszegez();
}

void enor::read()
{
    vasarlo vasarlas;
    string tmp2;
    voltarukod22 = false;
    int c = 0;

    string tmp;
    getline(x,tmp);
    istringstream ss(tmp);
    sx = x.fail()? abnorm : norm;

    /* linker valtozok */
    bool voltMar;
    int j;
    /* *** */

    if(sx==norm){
        ss>>vasarlas.time;
        ss>>vasarlas.id;
        while(ss>>tmp2)
        {
            vasarlas.items.push_back(tmp2);
            if(tmp2 == "arukod22")
                voltarukod22 = true;
        }

            /* linker, hogy volt-e mar ilyen elem */
           voltMar = false;
           for(int i=1;i<vasarlas.items.size(); ++i)
           {

                j = 0;

                while((voltMar == false) && (j<i))
                {
                    if(vasarlas.items[i] == vasarlas.items[j])
                        voltMar = true;
                    j = j+1;
                }

                if(voltMar == false)
                {
                    c = c + 1;
                }
           }
            /* *** */
            //c=c+1;

        if(voltarukod22 == false)
            cout<<endl<<vasarlas.time<<"    "<<vasarlas.id;
        if(elsovasarlo)
        {
            elsovasarlo = false;
            minOfItems = c;

            minvasarlo.id = vasarlas.id;
            minvasarlo.items = vasarlas.items;
            minvasarlo.time = vasarlas. time;
        } else if(minOfItems>c){
            minOfItems = c;

            minvasarlo.id = vasarlas.id;
            minvasarlo.items = vasarlas.items;
            minvasarlo.time = vasarlas. time;
        }
    }
}

bool enor::end() const
{
    if(sx==abnorm)
        cout<<endl<<endl<<"A legkevesebbet ("<<minOfItems<<" darabot) "<<minvasarlo.id<<" vasarolta "<< minvasarlo.time<<"-kor";
    return sx==abnorm;
}
