#include "MusicShop.h"
#include <iostream>
#include <algorithm>

void MusicShop::addItem(const std::shared_ptr<MusicItem>& item) {
    catalog.push_back(item);
}

std::vector<std::shared_ptr<MusicItem>> MusicShop::getItemsByArtist(const std::string& artist) const {
    std::vector<std::shared_ptr<MusicItem>> result;
    for (const auto& item : catalog) {
        if (item->getArtist() == artist) {
            result.push_back(item);
        }
    }
    return result;
}

std::string MusicShop::getItemLocation(const std::string& title) const {
    for (const auto& item : catalog) {
        if (item->getTitle() == title) {
            return item->getLocation();
        }
    }
    return "Произведение не найдено";
}

std::vector<MediaFormat> MusicShop::getFormatsByTitle(const std::string& title) const {
    std::vector<MediaFormat> formats;
    for (const auto& item : catalog) {
        if (item->getTitle() == title) {
            formats.push_back(item->getFormat());
        }
    }
    return formats;
}

std::vector<std::shared_ptr<MusicItem>> MusicShop::getItemsByGenre(Genre genre) const {
    std::vector<std::shared_ptr<MusicItem>> result;
    for (const auto& item : catalog) {
        if (item->getGenre() == genre) {
            result.push_back(item);
        }
    }
    return result;
}

std::vector<std::shared_ptr<MusicItem>> MusicShop::findItems(
    const std::string& title, int year, const std::string& album) const {
    
    std::vector<std::shared_ptr<MusicItem>> result;
    
    for (const auto& item : catalog) {
        bool matches = true;
        
        if (!title.empty() && item->getTitle() != title) matches = false;
        if (year != 0 && item->getYear() != year) matches = false;
        if (!album.empty() && item->getAlbum() != album) matches = false;
        
        if (matches) {
            result.push_back(item);
        }
    }
    return result;
}

std::vector<std::shared_ptr<MusicItem>> MusicShop::getItemsByArtistAndYears(
    const std::string& artist, int startYear, int endYear) const {
    
    std::vector<std::shared_ptr<MusicItem>> result;
    for (const auto& item : catalog) {
        if (item->getArtist() == artist && 
            item->getYear() >= startYear && 
            item->getYear() <= endYear) {
            result.push_back(item);
        }
    }
    return result;
}

void MusicShop::displayCatalog() const {
    std::cout << "=== КАТАЛОГ МУЗЫКАЛЬНОГО МАГАЗИНА ===\n";
    for (const auto& item : catalog) {
        std::cout << item->toString() << "------------------------\n";
    }
}
