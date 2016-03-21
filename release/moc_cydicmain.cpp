/****************************************************************************
** Meta object code from reading C++ file 'cydicmain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cydicmain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cydicmain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CyDicMain_t {
    QByteArrayData data[17];
    char stringdata0[341];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CyDicMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CyDicMain_t qt_meta_stringdata_CyDicMain = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CyDicMain"
QT_MOC_LITERAL(1, 10, 11), // "selectImage"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 24), // "on_listViewTitle_clicked"
QT_MOC_LITERAL(4, 48, 5), // "index"
QT_MOC_LITERAL(5, 54, 24), // "on_pushButtonNew_clicked"
QT_MOC_LITERAL(6, 79, 27), // "on_pushButtonDelete_clicked"
QT_MOC_LITERAL(7, 107, 28), // "on_pushButtonConfirm_clicked"
QT_MOC_LITERAL(8, 136, 32), // "on_pushButtonTitleInsert_clicked"
QT_MOC_LITERAL(9, 169, 13), // "onSelectImage"
QT_MOC_LITERAL(10, 183, 31), // "on_pushButtonBodyInsert_clicked"
QT_MOC_LITERAL(11, 215, 35), // "on_listWidgetBody_currentRowC..."
QT_MOC_LITERAL(12, 251, 10), // "currentRow"
QT_MOC_LITERAL(13, 262, 31), // "on_pushButtonFullScreen_clicked"
QT_MOC_LITERAL(14, 294, 26), // "on_pushButtonPrint_clicked"
QT_MOC_LITERAL(15, 321, 9), // "slotPrint"
QT_MOC_LITERAL(16, 331, 9) // "QPrinter*"

    },
    "CyDicMain\0selectImage\0\0on_listViewTitle_clicked\0"
    "index\0on_pushButtonNew_clicked\0"
    "on_pushButtonDelete_clicked\0"
    "on_pushButtonConfirm_clicked\0"
    "on_pushButtonTitleInsert_clicked\0"
    "onSelectImage\0on_pushButtonBodyInsert_clicked\0"
    "on_listWidgetBody_currentRowChanged\0"
    "currentRow\0on_pushButtonFullScreen_clicked\0"
    "on_pushButtonPrint_clicked\0slotPrint\0"
    "QPrinter*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CyDicMain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   75,    2, 0x08 /* Private */,
       5,    0,   78,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    1,   84,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    0,   88,    2, 0x08 /* Private */,
      15,    1,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,    2,

       0        // eod
};

void CyDicMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CyDicMain *_t = static_cast<CyDicMain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectImage(); break;
        case 1: _t->on_listViewTitle_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_pushButtonNew_clicked(); break;
        case 3: _t->on_pushButtonDelete_clicked(); break;
        case 4: _t->on_pushButtonConfirm_clicked(); break;
        case 5: _t->on_pushButtonTitleInsert_clicked(); break;
        case 6: _t->onSelectImage(); break;
        case 7: _t->on_pushButtonBodyInsert_clicked(); break;
        case 8: _t->on_listWidgetBody_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_pushButtonFullScreen_clicked(); break;
        case 10: _t->on_pushButtonPrint_clicked(); break;
        case 11: _t->slotPrint((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CyDicMain::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CyDicMain::selectImage)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CyDicMain::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CyDicMain.data,
      qt_meta_data_CyDicMain,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CyDicMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CyDicMain::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CyDicMain.stringdata0))
        return static_cast<void*>(const_cast< CyDicMain*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CyDicMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CyDicMain::selectImage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
