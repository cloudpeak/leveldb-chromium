// Copyright (c) 2012 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>

#include "base/at_exit.h"
#include "leveldb/dumpfile.h"
#include "leveldb/env.h"
#include "leveldb/status.h"
#include "leveldb/db.h"


int main(int argc, char** argv) {
  base::AtExitManager manager;
  // Set up database connection information and open database
  leveldb::DB* db = NULL;
  leveldb::Options options;
  options.create_if_missing = true;

  leveldb::Status status = leveldb::DB::Open(options, "./testdb", &db);

  if (false == status.ok()) {
    std::cerr << "Unable to open/create test database './testdb'" << std::endl;
    std::cerr << status.ToString() << std::endl;
    return -1;
  }

  // Add 256 values to the database
  //leveldb::WriteOptions writeOptions;
  //for (unsigned int i = 0; i < 1024* 128; ++i) {
  //  std::ostringstream keyStream;
  //  keyStream << "key" << i;

  //  std::ostringstream valueStream;
  //  valueStream << "Test data value: " << i;

  //  db->Put(writeOptions, keyStream.str(), valueStream.str());
  //}

  // Iterate over each item in the database and print them
  leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());
  delete it;

  //for (it->SeekToFirst(); it->Valid(); it->Next()) {
  //  std::cout << it->key().ToString() << " : "
  //            << it->value().ToString() << std::endl;
  //}

  //if (false == it->status().ok()) {
  //  std::cerr << "An error was found during the scan" << std::endl;
  //  std::cerr << it->status().ToString() << std::endl;
  //}

  db->Put(leveldb::WriteOptions(), "foo", "bar");
  std::string bar;
  while (1) {
    db->Get(leveldb::ReadOptions(), "key0", &bar);
  }


  // Close the database
  delete db;
  std::cout << "all done\n";
}