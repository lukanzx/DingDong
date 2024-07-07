#ifndef SQLACCOUNTMODEL_H
#define SQLACCOUNTMODEL_H

#include <QObject>
#include <QtSql/QSqlTableModel>
#include <QJsonArray>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>

class SqlAccountModel : public QSqlTableModel {
    Q_OBJECT
public:
    SqlAccountModel(QObject *parent, QSqlDatabase db);

    ~SqlAccountModel();

    QByteArray addUserAccount(const QString &userName, const QString &userPassword);

    QByteArray checkAccount(const int &userID, const QString &userPassword);

    QByteArray userInfo(const int &userID);

    void updateIcon(const int &userID, const QString &iconURL);

    void
    updateUserInfo(const int &userID, const QString &name, const int &gender, const QString &birth, const QString &area,
                   const QString &education, const QString &signature);

    QByteArray messageList(const int &ID);
};

#endif // SQLACCOUNTMODEL_H
