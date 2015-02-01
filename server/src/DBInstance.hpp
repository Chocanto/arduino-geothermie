#ifndef DB_INSTANCE_HPP 
#define DB_INSTANCE_HPP

#include <string>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;

class DBInstance {
    public:
        DBInstance(string tableName);

        ///
        /// \brief Return a PreparedStatement object with request
        /// \param req Request used by PreparedStatement
        /// \return PreparedStatement* New prepared statement with request
        ///
        PreparedStatement* getNewPreparedStatement(string req) const;

        string getTableName() const;
        ~DBInstance(){};
    
    protected:
        string tableName;
     
        ///
        /// \brief Recover data from database and create objects
        ///
        virtual void recoverPersisted(){};

        ///
        /// \brief Get the auto_increment id of the last inserted row
        ///
        /// \return int id
        int getLastInsertId();
        
};

#endif
