#include "iostream"
using namespace std;

struct Player
{
    int card;
    Player *next;
};

Player* AddFirst(Player *f, Player *t)
{
    t->next=f;
    return t;
}

Player* AddLast(Player *last, Player* t)
{
    last->next=t;
    t->next=NULL;
    return t;
}

int main()
{
    Player *p;
    Player *player1f=0, *player2f=0, *player1l=0, *player2l=0;
    int n=5;
    for(int i=0; i<n; ++i)
    {
        p=new Player;
        cin>>p->card;
        if(player1f==0) {
            AddFirst(player1f,p);
            player1f=p;
            player1l=p;
        }
        else {
            AddLast(player1l,p);
            player1l=p;
        }
    }
    for(int i=0; i<n; ++i)
    {
        p=new Player;
        cin>>p->card;
        if(player2f==0) {
            AddFirst(player2f,p);
            player2f=p;
            player2l=p;
        }
        else {
            AddLast(player2l,p);
            player2l=p;
        }
    }

    int s=0;
    while(true)
    {
        Player *t1=player1f, *t2=player2f;
        if(t1->card > t2->card)
        {
            if(t1->card==9 && t2->card==0)
            {
                if(player1f->next==0) {
                    cout<<"second";
                    ++s;
                    break;
                }
                else if(player2f->next==0)
                {
                    player1f=player1f->next;
                    AddFirst(player2f,t1);
                    player2f=t1;
                    ++s;
                }
                else {
                    player2f=player2f->next;
                    player1f=player1f->next;
                    AddLast(player2l,t1);
                    player2l=t1;
                    AddLast(player2l,t2);
                    player2l=t2;
                    ++s;
                }
            }
            else {
                if(player2f->next==0) {
                    cout<<"first";
                    ++s;
                    break;
                }
                else if(player1f->next==0)
                {
                    player2f=player2f->next;
                    AddLast(player1l,t2);
                    player1l=t2;
                    ++s;
                }
                else {
                    player2f=player2f->next;
                    player1f=player1f->next;
                    AddLast(player1l,t1);
                    player1l=t1;
                    AddLast(player1l,t2);
                    player1l=t2;
                    ++s;
                }
            }
        }
        else if(t1->card < t2->card)
        {
            if(t1->card==0 && t2->card==9)
            {
                if(player2f->next==0) {
                    cout<<"first";
                    ++s;
                    break;
                }
                else if(player1f->next==0)
                {
                    player2f=player2f->next;
                    AddLast(player1l,t2);
                    player1l=t2;
                    ++s;
                }
                else {
                    player2f=player2f->next;
                    player1f=player1f->next;
                    AddLast(player1l,t1);
                    player1l=t1;
                    AddLast(player1l,t2);
                    player1l=t2;
                    ++s;
                }
            }
            else {
                if(player1f->next==0) {
                    cout<<"second";
                    ++s;
                    break;
                }
                else if(player2f->next==0)
                {
                    player1f=player1f->next;
                    AddFirst(player2f,t1);
                    player2f=t1;
                    ++s;
                }
                else {
                    player2f=player2f->next;
                    player1f=player1f->next;
                    AddLast(player2l,t1);
                    player2l=t1;
                    AddLast(player2l,t2);
                    player2l=t2;
                    ++s;
                }
            }
        }
        if(s>=1000000) {
            cout<<"botva";
            system("PAUSE");
            return 0;
        }

    }

    cout<<' '<<s;

    system("PAUSE");
    return 0;
}
