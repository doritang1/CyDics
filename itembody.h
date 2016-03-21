#ifndef ITEMBODY_H
#define ITEMBODY_H
#include <QString>

class ItemBody
{
public:
    ItemBody();
    //~ItemBody();
    void writeItem(const QString itemText, const int primaryKey = 0, const int foreignKey = 0);
    void readItem(QString &itemText, int &primaryKey, int &foreignKey);

    QString get_itemText();
    bool set_itemText(const QString itemText);

    int get_primaryKey();
    bool set_primaryKey(const int primaryKey);

    int get_foreignKey();
    bool set_foreignKey(const int foreignKey);

private:
    QString itemText;
    int primaryKey;
    int foreignKey;
};

#endif // ITEMBODY_H
