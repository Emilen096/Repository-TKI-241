#ifndef MUSICSHOP_H
#define MUSICSHOP_H

#include "MusicItem.h"
#include "Song.h"
#include "Album.h"

class MusicShop {
private:
    MusicItem** catalog;
    int capacity;
    int size;
    
    void resize() {
        capacity *= 2;
        MusicItem** newCatalog = new MusicItem*[capacity];
        
        for (int i = 0; i < size; i++) {
            newCatalog[i] = catalog[i];
        }
        
        delete[] catalog;
        catalog = newCatalog;
    }
    
public:
    MusicShop() : capacity(10), size(0) {
        catalog = new MusicItem*[capacity];
    }
    
    ~MusicShop() {
        for (int i = 0; i < size; i++) {
            delete catalog[i];
        }
        delete[] catalog;
    }
    
    void addItem(MusicItem* item) {
        if (size >= capacity) {
            resize();
        }
        catalog[size++] = item;
    }
    
    int getSize() const { return size; }
    MusicItem** getCatalog() const { return catalog; }
    
    // Методы поиска
    MusicItem** getByArtist(const std::string& artist, int& resultCount) const {
        MusicItem** result = new MusicItem*[size];
        resultCount = 0;
        
        for (int i = 0; i < size; i++) {
            if (catalog[i]->getArtist() == artist) {
                result[resultCount++] = catalog[i];
            }
        }
        
        return result;
    }
    
    std::string getLocation(const std::string& title) const {
        for (int i = 0; i < size; i++) {
            if (catalog[i]->getTitle() == title) {
                return catalog[i]->getLocation();
            }
        }
        return "Not found";
    }
    
    MediaFormat* getFormats(const std::string& title, int& formatsCount) const {
        for (int i = 0; i < size; i++) {
            if (catalog[i]->getTitle() == title) {
                formatsCount = catalog[i]->getFormatsCount();
                MediaFormat* result = new MediaFormat[formatsCount];
                
                for (int j = 0; j < formatsCount; j++) {
                    result[j] = catalog[i]->getFormats()[j];
                }
                return result;
            }
        }
        
        formatsCount = 0;
        return NULL;
    }
    
    MusicItem** getByGenre(Genre genre, int& resultCount) const {
        MusicItem** result = new MusicItem*[size];
        resultCount = 0;
        
        for (int i = 0; i < size; i++) {
            if (catalog[i]->getGenre() == genre) {
                result[resultCount++] = catalog[i];
            }
        }
        
        return result;
    }
    
    MusicItem** findByYear(int year, int& resultCount) const {
        MusicItem** result = new MusicItem*[size];
        resultCount = 0;
        
        for (int i = 0; i < size; i++) {
            if (catalog[i]->getYear() == year) {
                result[resultCount++] = catalog[i];
            }
        }
        
        return result;
    }
    
private:
    MusicShop(const MusicShop&);
    MusicShop& operator=(const MusicShop&);
};

#endif