#pragma once
#include "MusicItem.h"
#include <vector>
#include <memory>
#include <string>

class MusicShop {
private:
    std::vector<std::shared_ptr<MusicItem>> catalog;
    
public:
    // Добавление произведения в каталог
    void addItem(const std::shared_ptr<MusicItem>& item);
    
    // Методы по заданию:
    
    // 1. Показать все произведения данного композитора (исполнителя)
    std::vector<std::shared_ptr<MusicItem>> getItemsByArtist(const std::string& artist) const;
    
    // 2. Показать местоположение выбранного произведения
    std::string getItemLocation(const std::string& title) const;
    
    // 3. Показать список носителей для выбранного произведения
    std::vector<MediaFormat> getFormatsByTitle(const std::string& title) const;
    
    // 4. Показать список произведений по жанру исполнения
    std::vector<std::shared_ptr<MusicItem>> getItemsByGenre(Genre genre) const;
    
    // 5. Находить произведение по названию, году выпуска, альбому
    std::vector<std::shared_ptr<MusicItem>> findItems(
        const std::string& title = "", 
        int year = 0, 
        const std::string& album = "") const;
    
    // 6. Показывать список произведений данного композитора по выбранным годам творчества
    std::vector<std::shared_ptr<MusicItem>> getItemsByArtistAndYears(
        const std::string& artist, 
        int startYear, 
        int endYear) const;
    
    // Дополнительно: вывод всего каталога
    void displayCatalog() const;
};
