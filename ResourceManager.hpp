#pragma once

#include "Resource.hpp"

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <cmath>


class ResourceManager {
private:
    Resource* resource_ptr; 

public:
    ResourceManager() : resource_ptr(nullptr) {
        try {
            // Inicjalizuje obiekt 
            resource_ptr = new Resource(); 
            std::cout << "ResourceManager: Konstruktor domyślny." << std::endl;
        } catch (const std::bad_alloc& e) {
            std::cerr << "Błąd alokacji Resource: " << e.what() << std::endl;
            resource_ptr = nullptr;
        }
    }

    //Destruktor 
    ~ResourceManager() {
        if (resource_ptr != nullptr) {
            delete resource_ptr;
            resource_ptr = nullptr;
        }
        std::cout << "ResourceManager: Destruktor - zasób zwolniony." << std::endl;
    }

    // Konstruktor kopiujący 
    ResourceManager(const ResourceManager& other) : resource_ptr(nullptr) {
        if (other.resource_ptr) {
            resource_ptr = new Resource(*(other.resource_ptr)); 
        }
        std::cout << "ResourceManager: Konstruktor kopiujący (GŁĘBOKA KOPIA)." << std::endl;
    }

    // Operator przypisania kopiującego 
    ResourceManager& operator=(const ResourceManager& other) {
        std::cout << "ResourceManager: Operator przypisania kopiującego." << std::endl;
        if (this != &other) {
            if (resource_ptr != nullptr) {
                delete resource_ptr;
                resource_ptr = nullptr;
            }
            if (other.resource_ptr) {
                resource_ptr = new Resource(*(other.resource_ptr)); 
            }
        }
        return *this;
    }

    
    ResourceManager(ResourceManager&& other) noexcept = delete;

    
    ResourceManager& operator=(ResourceManager&& other) noexcept = delete;
    
    
    double get() const {
        if (resource_ptr) {
            return resource_ptr->get();
        }
        return NAN; 
    }
};
