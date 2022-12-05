#include "UserEvent.h"
#include "Utils/DataBase.h"
#include "Config/config.h"
#include "Utils/Log.h"
#include "pch.h"

namespace Engine {

    DataBase UserDB;

    void DBoper_User(std::string first,std::string second,std::function<void(std::string,std::string)> fn)
    {
        UserDB.Init(ROOT + std::string("/engine/server/db/user"));

        std::cout << "--------------Acc/Pass--------------" << std::endl;

        UserDB.iterate([](leveldb::Iterator* it) {
            std::cout << it->key().ToString() << ": " << it->value().ToString() << std::endl;
        });

        std::cout << "--------------Acc/Pass--------------" << std::endl;

        std::string account,password;
        std::cout << "Please input "+ first + "/" + second+ ":" << std::endl;
        
        std::cout << first+": ";
        std::cin >> account;

        std::cout << second+": ";
        std::cin >> password;

        fn(account,password);

        UserDB.Del();
    }
	
    bool UserLogInEvent::Handle()
    {
        bool Login = false;
        DBoper_User("Account","Password",[&](std::string acc,std::string pass){
            bool check = false;
            UserDB.iterate([&](leveldb::Iterator* it) {
                if(it->key().ToString() == acc && it->value().ToString() == pass)
                {
                    check = true;
                }
            });

            if(check)
            {
                ENGINE_CORE_INFO("{0}", "Success Login!");
                Login = true;
            }
            else ENGINE_CORE_WARN("{0}", "Account or Password Wrong!");

        });
        return Login;
    }

    bool UserSignUpEvent::Handle()
    {
        bool Signed = false;
        DBoper_User("Account","Password",[&](std::string acc,std::string pass){
            bool check = false;
            UserDB.iterate([&](leveldb::Iterator* it) {
                if(it->key().ToString() != acc)
                {
                    check = true;
                }
            });

            if(check)
            {
                UserDB.Write(acc,pass);
                ENGINE_CORE_INFO("{0}", "Success Signed Up!");
                Signed = true;
            }
            else ENGINE_CORE_WARN("{0}", "Account Repeat! Failed Signed Up!");

        });
        return Signed;
    }
    
    bool UserRePassEvent::Handle()
    {
        bool Check = false;
        std::string key;

        DBoper_User("Account","Password",[&](std::string acc,std::string pass){
            bool check = false;
            UserDB.iterate([&](leveldb::Iterator* it) {
                if(it->key().ToString() == acc && it->value().ToString() == pass)
                {
                    check = true;
                }
            });

            if(check)
            {
                Check = true;
                key = acc;
            }
        });

        if(Check)
        {
            std::string password,r;
            std::cout << "Please input New PassWord"<< std::endl;
            
            std::cout << "New PassWord : ";
            std::cin >> password;

            std::cout << "Repeat again: ";
            std::cin >> r;

            if(r == password)
            {
                UserDB.Write(key,password);
                return true;
            }
            else return false;
        }
        
        return false;
    }

    bool UserFGPassEvent::Handle()
    {
        ENGINE_CORE_WARN("{0}", "Comming Soon!");
        return true;
    }

    bool QuitEvent::Handle()
    {
        return true;
    }
}