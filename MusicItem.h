#pragma once
#include <string>
#include <memory>

enum class Genre { ROCK, POP, JAZZ, CLASSICAL, HIPHOP, ELECTRONIC };
enum class MediaFormat { CD, VINYL, CASSETTE, DIGITAL };

class MusicItem {
protected:
    std::string title;
    std::string artist;
    int year;
    Genre genre;
    std::string album;
    MediaFormat format;
    double price;
    std::string location;  // местоположение в магазине
    
public:
    MusicItem(const std::string& title, const std::string& artist, 
              int year, Genre genre, const std::string& album,
              MediaFormat format, double price, const std::string& location);
    
    virtual ~MusicItem() = default;
    
    // Геттеры
    std::string getTitle() const { return title; }
    std::string getArtist() const { return artist; }
    int getYear() const { return year; }
    Genre getGenre() const { return genre; }
    std::string getAlbum() const { return album; }
    MediaFormat getFormat() const { return format; }
    double getPrice() const { return price; }
    std::string getLocation() const { return location; }
    
    // Виртуальный метод для вывода информации
    virtual std::string toString() const;
};
