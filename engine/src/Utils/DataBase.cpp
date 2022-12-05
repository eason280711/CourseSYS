#include "DataBase.h"
#include "pch.h"
#include "Utils/Log.h"

namespace Engine {

    void DataBase::Init(std::string path)
    {
        Opt.create_if_missing = true;
        leveldb::Status status = leveldb::DB::Open(Opt, path, &db);
        if (!status.ok()) {
			ENGINE_CORE_ERROR("{0}", "DataBase is not open!");
        }
    }

    void DataBase::Del()
	{
		delete db;
	}

	void DataBase::iterate(std::function<void(leveldb::Iterator*)> fn)
	{
		leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());
		for (it->SeekToFirst(); it->Valid(); it->Next()) {
			fn(it);
		}
		delete it;
	}

    leveldb::Status DataBase::Write(std::string key, std::string value)
	{
		leveldb::Status status = db->Put(leveldb::WriteOptions(), key, value);
		return status;
	}
    leveldb::Status DataBase::Read(std::string key, std::string& value)
	{
		leveldb::Status status = db->Get(leveldb::ReadOptions(), key, &value);
		return status;
	}
}
