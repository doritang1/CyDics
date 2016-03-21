#ifndef ITEMTITLE_H
#define ITEMTITLE_H
#include <QString>

//향후 상속으로 title, body, example 데이터를 모두 표현하도록 수정 요망
class ItemTitle
{
public:
    ItemTitle();
    //~ItemTitle();
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

#endif // ITEMTITLE_H
