#include "itembody.h"

ItemBody::ItemBody()
{

}

void ItemBody::writeItem(const QString itemText, const int primaryKey, const int foreignKey)
{
    this->itemText = itemText;
    this->primaryKey = primaryKey;
    this->foreignKey = foreignKey;
    return;
}

QString ItemBody::get_itemText()
{
    return this->itemText;
}

bool ItemBody::set_itemText(const QString itemText)
{
    this->itemText = itemText;
    return true;
}

int ItemBody::get_primaryKey()
{
    return this->primaryKey;
}

bool ItemBody::set_primaryKey(const int primaryKey)
{
    this->primaryKey = primaryKey;
    return true;
}


int ItemBody::get_foreignKey()
{
    return this->foreignKey;
}

bool ItemBody::set_foreignKey(const int foreignKey)
{
    this->foreignKey = foreignKey;
    return true;
}
