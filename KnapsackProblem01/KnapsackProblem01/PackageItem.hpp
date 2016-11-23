#ifndef PACKAGE_ITEM_H
#define PACKAGE_ITEM_H

#include <string>

class PackageItem {
private:
    std::string name;
    int weight;
    int value;
public:
    PackageItem(std::string name, int weight, int value) {
        this->name = name;
        this->weight = weight;
        this->value = value;
    }
};


#endif /* PACKAGE_ITEM_H */