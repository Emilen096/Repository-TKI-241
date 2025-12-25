#include "MusicShop.h"
#include <iostream>
#include <memory>

int main() {
    MusicShop shop;
    
    // Добавляем тестовые данные
    shop.addItem(std::make_shared<MusicItem>("Bohemian Rhapsody", "Queen", 
        1975, Genre::ROCK, "A Night at the Opera", MediaFormat::VINYL, 
        29.99, "Стеллаж A, Полка 3"));
    
    shop.addItem(std::make_shared<MusicItem>("Hotel California", "Eagles", 
        1976, Genre::ROCK, "Hotel California", MediaFormat::CD, 
        19.99, "Стеллаж B, Полка 1"));
    
    shop.addItem(std::make_shared<MusicItem>("Imagine", "John Lennon", 
        1971, Genre::POP, "Imagine", MediaFormat::CASSETTE, 
        14.99, "Стеллаж C, Полка 2"));
    
    shop.addItem(std::make_shared<MusicItem>("Thriller", "Michael Jackson", 
        1982, Genre::POP, "Thriller", MediaFormat::CD, 
        24.99, "Стеллаж A, Полка 1"));
    
    shop.addItem(std::make_shared<MusicItem>("Billie Jean", "Michael Jackson", 
        1982, Genre::POP, "Thriller", MediaFormat::VINYL, 
        34.99, "Стеллаж A, Полка 2"));
    
    // Тестируем все функции по заданию
    
    std::cout << "=== ТЕСТИРОВАНИЕ ВСЕХ ФУНКЦИЙ ===\n\n";
    
    // 1. Произведения исполнителя
    std::cout << "1. Все произведения Michael Jackson:\n";
    auto jacksonSongs = shop.getItemsByArtist("Michael Jackson");
    for (const auto& song : jacksonSongs) {
        std::cout << " - " << song->getTitle() << " (" << song->getYear() << ")\n";
    }
    
    // 2. Местоположение
    std::cout << "\n2. Местоположение 'Hotel California':\n";
    std::cout << "   " << shop.getItemLocation("Hotel California") << "\n";
    
    // 3. Список носителей для произведения
    std::cout << "\n3. Носители для 'Thriller':\n";
    auto formats = shop.getFormatsByTitle("Thriller");
    for (const auto& format : formats) {
        std::cout << "   - " << static_cast<int>(format) << "\n";
    }
    
    // 4. Произведения по жанру
    std::cout << "\n4. Все произведения в жанре ROCK:\n";
    auto rockSongs = shop.getItemsByGenre(Genre::ROCK);
    for (const auto& song : rockSongs) {
        std::cout << "   - " << song->getTitle() << " by " << song->getArtist() << "\n";
    }
    
    // 5. Поиск по критериям
    std::cout << "\n5. Поиск произведений 1982 года:\n";
    auto search1982 = shop.findItems("", 1982, "");
    for (const auto& song : search1982) {
        std::cout << "   - " << song->getTitle() << "\n";
    }
    
    // 6. Произведения исполнителя за период
    std::cout << "\n6. Произведения Queen за 1970-1980 гг:\n";
    auto queen70s = shop.getItemsByArtistAndYears("Queen", 1970, 1980);
    for (const auto& song : queen70s) {
        std::cout << "   - " << song->getTitle() << " (" << song->getYear() << ")\n";
    }
    
    // Весь каталог
    std::cout << "\n=== ПОЛНЫЙ КАТАЛОГ ===\n";
    shop.displayCatalog();
    
    return 0;
}
