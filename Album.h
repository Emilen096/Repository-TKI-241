#ifndef ALBUM_H
#define ALBUM_H

#include "MusicItem.h"
#include <string>

class Album : public MusicItem {
private:
    int trackCount;
    double totalDuration;
    std::string* trackList;
    
public:
    Album(const std::string& title, const std::string& artist, int year,
          Genre genre, const std::string& album,
          MediaFormat* formats, int formatsCount,
          const std::string& location,
          int trackCount, double totalDuration, 
          std::string* trackList);
    
    ~Album();
    
    int getTrackCount() const { return trackCount; }
    double getTotalDuration() const { return totalDuration; }
    std::string* getTrackList() const { return trackList; }
    
    std::string getInfo() const;
};

#endif