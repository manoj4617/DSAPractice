#include <iostream>

using namespace std;

class MediaPlayer {
    public:
    virtual void play(const string&) = 0;
    virtual ~MediaPlayer() = default;
};

class VideoPlayer {
    public:
    void playVideo(const string& fileName) {
        cout << "Playing video from: " << fileName << "\n";
    }
};

/**
 * Adapter pattern is a structural design pattern that allows objects with incompatible interfaces to collaborate.
 * It does this by providing an adapter object that contains the old interface and maps it to the new interface.
 * The purpose of the adapter pattern is to allow two classes that are not compatible to work together, without
 * changing their source code.
 *
 * In the example above, we have a VideoPlayer class that has a playVideo method that takes a string as an argument.
 * We also have a MediaPlayer interface that has a play method that takes a string as an argument.  The problem is that
 * the VideoPlayer class does not implement the MediaPlayer interface, so we cannot pass a VideoPlayer object to methods
 * that expect a MediaPlayer object.
 *
 * The adapter pattern solves this problem by providing a class, VideoPlayerAdapter, that implements the MediaPlayer
 * interface.  The VideoPlayerAdapter class takes a VideoPlayer object in its constructor, and maps the play method of
 * the MediaPlayer interface to the playVideo method of the VideoPlayer class.
 *
 * So, if we have a method that takes a MediaPlayer object as an argument, we can pass a VideoPlayerAdapter object to it
 * instead of the VideoPlayer object, and it will work correctly.
 */
class VideoPlayerAdapter : public MediaPlayer{
    private:
    VideoPlayer* videoPlayer;

    public:
    VideoPlayerAdapter(VideoPlayer* player) : videoPlayer(player) {}
    void play(const string& fileName) override {
        videoPlayer->playVideo(fileName);
    }
};

int main(){
    VideoPlayer* videoPlayer = new VideoPlayer();
    MediaPlayer* player = new VideoPlayerAdapter(videoPlayer);
    player->play("movie.mp4");

    delete videoPlayer;
    delete player;

    return 0;
}