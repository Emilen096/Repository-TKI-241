#include "MusicItem.h"
#include "MusicShop.h"
#include <sstream>
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusicShopTests
{
    TEST_CLASS(MusicItemTests)
    {
    public:
        TEST_METHOD(MusicItemConstructor_ValidData_Success)
        {
            // Arrange & Act
            MusicItem item("Bohemian Rhapsody", "Queen", 1975, Genre::ROCK, 
                          "A Night at the Opera", MediaFormat::VINYL, 
                          29.99, "Стеллаж A, Полка 3");
            
            // Assert
            Assert::AreEqual(std::string("Bohemian Rhapsody"), item.getTitle());
            Assert::AreEqual(std::string("Queen"), item.getArtist());
            Assert::AreEqual(1975, item.getYear());
            Assert::AreEqual(Genre::ROCK, item.getGenre());
            Assert::AreEqual(std::string("A Night at the Opera"), item.getAlbum());
            Assert::AreEqual(MediaFormat::VINYL, item.getFormat());
            Assert::AreEqual(29.99, item.getPrice(), 0.001);
            Assert::AreEqual(std::string("Стеллаж A, Полка 3"), item.getLocation());
        }

        TEST_METHOD(MusicItemToString_ValidData_OutputsCorrectInfo)
        {
            // Arrange
            MusicItem item("Imagine", "John Lennon", 1971, Genre::POP, 
                          "Imagine", MediaFormat::CASSETTE, 
                          14.99, "Стеллаж C, Полка 2");
            
            // Act
            std::string result = item.toString();
            
            // Assert
            Assert::IsTrue(result.find("Название: Imagine") != std::string::npos);
            Assert::IsTrue(result.find("Исполнитель: John Lennon") != std::string::npos);
            Assert::IsTrue(result.find("Год: 1971") != std::string::npos);
            Assert::IsTrue(result.find("Альбом: Imagine") != std::string::npos);
            Assert::IsTrue(result.find("Цена: $14.99") != std::string::npos);
            Assert::IsTrue(result.find("Местоположение: Стеллаж C, Полка 2") != std::string::npos);
        }
    };

    TEST_CLASS(MusicShopTests)
    {
    public:
        TEST_METHOD(MusicShopDefaultConstructor_Success)
        {
            // Arrange & Act
            MusicShop shop;
            
            // Assert - магазин должен быть пустым
            // Проверим косвенно через методы поиска
            auto items = shop.getItemsByArtist("Test");
            Assert::AreEqual(0, (int)items.size());
        }

        TEST_METHOD(MusicShopAddItem_Success)
        {
            // Arrange
            MusicShop shop;
            auto item1 = std::make_shared<MusicItem>("Song1", "Artist1", 2000, 
                Genre::POP, "Album1", MediaFormat::CD, 10.0, "Location1");
            auto item2 = std::make_shared<MusicItem>("Song2", "Artist2", 2005, 
                Genre::ROCK, "Album2", MediaFormat::VINYL, 20.0, "Location2");
            
            // Act
            shop.addItem(item1);
            shop.addItem(item2);
            
            // Assert
            auto allItems = shop.findItems("", 0, "");
            Assert::AreEqual(2, (int)allItems.size());
        }

        TEST_METHOD(MusicShopGetItemsByArtist_Success)
        {
            // Arrange
            MusicShop shop;
            auto item1 = std::make_shared<MusicItem>("Song1", "Queen", 1975, 
                Genre::ROCK, "Album1", MediaFormat::CD, 10.0, "Loc1");
            auto item2 = std::make_shared<MusicItem>("Song2", "Queen", 1980, 
                Genre::ROCK, "Album2", MediaFormat::VINYL, 15.0, "Loc2");
            auto item3 = std::make_shared<MusicItem>("Song3", "Beatles", 1965, 
                Genre::POP, "Album3", MediaFormat::CASSETTE, 12.0, "Loc3");
            
            shop.addItem(item1);
            shop.addItem(item2);
            shop.addItem(item3);
            
            // Act
            auto queenSongs = shop.getItemsByArtist("Queen");
            auto beatlesSongs = shop.getItemsByArtist("Beatles");
            auto emptySongs = shop.getItemsByArtist("Unknown");
            
            // Assert
            Assert::AreEqual(2, (int)queenSongs.size());
            Assert::AreEqual(1, (int)beatlesSongs.size());
            Assert::AreEqual(0, (int)emptySongs.size());
            
            Assert::AreEqual(std::string("Song1"), queenSongs[0]->getTitle());
            Assert::AreEqual(std::string("Song3"), beatlesSongs[0]->getTitle());
        }

        TEST_METHOD(MusicShopGetItemLocation_Success)
        {
            // Arrange
            MusicShop shop;
            auto item = std::make_shared<MusicItem>("Hotel California", "Eagles", 
                1976, Genre::ROCK, "Hotel California", MediaFormat::CD, 
                19.99, "Стеллаж B, Полка 1");
            shop.addItem(item);
            
            // Act
            std::string location = shop.getItemLocation("Hotel California");
            std::string notFound = shop.getItemLocation("Unknown Song");
            
            // Assert
            Assert::AreEqual(std::string("Стеллаж B, Полка 1"), location);
            Assert::AreEqual(std::string("Произведение не найдено"), notFound);
        }

        TEST_METHOD(MusicShopGetFormatsByTitle_Success)
        {
            // Arrange
            MusicShop shop;
            auto item1 = std::make_shared<MusicItem>("Thriller", "Michael Jackson", 
                1982, Genre::POP, "Thriller", MediaFormat::CD, 24.99, "Loc1");
            auto item2 = std::make_shared<MusicItem>("Thriller", "Michael Jackson", 
                1982, Genre::POP, "Thriller", MediaFormat::VINYL, 34.99, "Loc2");
            auto item3 = std::make_shared<MusicItem>("Billie Jean", "Michael Jackson", 
                1982, Genre::POP, "Thriller", MediaFormat::DIGITAL, 9.99, "Loc3");
            
            shop.addItem(item1);
            shop.addItem(item2);
            shop.addItem(item3);
            
            // Act
            auto thrillerFormats = shop.getFormatsByTitle("Thriller");
            auto unknownFormats = shop.getFormatsByTitle("Unknown");
            
            // Assert
            Assert::AreEqual(2, (int)thrillerFormats.size());
            Assert::AreEqual(0, (int)unknownFormats.size());
            
            // Проверяем, что оба формата присутствуют
            bool hasCD = false, hasVinyl = false;
            for (const auto& format : thrillerFormats) {
                if (format == MediaFormat::CD) hasCD = true;
                if (format == MediaFormat::VINYL) hasVinyl = true;
            }
            Assert::IsTrue(hasCD);
            Assert::IsTrue(hasVinyl);
        }

        TEST_METHOD(MusicShopGetItemsByGenre_Success)
        {
            // Arrange
            MusicShop shop;
            auto item1 = std::make_shared<MusicItem>("Song1", "Artist1", 2000, 
                Genre::ROCK, "Album1", MediaFormat::CD, 10.0, "Loc1");
            auto item2 = std::make_shared<MusicItem>("Song2", "Artist2", 2005, 
                Genre::ROCK, "Album2", MediaFormat::VINYL, 20.0, "Loc2");
            auto item3 = std::make_shared<MusicItem>("Song3", "Artist3", 2010, 
                Genre::JAZZ, "Album3", MediaFormat::DIGITAL, 15.0, "Loc3");
            
            shop.addItem(item1);
            shop.addItem(item2);
            shop.addItem(item3);
            
            // Act
            auto rockSongs = shop.getItemsByGenre(Genre::ROCK);
            auto jazzSongs = shop.getItemsByGenre(Genre::JAZZ);
            auto popSongs = shop.getItemsByGenre(Genre::POP);
            
            // Assert
            Assert::AreEqual(2, (int)rockSongs.size());
            Assert::AreEqual(1, (int)jazzSongs.size());
            Assert::AreEqual(0, (int)popSongs.size());
            
            Assert::AreEqual(std::string("Song1"), rockSongs[0]->getTitle());
            Assert::AreEqual(std::string("Song3"), jazzSongs[0]->getTitle());
        }

        TEST_METHOD(MusicShopFindItems_Success)
        {
            // Arrange
            MusicShop shop;
            auto item1 = std::make_shared<MusicItem>("Song1", "Artist1", 2000, 
                Genre::POP, "AlbumA", MediaFormat::CD, 10.0, "Loc1");
            auto item2 = std::make_shared<MusicItem>("Song2", "Artist2", 2000, 
                Genre::ROCK, "AlbumA", MediaFormat::VINYL, 20.0, "Loc2");
            auto item3 = std::make_shared<MusicItem>("Song3", "Artist1", 2005, 
                Genre::POP, "AlbumB", MediaFormat::DIGITAL, 15.0, "Loc3");
            
            shop.addItem(item1);
            shop.addItem(item2);
            shop.addItem(item3);
            
            // Act & Assert
            // Поиск по названию
            auto byTitle = shop.findItems("Song1", 0, "");
            Assert::AreEqual(1, (int)byTitle.size());
            Assert::AreEqual(std::string("Song1"), byTitle[0]->getTitle());
            
            // Поиск по году
            auto byYear = shop.findItems("", 2000, "");
            Assert::AreEqual(2, (int)byYear.size());
            
            // Поиск по альбому
            auto byAlbum = shop.findItems("", 0, "AlbumA");
            Assert::AreEqual(2, (int)byAlbum.size());
            
            // Комбинированный поиск
            auto combined = shop.findItems("Song1", 2000, "AlbumA");
            Assert::AreEqual(1, (int)combined.size());
            
            // Поиск несуществующего
            auto notFound = shop.findItems("Unknown", 0, "");
            Assert::AreEqual(0, (int)notFound.size());
        }

        TEST_METHOD(MusicShopGetItemsByArtistAndYears_Success)
        {
            // Arrange
            MusicShop shop;
            auto item1 = std::make_shared<MusicItem>("Song1", "Queen", 1975, 
                Genre::ROCK, "Album1", MediaFormat::CD, 10.0, "Loc1");
            auto item2 = std::make_shared<MusicItem>("Song2", "Queen", 1980, 
                Genre::ROCK, "Album2", MediaFormat::VINYL, 15.0, "Loc2");
            auto item3 = std::make_shared<MusicItem>("Song3", "Queen", 1990, 
                Genre::POP, "Album3", MediaFormat::DIGITAL, 12.0, "Loc3");
            auto item4 = std::make_shared<MusicItem>("Song4", "Beatles", 1965, 
                Genre::POP, "Album4", MediaFormat::CASSETTE, 8.0, "Loc4");
            
            shop.addItem(item1);
            shop.addItem(item2);
            shop.addItem(item3);
            shop.addItem(item4);
            
            // Act
            auto queen70s = shop.getItemsByArtistAndYears("Queen", 1970, 1980);
            auto queen80s = shop.getItemsByArtistAndYears("Queen", 1980, 1990);
            auto beatles60s = shop.getItemsByArtistAndYears("Beatles", 1960, 1970);
            auto empty = shop.getItemsByArtistAndYears("Unknown", 2000, 2010);
            
            // Assert
            Assert::AreEqual(2, (int)queen70s.size()); // 1975 и 1980
            Assert::AreEqual(2, (int)queen80s.size()); // 1980 и 1990
            Assert::AreEqual(1, (int)beatles60s.size());
            Assert::AreEqual(0, (int)empty.size());
            
            // Проверяем, что правильные песни в правильных диапазонах
            bool has1975 = false, has1990 = false;
            for (const auto& song : queen70s) {
                if (song->getYear() == 1975) has1975 = true;
                if (song->getYear() == 1990) has1990 = true;
            }
            Assert::IsTrue(has1975);
            Assert::IsFalse(has1990); // 1990 не в диапазоне 1970-1980
        }

        TEST_METHOD(MusicShopDisplayCatalog_Success)
        {
            // Arrange
            MusicShop shop;
            auto item = std::make_shared<MusicItem>("Test Song", "Test Artist", 
                2020, Genre::POP, "Test Album", MediaFormat::CD, 
                9.99, "Test Location");
            shop.addItem(item);
            
            // Act & Assert
            // Просто проверяем, что функция выполняется без исключений
            try {
                shop.displayCatalog();
                Assert::IsTrue(true); // Если дошли сюда - успех
            } catch (...) {
                Assert::Fail(L"displayCatalog threw an exception");
            }
        }

        TEST_METHOD(MusicShopMultipleArtistsSameTitle_Success)
        {
            // Arrange
            MusicShop shop;
            auto item1 = std::make_shared<MusicItem>("Yesterday", "Beatles", 
                1965, Genre::POP, "Help!", MediaFormat::VINYL, 25.0, "Loc1");
            auto item2 = std::make_shared<MusicItem>("Yesterday", "Boyz II Men", 
                1994, Genre::R_AND_B, "Cooleyhighharmony", MediaFormat::CD, 15.0, "Loc2");
            
            shop.addItem(item1);
            shop.addItem(item2);
            
            // Act
            auto yesterdaySongs = shop.findItems("Yesterday", 0, "");
            
            // Assert
            Assert::AreEqual(2, (int)yesterdaySongs.size());
            
            bool hasBeatles = false, hasBoyz = false;
            for (const auto& song : yesterdaySongs) {
                if (song->getArtist() == "Beatles") hasBeatles = true;
                if (song->getArtist() == "Boyz II Men") hasBoyz = true;
            }
            Assert::IsTrue(hasBeatles);
            Assert::IsTrue(hasBoyz);
        }
    };

    TEST_CLASS(IntegrationTests)
    {
    public:
        TEST_METHOD(FullMusicShopSystem_Success)
        {
            // Arrange
            MusicShop shop;
            
            // Act - добавляем разнообразные музыкальные произведения
            shop.addItem(std::make_shared<MusicItem>("Bohemian Rhapsody", "Queen", 
                1975, Genre::ROCK, "A Night at the Opera", MediaFormat::VINYL, 
                29.99, "Стеллаж A, Полка 3"));
            
            shop.addItem(std::make_shared<MusicItem>("Hotel California", "Eagles", 
                1976, Genre::ROCK, "Hotel California", MediaFormat::CD, 
                19.99, "Стеллаж B, Полка 1"));
            
            shop.addItem(std::make_shared<MusicItem>("Thriller", "Michael Jackson", 
                1982, Genre::POP, "Thriller", MediaFormat::CD, 
                24.99, "Стеллаж A, Полка 1"));
            
            shop.addItem(std::make_shared<MusicItem>("Take Five", "Dave Brubeck", 
                1959, Genre::JAZZ, "Time Out", MediaFormat::VINYL, 
                34.99, "Стеллаж C, Полка 2"));
            
            // Assert - проверяем все функции системы
            
            // 1. Проверяем поиск по исполнителю
            auto queenSongs = shop.getItemsByArtist("Queen");
            Assert::AreEqual(1, (int)queenSongs.size());
            
            // 2. Проверяем местоположение
            std::string location = shop.getItemLocation("Hotel California");
            Assert::AreEqual(std::string("Стеллаж B, Полка 1"), location);
            
            // 3. Проверяем поиск по жанру
            auto rockSongs = shop.getItemsByGenre(Genre::ROCK);
            Assert::AreEqual(2, (int)rockSongs.size());
            
            // 4. Проверяем поиск по году
            auto songs1970s = shop.findItems("", 1975, "");
            Assert::IsTrue(songs1970s.size() >= 1);
            
            // 5. Проверяем поиск по исполнителю и годам
            auto songsByYears = shop.getItemsByArtistAndYears("Eagles", 1970, 1980);
            Assert::AreEqual(1, (int)songsByYears.size());
            
            // 6. Проверяем, что все произведения добавлены
            auto allSongs = shop.findItems("", 0, "");
            Assert::AreEqual(4, (int)allSongs.size());
        }

        TEST_METHOD(MusicShopComplexOperations_Success)
        {
            // Arrange
            MusicShop shop;
            
            // Добавляем несколько версий одного произведения
            shop.addItem(std::make_shared<MusicItem>("Imagine", "John Lennon", 
                1971, Genre::POP, "Imagine", MediaFormat::CASSETTE, 
                14.99, "Loc1"));
            
            shop.addItem(std::make_shared<MusicItem>("Imagine", "John Lennon", 
                1971, Genre::POP, "Imagine", MediaFormat::CD, 
                19.99, "Loc2"));
            
            shop.addItem(std::make_shared<MusicItem>("Imagine", "John Lennon", 
                1971, Genre::POP, "Imagine", MediaFormat::VINYL, 
                29.99, "Loc3"));
            
            // Act & Assert
            // Проверяем, что есть 3 носителя для "Imagine"
            auto formats = shop.getFormatsByTitle("Imagine");
            Assert::AreEqual(3, (int)formats.size());
            
            // Проверяем поиск по разным критериям
            auto byTitle = shop.findItems("Imagine", 0, "");
            Assert::AreEqual(3, (int)byTitle.size());
            
            auto byYear = shop.findItems("", 1971, "");
            Assert::AreEqual(3, (int)byYear.size());
            
            auto byAlbum = shop.findItems("", 0, "Imagine");
            Assert::AreEqual(3, (int)byAlbum.size());
            
            // Проверяем поиск по исполнителю
            auto byArtist = shop.getItemsByArtist("John Lennon");
            Assert::AreEqual(3, (int)byArtist.size());
            
            // Проверяем, что все произведения в одном жанре
            auto byGenre = shop.getItemsByGenre(Genre::POP);
            Assert::IsTrue(byGenre.size() >= 3);
        }
    };
}
