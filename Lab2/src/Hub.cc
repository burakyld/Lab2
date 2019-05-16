
#include <stdio.h>
#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class Hub : public cSimpleModule
    {
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        virtual void finish();
    private:
        int *a;
    };
    Define_Module(Hub);

    void Hub::initialize()
    {
         a=(int*)calloc(sizeof(int),gateSize("out")); //bellekten yer ayr�ld� ve bellek daha sonras�nda s�f�rland�
    }

    void Hub::handleMessage(cMessage *msg)
        {
        cGate *g = msg->getArrivalGate();
            switch(a[g->getIndex()]){
            case 0:

                            send(new cMessage("renk",  2),"out",g->getIndex());
              break;

            case 1:
                            send(new cMessage("renk",  2),"out",g->getIndex());
                            break;
            case 2:
                delete(msg);


            }

            a[g->getIndex()] = (a[g->getIndex()]+1)%3; //parametreye g�re mod3 de case lere giri� yap�l�yor. 

        }

    void Hub::finish()
    {}




