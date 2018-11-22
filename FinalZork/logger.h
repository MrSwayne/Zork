#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QDebug>


class Logger
{
public:
  template<typename T>
  static void log(T &obj, QString &text ){
      //prints info to console
    qDebug() << text
             << "\n============\n"
             << obj << endl;
  }
};

#endif // LOGGER_H
