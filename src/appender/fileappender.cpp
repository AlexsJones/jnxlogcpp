/*********************************************************************************
*     File Name           :     /home/anon/Code/jnxlogcpp/src/appender/fileappender.cpp
*     Created By          :     anon
*     Creation Date       :     [2016-01-14 18:37]
*     Last Modified       :     [2016-01-27 12:04]
*     Description         :
**********************************************************************************/

#include "fileappender.hpp"
#include <fstream>
using namespace std;

FileAppender::FileAppender(): BaseAppender("FileAppender") {

}
FileAppender::~FileAppender() {

}
void FileAppender::Emit(const stringstream& s) {

  ofstream osfile;
  osfile.open(_appenderInfo.LogPath,ios_base::app);
  osfile << s.str();
  osfile.close();
}
void FileAppender::AddAppenderInfo(const AppenderInfo appender) {

  _appenderInfo = appender;
}
