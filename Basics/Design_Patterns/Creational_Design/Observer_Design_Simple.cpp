#include<iostream>
#include<vector>
using namespace std;

class Oberserver
{
    public:
    virtual void update(string upString)=0;
};

class YtSubscriber : public Oberserver
{
    private:
    string name;
    public:
    YtSubscriber(string nameOfSub) : name(nameOfSub){}
    void update(string upStr) override
    {
        cout<<"Name of Yt Sub : "<<name<<" notification received is : "<<upStr<<endl;
    }
};

class YtChannel
{
    private:
    std::vector<Oberserver*> obs;
    public:
    void subscribe(Oberserver* subObs)
    {
        obs.push_back(subObs);
    }

    void notify(string notifyStr)
    {
        for(auto observer:obs)
        {
            observer->update(notifyStr);
        }
    }
};

int main()
{
    YtSubscriber yt1(std::string("Rak"));
    YtSubscriber yt2(std::string("Bak"));

    YtChannel ytChannel;
    ytChannel.subscribe(&yt1);
    ytChannel.subscribe(&yt2);

    ytChannel.notify("New vid");
    return 0;
}