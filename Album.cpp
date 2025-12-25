#include "Album.h"
#include <sstream>
#include <iomanip>

Album::Album(const std::string& title, const std::string& artist, int year,
             Genre genre, const std::string& album,
             MediaFormat* formats, int formatsCount,
             const std::string& location,
             int trackCount, double totalDuration,
             std::string* trackList)
    : MusicItem(title, artist, year, genre, album, formats, formatsCount, location),
      trackCount(trackCount), totalDuration(totalDuration) {
    
    this->trackList = new std::string[trackCount];
    for (int i = 0; i < trackCount; i++) {
        this->trackList[i] = trackList[i];
    }
}

Album::~Album() {
    delete[] trackList;
}

std::string Album::getInfo() const {
    std::ostringstream oss;
    oss << "ALBUM: \"" << title << "\" by " << artist
        << " (" << year << ")\n"
        << "Tracks: " << trackCount << " (" 
        << std::fixed << std::setprecision(2) << totalDuration << " min)\n"
        << "Formats: ";
    
    for (int i = 0; i < formatsCount; i++) {
        oss << MusicItem::formatToString(formats[i]);
        if (i < formatsCount - 1) oss << ", ";
    }
    
    oss << " | Location: " << location << "\n"
        << "First 3 tracks:\n";
    
    int limit = (trackCount > 3) ? 3 : trackCount;
    for (int i = 0; i < limit; i++) {
        oss << "  " << (i + 1) << ". " << trackList[i] << "\n";
    }
    
    if (trackCount > 3) {
        oss << "  ... and " << (trackCount - 3) << " more";
    }
    
    return oss.str();
}