#include "MusicItem.h"

MusicItem::MusicItem(const std::string& title, const std::string& artist, int year,
                     Genre genre, const std::string& album,
                     MediaFormat* formats, int formatsCount,
                     const std::string& location)
    : title(title), artist(artist), year(year), genre(genre), album(album),
      formatsCount(formatsCount), location(location) {
    
    this->formats = new MediaFormat[formatsCount];
    for (int i = 0; i < formatsCount; i++) {
        this->formats[i] = formats[i];
    }
}

MusicItem::~MusicItem() {
    delete[] formats;
}

std::string MusicItem::genreToString(Genre g) {
    switch (g) {
        case GENRE_ROCK: return "Rock";
        case GENRE_POP: return "Pop";
        case GENRE_CLASSICAL: return "Classical";
        case GENRE_JAZZ: return "Jazz";
        case GENRE_HIPHOP: return "Hip-Hop";
        default: return "Unknown";
    }
}

std::string MusicItem::formatToString(MediaFormat f) {
    switch (f) {
        case FORMAT_CD: return "CD";
        case FORMAT_VINYL: return "Vinyl";
        case FORMAT_CASSETTE: return "Cassette";
        case FORMAT_DIGITAL: return "Digital";
        default: return "Unknown";
    }
}

bool MusicItem::hasFormat(MediaFormat format) const {
    for (int i = 0; i < formatsCount; i++) {
        if (formats[i] == format) {
            return true;
        }
    }
    return false;
}