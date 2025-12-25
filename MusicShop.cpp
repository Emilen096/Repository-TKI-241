#pragma once
#include "MusicItem.h"
#include "Song.h"
#include "Album.h"
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

// Класс-контейнер для управления музыкальной коллекцией
class MusicShop {
private:
    std::vector<std::shared_ptr<MusicItem>> catalog;
    
public:
    // Добавление произведения в каталог
    void addItem(std::shared_ptr<MusicItem> item);
    
    // Получение всей коллекции
    const std::vector<std::shared_ptr<MusicItem>>& getCatalog() const;
    
    // 1. Показать все произведения данного исполнителя
    std::vector<std::shared_ptr<MusicItem>> getByArtist(const std::string& artist) const;
    
    // 2. Показать местоположение выбранного произведения
    std::string getLocation(const std::string& title) const;
    
    // 3. Показать список носителей для выбранного произведения
    std::vector<std::string> getFormats(const std::string& title) const;
    
    // 4. Показать список произведений по жанру
    std::vector<std::shared_ptr<MusicItem>> getByGenre(Genre genre) const;
    
    // 5. Найти произведение по названию
    std::vector<std::shared_ptr<MusicItem>> findByTitle(const std::string& title) const;
    
    // 5. Найти произведение по году выпуска
    std::vector<std::shared_ptr<MusicItem>> findByYear(int year) const;
    
    // 5. Найти произведение по альбому
    std::vector<std::shared_ptr<MusicItem>> findByAlbum(const std::string& album) const;
    
    // 6. Показать список произведений исполнителя по выбранным годам
    std::vector<std::shared_ptr<MusicItem>> getByArtistAndYears(const std::string& artist, 
                                                                int startYear, int endYear) const;
    
    // Универсальный поиск по нескольким критериям
    std::vector<std::shared_ptr<MusicItem>> search(const std::string& keyword) const;
    
    // Получение размера каталога
    size_t size() const { return catalog.size(); }
};