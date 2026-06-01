#include <iostream>
using namespace std;
class Gun{
public:
    int ammo;
    int damage;
    int scope;
};
class player{ // class is user difine datatype
public:
    class helmet{
        private:
        int hp;
        int level;
        public:
        int gethp(){
            return hp;
            
        }
        int getlevel(){
            return level;
        }
        void sethp(int hp){
            this->hp=hp;
            return;
        }
        void setlevel(int level){
            this->level=level;
            return;
        }
        
    };


private:

    int health;
    int age;
    int score;
    bool alive;
    Gun gun;
    helmet Helmet;


public:
    int gethealth()
    {
        return health;
    }
    int getAge()
    {
        return age;
    }
    int getscore()
    {
        return score;
    }
    int getalive()
    {
        return alive;
    }
    Gun getgun(){
        return gun;
    }
    helmet gethelmet(){
        return Helmet;
    }


    void setgun(Gun gun){
        this->gun=gun;
    }
    void sethealth(int health)
    {
        player::health = health;
        return;
    }
    void setAge(int age)
    {
        this->age = age;
        return;
    }
    void setscore(int score)
    {
        player::score = score;
        return;
    }
    void setAlive(bool alive)
    {
        player::alive = alive;
        return;
    }

    void sethelmet(int level){
        helmet *Helmet=new helmet;
        Helmet->setlevel(level);
        if(level==1) Helmet->sethp(25);
        else if(level==2) Helmet->sethp(50);
        else if(level==3) Helmet->sethp(100);
        else cout<<"invalid";

        this->Helmet=*Helmet;

    }
};

int add(player a,player b){
    return a.getscore()+b.getscore();
}
player maxScore(player a,player b){
    if(a.getscore()>b.getscore()) return a;
    else return b; 
}
int main(){
    player sarthak; //object creation.
    //adding data
    sarthak.setAge(20);
    sarthak.setAlive(true);
    sarthak.sethealth(90);
    sarthak.setscore(500);
    cout<<sarthak.getAge()<<" ";
    cout<<sarthak.getalive()<<" ";
    cout<<sarthak.gethealth()<<" ";
    cout<<sarthak.getscore()<<" ";


    player harsh;
    harsh.setscore(120);

    cout<<endl<<add(harsh,sarthak);
    player sanket=maxScore(harsh,sarthak);
    cout<<endl<<sanket.getscore();
    // player* sam=new player;   //it stores only add of new player
    // player sam_obj=*sam;
    // sam_obj.setscore(40); it is with creating object 
    // cout<<endl<<sam_obj.getscore();

    player*sam=new player;  //withot creating object
    sam->setscore(200);
    cout<<endl<<sam->getscore();


    Gun akm;
    akm.damage=45;
    akm.ammo=100;
    akm.scope=1;
    sarthak.setgun(akm);

    cout<<endl<<sarthak.getgun().damage;

    sarthak.sethelmet(2);
    cout<<endl<<sarthak.gethelmet().gethp();


    //array of objects
    player players[3]={sarthak,harsh,*sam};
    cout<<endl<<players[0].getAge();


    
}