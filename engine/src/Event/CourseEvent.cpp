#include "CourseEvent.h"
#include "Utils/DataBase.h"
#include "Config/config.h"
#include "Utils/Log.h"
#include "pch.h"

namespace Engine {
    
    DataBase CourseDB;
    DataBase StudentDB;

    void DBoper_Course(std::function<void(void)> fn)
    {
        CourseDB.Init(ROOT + std::string("/engine/server/db/course"));

        CourseDB.Write("0848","INTRODUCTION TO DATA MINING");
        CourseDB.Write("3803","SOFTWARE ENGINEERING PRACTICES");
        CourseDB.Write("0852","PROGRAMMING APPLICATION PRACTICAL");
        CourseDB.Write("0848","INTRODUCTION TO BIG DATA ANALYSIS");
        CourseDB.Write("3555","CITIZEN PARTICIPATION");
        CourseDB.Write("3050","THEORY AND PRACTICE OF EDUCATION");
        CourseDB.Write("1387","THE EXPERIMENT OF MICRO-PROCESSOR SYSTEM");

        std::cout << "--------------CID/Course--------------" << std::endl;

        CourseDB.iterate([&](leveldb::Iterator* it) {
            std::cout << it->key().ToString() << ": " << it->value().ToString() << std::endl;
        });

        std::cout << "--------------CID/Course--------------" << std::endl;

        std::cout << std::endl;

        StudentDB.Init(ROOT + std::string("/engine/server/db/student"));

        std::cout << "--------------Acc/Courses--------------" << std::endl;
        StudentDB.iterate([&](leveldb::Iterator* it) {
            std::cout << it->key().ToString() << " | " << it->value().ToString() << std::endl;
        });
        std::cout << "--------------Acc/Courses--------------" << std::endl;

        fn();

        CourseDB.Del();
        StudentDB.Del();
    }
	
    bool AddCourseEvent::Handle()
    {
        bool Suc = true;
        DBoper_Course([&](){
            std::string Acc,CID;
            std::cout << "Please input CID:" << std::endl;

            std::cout << "Account: ";
            std::cin >> Acc;
            
            std::cout << "CID: ";
            std::cin >> CID;

            std::string check = "";

            CourseDB.iterate([&](leveldb::Iterator* it) {
                if(it->key().ToString() == CID)
                {
                    check = it->value().ToString();
                }
            });

            if(check == "")
            {
                ENGINE_CORE_WARN("{0}", "CID NOT FOUND!");
                Suc = false;
                return;
            }

            std::string val = "";

            StudentDB.iterate([&](leveldb::Iterator* it) {
                if(it->key().ToString() == Acc)
                {
                    val = it->value().ToString();
                }
            });

            if(val == "")
                StudentDB.Write(Acc,"");
            
            val += CID + " ";
            StudentDB.Write(Acc,val);

        });
        return Suc;
    }

    bool GetCourseInfoEvent::Handle()
    {
        bool Suc = true;
        DBoper_Course([&](){
            std::string CID;
            std::cout << "Please input CID:" << std::endl;

            std::cout << "CID: ";
            std::cin >> CID;

            std::string check = "";

            CourseDB.iterate([&](leveldb::Iterator* it) {
                if(it->key().ToString() == CID)
                {
                    check = it->value().ToString();
                }
            });

            if(check == "")
            {
                ENGINE_CORE_WARN("{0}", "CID NOT FOUND!");
                Suc = false;
                return;
            }
            std::cout << "[ " + CID +" ] " + check << std::endl; 
        });
        return Suc;
    }
    
    bool GetOwnCourseEvent::Handle()
    {
        bool Suc = true;
        DBoper_Course([&](){
            std::string Acc;
            std::cout << "Please input Account:" << std::endl;

            std::cout << "Account: ";
            std::cin >> Acc;

            std::string check;

            StudentDB.iterate([&](leveldb::Iterator* it) {
                if(it->key().ToString() == Acc)
                {
                    check = it->value().ToString();
                }
            });

            if(check == "")
            {
                ENGINE_CORE_WARN("{0}", "Acc NOT FOUND!");
                Suc = false;
                return;
            }

            std::stringstream ss(check);
            std::string tmp;
            std::cout << "--------------Course--------------" << std::endl;
            while(std::getline(ss,tmp,' '))
            {
                std::string name;
                if(tmp.size() > 0)
                {
                    CourseDB.iterate([&](leveldb::Iterator* it) {
                        if(it->key().ToString() == tmp)
                        {
                             name = it->value().ToString();
                        }
                    });
                    std::cout << "[ " + tmp +" ] " + name << std::endl; 
                }
            }
            std::cout << "--------------Course--------------" << std::endl;

        });
        return Suc;
    }

    bool SearchCourseEvent::Handle()
    {
        bool Suc = true;
        DBoper_Course([&](){
            std::string CID;
            std::cout << "Please input CID:" << std::endl;

            std::cout << "CID: ";
            std::cin >> CID;

            std::string check = "";

            CourseDB.iterate([&](leveldb::Iterator* it) {
                if(it->key().ToString() == CID)
                {
                    check = it->value().ToString();
                }
            });

            if(check == "")
            {
                ENGINE_CORE_WARN("{0}", "CID NOT FOUND!");
                Suc = false;
                return;
            }
            std::cout << "[ " + CID +" ] " + check << std::endl; 
        });
        return Suc;
    }
}