#ifndef PACKAGE_ITEM_H
#define PACKAGE_ITEM_H


class PackageItem {
public:
    int id;
    int weight;
    int value;
    PackageItem(int id, int weight, int value) {
        this->id = id;
        this->weight = weight;
        this->value = value;
    }
};


#endif /* PACKAGE_ITEM_H */