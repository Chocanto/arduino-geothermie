#ifndef DB_INSTANCE_HPP 
#define DB_INSTANCE_HPP

class DBInstance {
    public:
        DBInstance();

        sendRequest(string req);

        getTableName();
    private:
        string tableName;
}

#endif
