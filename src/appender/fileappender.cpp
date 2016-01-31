/*********************************************************************************
 *     File Name           :     /home/anon/Code/jnxlogcpp/src/appender/fileappender.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 18:37]
 *     Last Modified       :     [2016-01-29 17:48]
 *     Description         :
 **********************************************************************************/

#include "fileappender.hpp"
#include <fstream>
using namespace std;

FileAppender::FileAppender(string logpath): BaseAppender("FileAppender") {
  _logPath = logpath;
  if(_logPath.empty()) {

  }
  locker = new mutex();
}
FileAppender::~FileAppender() {
  delete locker;
}
void FileAppender::Emit(const stringstream& s) {
    ofstream osfile;
    
    lock_guard<mutex> lock(*locker);
    osfile.open(_logPath,ios_base::app);
    osfile << s.str();
    osfile.close();
}
