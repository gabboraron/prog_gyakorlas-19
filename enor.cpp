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

    if(sx==norm){
        ss>>vasarlas.time;
        ss>>vasarlas.id;
        while(ss>>tmp2)
        {
            vasarlas.items.push_back(tmp2);
            if(tmp2 == "arukod22")
                voltarukod22 = true;
            c=c+1;
        }
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

/*
void enor::osszegez()
{
    //k�t �sszegz�s
    dx.sum=0;
    dx.jo=true;
    for(int i=0; i<(int)dx.v.size(); ++i)
    {
        int ar;
        if(dx.v[i].tipus=='G') ar=500;
        else if(dx.v[i].tipus=='D') ar=800;
        else ar=1000;
        dx.sum+=ar;
        dx.jo=dx.jo && dx.v[i].tipus=='D';
    }

}

vetites enor::current() const
{
    return dx;
}
*/

bool enor::end() const
{
    if(sx==abnorm)
        cout<<endl<<endl<<"A legkevesebbet ("<<minOfItems<<" darabot) "<<minvasarlo.id<<" vasarolta "<< minvasarlo.time<<"-kor";
    return sx==abnorm;
}

/*
std::ostream& operator<<(std::ostream& out, const vetites& z)
{
    for(int i=0; i<(int)z.id.size(); ++i)
    {
        out<<z.id[i]<<" ";
    }
    out<<z.ido<<" ";
    for(int i=0; i<(int)z.v.size(); ++i)
    {
        out<<z.v[i].hely<<" "<<z.v[i].tipus<<" ";
    }
    out<<"sum="<<z.sum<<" "<<z.jo<<endl;
    return out;
}
*/
