#include <iostream>
#include <string>

// Включаем все заголовки
#include "MusicItem.h"
#include "Song.h"
#include "Album.h"
#include "MusicShop.h"

int main() {
    std::cout << "Starting Music Store Program...\n";
    
    MusicShop shop;
    
    // Простые тестовые данные
    MediaFormat formats1[] = {FORMAT_CD, FORMAT_DIGITAL};
    MediaFormat formats2[] = {FORMAT_VINYL, FORMAT_DIGITAL};
    
    // Создаем пару песен
    Song* song1 = new Song(
        "Test Song 1",
        "Test Artist",
        2020,
        GENRE_ROCK,
        "Test Album",
        formats1, 2,
        "Shelf A, Box 1",
        3.5,
        "Test Writer"
    );
    shop.addItem(song1);
    
    Song* song2 = new Song(
        "Test Song 2", 
        "Test Artist",
        2021,
        GENRE_POP,
        "Test Album 2",
        formats2, 2,
        "Shelf B, Box 2",
        4.0,
        "Test Writer 2"
    );
    shop.addItem(song2);
    
    // Выводим информацию
    std::cout << "\n=== All Items ===\n";
    for (int i = 0; i < shop.getSize(); i++) {
        MusicItem* item = shop.getCatalog()[i];
        std::cout << item->getInfo() << "\n\n";
    }
    
    // Тест поиска по исполнителю
    std::cout << "\n=== Search by Artist ===\n";
    int resultCount = 0;
    MusicItem** results = shop.getByArtist("Test Artist", resultCount);
    for (int i = 0; i < resultCount; i++) {
        std::cout << "Found: " << results[i]->getTitle() << "\n";
    }
    delete[] results;
    
    // Тест местоположения
    std::cout << "\n=== Location Test ===\n";
    std::cout << "Location: " << shop.getLocation("Test Song 1") << "\n";
    
    std::cout << "\n=== Program Completed ===\n";
    return 0;
}