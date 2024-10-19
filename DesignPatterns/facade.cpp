#include <iostream>

using namespace std;

class DVDPlayer{
    public:
    void on(){
        cout << "Turning on DVD player..\n";
    }
    void play(const string& movieName){
        cout << "Playing movie " << movieName << " on DVD player...\n";
    }
    void off(){
        cout << "Turning off DVD player..\n";
    }
};

class Projector {
    public:
    void on(){
        cout << "Turning on Projector...\n";
    }

    void off(){
        cout << "Turning off Projector...\n";
    }
};

class Speaker {
    public:
    void on(){
        cout << "Turning on speaker...\n";
    }
    void setVolume(int level){
        cout << "Setting speaker volume to: " << level << "\n";
    }
    void off(){
        cout << "Turning off spearker...\n";
    }
};

class MovieTheatre{
    private:
    DVDPlayer *dvdPlayer;
    Projector *project;
    Speaker *speaker;

    public:
    MovieTheatre(DVDPlayer *dvd, Projector *proj, Speaker *speak) :
        dvdPlayer(dvd),
        project(proj),
        speaker(speak){}

    void watchMovie(const string& movieName){
        cout << "Get Ready to watch a movie...";
        dvdPlayer->on();
        project->on();
        speaker->on();
        speaker->setVolume(10);
        dvdPlayer->play(movieName);
    }

    void endMovie(){
        std::cout << "Shutting down home theater system..." << std::endl;
        dvdPlayer->off();
        project->off();
        speaker->off();
    }
};

int main() {
    // Create subsystem objects
    DVDPlayer dvdPlayer;
    Projector projector;
    Speaker speakers;

    // Create the facade and pass the subsystem objects
    MovieTheatre homeTheater(&dvdPlayer, &projector, &speakers);

    // Use the facade to watch a movie
    homeTheater.watchMovie("The Matrix");

    // Use the facade to end the movie
    homeTheater.endMovie();

    return 0;
}