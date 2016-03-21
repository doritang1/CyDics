#include "itemtitle.h"

ItemTitle::ItemTitle()
{

}

void ItemTitle::writeItem(const QString itemText, const int primaryKey, const int foreignKey)
{
    this->itemText = itemText;
    this->primaryKey = primaryKey;
    this->foreignKey = foreignKey;
    return;
}

QString ItemTitle::get_itemText()
{
    return this->itemText;
}

bool ItemTitle::set_itemText(const QString itemText)
{
    this->itemText = itemText;
    return true;
}

int ItemTitle::get_primaryKey()
{
    return this->primaryKey;
}

bool ItemTitle::set_primaryKey(const int primaryKey)
{
    this->primaryKey = primaryKey;
    return true;
}

int ItemTitle::get_foreignKey()
{
    return this->foreignKey;
}

bool ItemTitle::set_foreignKey(const int foreignKey)
{
    this->foreignKey = foreignKey;
    return true;
}
