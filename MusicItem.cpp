#include "MusicItem.h"
#include <sstream>

MusicItem::MusicItem(const std::string& title, const std::string& artist, 
                     int year, Genre genre, const std::string& album,
                     MediaFormat format, double price, const std::string& location)
    : title(title), artist(artist), year(year), genre(genre), album(album),
      format(format), price(price), location(location) {}

std::string MusicItem::toString() const {
    std::stringstream ss;
    ss << "Название: " << title 
       << "\nИсполнитель: " << artist
       << "\nГод: " << year
       << "\nАльбом: " << album
       << "\nЖанр: " << static_cast<int>(genre)
       << "\nФормат: " << static_cast<int>(format)
       << "\nЦена: $" << price
       << "\nМестоположение: " << location
       << "\n";
    return ss.str();
}
