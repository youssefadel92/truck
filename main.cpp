#include <iostream>
#include <String>

using namespace std;
class person
{
private:
    string name;
public:
    person(){
        name="";
    }
    person(string the_name){
        name=the_name;
    }
    person(const person& the_object){
        name=the_object.name;
    }
    string get_name(){
        cout<<name<<endl;
    }
    person& operator = (const person& rt_side){
        string x=rt_side.name;
        name=x;
    }
    friend istream& operator >>(istream& in_stream,person& person_object){
        string nam;
        cout<<"enter person's name:";
        getline(cin, nam);
        person_object.name=nam;
        return in_stream;
    }
    friend ostream& operator <<(ostream& out_stream,const person& person_object){
        cout<<person_object.name<<endl;
    }

};
class vechile{
    protected:
    string manufacturername;
    int cylindersnum;
    person owner;
    public:
    vechile(){
        manufacturername="";
        cylindersnum=0;
    }
    vechile(string manf,int cyl,person own){
        manufacturername=manf;
        cylindersnum=cyl;
        owner=own;
    }
    void setcylindersnum(int x){
        cylindersnum=x;
    }
    void setmanfacturername(string x){
        manufacturername=x;
    }
    void setowner(person x){
        owner=x;
    }
    friend istream& operator >>(istream& in_stream,vechile& v){
        string nam;
        int x;
        person zs;
        cout<<"enter manufacturer's name:";
        getline(cin,nam);
        cin>>zs;
        v.owner=zs;
        cout<<"enter cylinders:";
        cin>>x;
        v.cylindersnum=x;
        v.manufacturername=nam;
        return in_stream;
    }


};
class truck:public vechile{
    protected:
    double loadcapacity;
    int towingcapacity;
    public:
    truck(const truck& z){
        loadcapacity=z.loadcapacity;
        towingcapacity=z.towingcapacity;
        manufacturername=z.manufacturername;
        owner=z.owner;
        cylindersnum=z.cylindersnum;
    }
    truck(){
        loadcapacity=0;
        towingcapacity=0;
        vechile();
    }
    truck(string manf,int cyl,person own,double loadca,int tocap):vechile (manf,cyl,own)
    {
        loadcapacity=loadca;
        towingcapacity=tocap;
    }
    void setloadcapacity(double x){
        loadcapacity=x;
    }
    void settowcapacity(int x){
        towingcapacity=x;
    }
    friend ostream& operator <<(ostream& out_stream,const truck& g){
        cout<<"Load Capacity:"<<g.loadcapacity<<endl<<"cylinders:"<<g.cylindersnum<<endl;
        cout<<"Tow Capacity:"<<g.towingcapacity<<endl<<"manufacturer name:"<<g.manufacturername<<endl<<"Owner:"<<g.owner;
    }
    friend istream& operator >>(istream& in_stream,truck& t){
        int x,y;
        string c;
        double z;
        person p;
        cin>>p;
        cout<<"enter manufacturer name:";
        getline(cin,c);
        cout<<"enter load Capacity:";
        cin>>z;
        cout<<"enter towing Capacity:";
        cin>>y;
        cout<<"enter cylinders:";
        cin>>x;

        t.loadcapacity=z;
        t.towingcapacity=y;
        t.manufacturername=c;
        t.owner=p;
        t.cylindersnum=x;

        return in_stream;
    }
    truck& operator = (const truck& z){
        loadcapacity=z.loadcapacity;
        towingcapacity=z.towingcapacity;
        manufacturername=z.manufacturername;
        owner=z.owner;
        cylindersnum=z.cylindersnum;
    }

};
int main()
{
//    person x("youssef");
//    person y;
//    person z;
//    cin>>z;
//    y=x;
//    truck t("mitsubishi",2000,z,200,100);
 //   vechile v;
 //   cin>>v;
    truck t;
    cin>>t;
    //truck z(t);
    truck z;
    z=t;
    cout<<t<<endl;
    cout<<z<<endl;
    return 0;
}
