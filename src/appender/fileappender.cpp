/*********************************************************************************
 *     File Name           :     /home/anon/Code/jnxlogcpp/src/appender/fileappender.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 18:37]
 *     Last Modified       :     [2016-01-27 14:47]
 *     Description         :
 **********************************************************************************/

#include "fileappender.hpp"
#include <fstream>
using namespace std;

FileAppender::FileAppender(string logpath): BaseAppender("FileAppender") {
  _logPath = logpath;
}
FileAppender::~FileAppender() {

}
void FileAppender::Emit(const stringstream& s) {
  if(!_logPath.empty()) {
    ofstream osfile;
    osfile.open(_logPath,ios_base::app);
    osfile << s.str();
    osfile.close();
  }
}
