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
            vasarlo tmp;
            bool voltarukod22;
            int cOfarukod22 = 0;
            int j,c;
            //--
            int minimum;
            vasarlo minimumElem;
            bool elsoelem = true;
            bool voltMar;

            hiba=false;
            cout<<"Add meg a fajl nevet: ";
            cin>>fname;
            enor t(fname);
            bool l=false;
            //for(t.first(); !t.end(); t.next())
            //Ha az ures fajlra hibat kell jelezni
            t.first();
            cout<<endl<<"Az alabbiak nem vettek 'arukod22'-t: "<<endl;
            if(t.end())
            {
                cout<<"Ures a fajl, nem lehet feldolgozni!\n";
                hiba=true;
                break;
            }
            for(;!t.end(); t.next())
            {
                //--feldolgozas
                tmp = t.Current();
                /*cout<<endl<<tmp.id<<" "<<tmp.time<<endl;

                for(int i=0; i<tmp.items.size(); ++i)
                {
                    cout<<tmp.items[i]<<" ";
                }*/
                voltarukod22 = false;
                j=0;
                //cout<<"voltarukod22 - eleje: "<<voltarukod22<<endl;
                while((voltarukod22 == false) && (j<tmp.items.size()))
                {
                    if(tmp.items[j] == "arukod22")
                        voltarukod22 = true;
                    //cout<<"tmp.items["<<j<<"]:"<<tmp.items[j]<<" ";
                    ++j;
                }
                //cout<<endl;

                if(voltarukod22 == false)
                {
                    cout<<tmp.id<<" "<<tmp.time<<endl;
                    ++cOfarukod22;
                }/* else
                {
                    cout<<"vett: "<<tmp.id<<" "<<tmp.time<<endl;
                }*/
                //cout<<"voltarukod22 - vege: "<<voltarukod22<<endl;

                //LINKER
                if(elsoelem == false)
                {
                    c = 1;
                   /* for(int i=1; i<tmp.items.size(); ++i)
                    {
                        j = 0;
                        cout<<endl<<tmp.items[i]<<": ";
                        while( (j<i) && (tmp.items[i] != tmp.items[j]))
                        {
                            cout<<tmp.items[j]<<" ";
                            ++j;
                        }
                        if(tmp.items[i] != tmp.items[j])
                            ++c;
                    }*/
                       voltMar = false;
                       for(int i=1;i<tmp.items.size(); ++i)
                       {

                            j = 0;

                            while((voltMar == false) && (j<i))
                            {
                                if(tmp.items[i] == tmp.items[j])
                                    voltMar = true;
                                j = j+1;
                            }

                            if(voltMar == false)
                            {
                                c = c + 1;
                            }
                       }
                    //c = tmp.items.size();
                //MINKER
                    if(minimum > c)
                    {
                        minimum = c;
                        minimumElem.id = tmp.id;
                        minimumElem.items = tmp.items;
                        minimumElem.time = tmp.time;
                    }

                }else
                {
                    minimum = tmp.items.size();
                    elsoelem = false;

                    minimumElem.id = tmp.id;
                    minimumElem.items = tmp.items;
                    minimumElem.time = tmp.time;
                }
            }
            cout<<endl<<"A legkevesebbet "<<minimumElem.id<<" vasarolta "<<minimumElem.time<<"-kor, "<<minimum<<" darabot.";

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
