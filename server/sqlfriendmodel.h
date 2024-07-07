#ifndef SQLFRIENDMODEL_H
#define SQLFRIENDMODEL_H

#include <QObject>
#include <QtSql/QSqlTableModel>
#include <QJsonArray>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>

class SqlFriendModel : public QSqlTableModel {
    Q_OBJECT
public:
    SqlFriendModel(QObject *parent, QSqlDatabase db);

    ~SqlFriendModel();

    bool addFriend(const int &aID, const int &bID);

    void delFriend(const int &aID, const int &bID);

    QByteArray friendList(const int &ID);

    void
    sendMessage(const int &sendID, const int &receiveID, const int &type, const int &datetime, const QString &message);

    QByteArray messageList(const int &aID, const int &bID);
};

#endif // SQLFRIENDSMODEL_H
