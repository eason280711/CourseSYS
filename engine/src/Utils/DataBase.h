#pragma once
#include "Core/Core.h"
#include "leveldb/db.h"
#include "pch.h"

namespace Engine {
    class DataBase
    {
    public:
        ~DataBase() {};

        void Init(std::string path);
        void Del();
		
        void iterate(std::function<void(leveldb::Iterator*)> fn);
        leveldb::Status Write(std::string key, std::string value);
        leveldb::Status Read(std::string key, std::string& value);

        leveldb::DB*& GetDB() {return db;}
        leveldb::Options& GetOpt() {return Opt;}
    private:
        leveldb::DB* db;
        leveldb::Options Opt;
    };
}