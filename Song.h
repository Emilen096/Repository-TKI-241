#ifndef SONG_H
#define SONG_H

#include "MusicItem.h"

class Song : public MusicItem {
private:
    double duration;
    std::string writer;
    
public:
    Song(const std::string& title, const std::string& artist, int year,
         Genre genre, const std::string& album,
         MediaFormat* formats, int formatsCount,
         const std::string& location,
         double duration, const std::string& writer);
    
    double getDuration() const { return duration; }
    std::string getWriter() const { return writer; }
    
    std::string getInfo() const;
};

#endif