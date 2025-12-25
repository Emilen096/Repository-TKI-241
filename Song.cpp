#include "Song.h"
#include <sstream>
#include <iomanip>

Song::Song(const std::string& title, const std::string& artist, int year,
           Genre genre, const std::string& album,
           MediaFormat* formats, int formatsCount,
           const std::string& location,
           double duration, const std::string& writer)
    : MusicItem(title, artist, year, genre, album, formats, formatsCount, location),
      duration(duration), writer(writer) {}

std::string Song::getInfo() const {
    std::ostringstream oss;
    oss << "SONG: \"" << title << "\" by " << artist
        << " (" << year << ")\n"
        << "Album: " << (album.empty() ? "(Single)" : album)
        << " | Genre: " << MusicItem::genreToString(genre)
        << " | Duration: " << std::fixed << std::setprecision(2) << duration << " min\n"
        << "Formats: ";
    
    for (int i = 0; i < formatsCount; i++) {
        oss << MusicItem::formatToString(formats[i]);
        if (i < formatsCount - 1) oss << ", ";
    }
    
    oss << " | Location: " << location
        << " | Writer: " << writer;
    return oss.str();
}