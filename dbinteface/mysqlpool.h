//
// Created by wj on 18-10-8.
//

#ifndef LOGINSERVER_MYSQLPOOL_H
#define LOGINSERVER_MYSQLPOOL_H
#include <mysql++/mysql++.h>
#include <unistd.h>


class MysqlPool : public mysqlpp::ConnectionPool {
public:
    MysqlPool(std::string db, std::string ip, std::string user, std::string pswd, int port=3306, int max_size=2,std::string charset="utf8") :
            db_(db),
            ip_(ip),
            user_(user),
            pswd_(pswd),
            port_(port),
            max_size_(max_size),
            m_charset(charset)
    {
        m_max_idle_time = 300;
    }

    ~MysqlPool() {
        clear();
    }

    mysqlpp::Connection *grab() {
        while (conns_in_use_ > max_size_) {
            sleep(1);
        }

        ++conns_in_use_;
        return mysqlpp::ConnectionPool::grab();
    }

    void release(const mysqlpp::Connection *pc) {
        mysqlpp::ConnectionPool::release(pc);
        --conns_in_use_;
    }


    void remove(const mysqlpp::Connection *pc) {
        mysqlpp::ConnectionPool::remove(pc);
    }

protected:
    virtual mysqlpp::Connection *create() {
        mysqlpp::Connection *coon = new mysqlpp::Connection();

        mysqlpp::SetCharsetNameOption *pOpt = new mysqlpp::SetCharsetNameOption(m_charset);
        //设置字符集
        coon->set_option(pOpt);
        coon->connect(db_.c_str(), ip_.c_str(), user_.c_str(), pswd_.c_str(), port_);
        return coon;
    }

    virtual void destroy(mysqlpp::Connection *pc) {
        delete pc;
    }

    virtual unsigned int max_idle_time() {
        return m_max_idle_time;
    }

private:
    std::string db_;
    std::string ip_;
    std::string user_;
    std::string pswd_;
    int port_;
    std::string m_charset;
    unsigned int m_max_idle_time;
    unsigned int conns_in_use_;
    int max_size_;

};
#endif //LOGINSERVER_MYSQLPOOL_H
