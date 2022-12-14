#ifndef EMPLOYEEDATAMODEL_H
#define EMPLOYEEDATAMODEL_H

#include <QAbstractListModel>
#include <qdebug.h>
#include "common.h"
#include <cstring>

// IPC
#include <sys/ipc.h>
#include <sys/shm.h>

class EmployeeDataModel : public QAbstractListModel
{
Q_OBJECT
signals:

public:
    explicit EmployeeDataModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    // toan4.nguyen:
    enum EMPLOYEE_DATA_ROLES {
        EMPLOYEE_DATA_ROLES_ID = Qt::UserRole + 1,
        EMPLOYEE_DATA_ROLES_NAME,
        EMPLOYEE_DATA_ROLES_AVERAGE_SCORE,
        EMPLOYEE_DATA_ROLES_IS_SELECTED
    };

    void init();

    Q_INVOKABLE void loadEmployeeListToHMI();

private:
    QVector<EMPLOYEE_LIST_ITEM_T> vEmployeeList;
};



class EmployeeDataDetailModel : public QAbstractListModel
{
Q_OBJECT

public slots:
    void slotUpdateScoreModel(const int &asmScore, const int &cppScore, const int &jsScore, const int &qmlScore, const int &openglScore);

public:
    explicit EmployeeDataDetailModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    // toan4.nguyen:
    enum EMPLOYEE_DATA_ROLES {
        EMPLOYEE_DATA_DETAIL_ROLES_SCORE = Qt::UserRole + 1,
    };

    void init();

    Q_INVOKABLE void loadScoresToHMI(const QString &name);

private:
    QVector<int> vEmployeeScore;
};

#endif // EMPLOYEEDATAMODEL_H
