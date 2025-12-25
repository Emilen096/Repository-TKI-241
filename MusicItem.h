#ifndef MUSICITEM_H
#define MUSICITEM_H

#include <string>

// Простые перечисления
enum Genre {
    GENRE_ROCK = 0,
    GENRE_POP,
    GENRE_CLASSICAL,
    GENRE_JAZZ,
    GENRE_HIPHOP
};

enum MediaFormat {
    FORMAT_CD = 0,
    FORMAT_VINYL,
    FORMAT_CASSETTE,
    FORMAT_DIGITAL
};

class MusicItem {
protected:
    std::string title;
    std::string artist;
    int year;
    Genre genre;
    std::string album;
    MediaFormat* formats;
    int formatsCount;
    std::string location;

public:
    MusicItem(const std::string& title, const std::string& artist, int year,
              Genre genre, const std::string& album,
              MediaFormat* formats, int formatsCount,
              const std::string& location);
    virtual ~MusicItem();

    std::string getTitle() const { return title; }
    std::string getArtist() const { return artist; }
    int getYear() const { return year; }
    Genre getGenre() const { return genre; }
    std::string getAlbum() const { return album; }
    MediaFormat* getFormats() const { return formats; }
    int getFormatsCount() const { return formatsCount; }
    std::string getLocation() const { return location; }

    virtual std::string getInfo() const = 0;

    static std::string genreToString(Genre g);
    static std::string formatToString(MediaFormat f);
    bool hasFormat(MediaFormat format) const;
};

#endif