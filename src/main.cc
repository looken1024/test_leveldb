#include <iostream>
#include <string>
#include "leveldb/db.h"

int main() {
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    
    // 打开数据库
    leveldb::Status status = leveldb::DB::Open(options, "./testdb", &db);
    if (!status.ok()) {
        std::cerr << "无法打开数据库: " << status.ToString() << std::endl;
        return 1;
    }
    
    // 写入数据
    std::string key = "name";
    std::string value = "LevelDB";
    status = db->Put(leveldb::WriteOptions(), key, value);
    if (!status.ok()) {
        std::cerr << "写入失败: " << status.ToString() << std::endl;
        delete db;
        return 1;
    }
    
    // 读取数据
    std::string read_value;
    status = db->Get(leveldb::ReadOptions(), key, &read_value);
    if (status.ok()) {
        std::cout << "读取成功: " << read_value << std::endl;
    } else {
        std::cerr << "读取失败: " << status.ToString() << std::endl;
    }
    
    // 删除数据
    status = db->Delete(leveldb::WriteOptions(), key);
    if (!status.ok()) {
        std::cerr << "删除失败: " << status.ToString() << std::endl;
    }
    
    // 关闭数据库
    delete db;
    return 0;
}
