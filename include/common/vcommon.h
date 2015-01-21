// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.0.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_COMMON_H__
#define __V_COMMON_H__

#define WIN32_LEAN_AND_MEAN
#include <QtCore>
// #include <VDesign> // gilgil temp 2014.11.27
#include <VSystem>
#ifdef WIN32
#include <VWindows>
#endif // WIN32
#ifdef linux
#include <VLinux>
#endif // linux

// ----------------------------------------------------------------------------
// VDream Version
// ----------------------------------------------------------------------------
extern const char* VDREAM_VERSION;

// ----------------------------------------------------------------------------
// Common Define
// ----------------------------------------------------------------------------
#ifndef SAFE_DELETE
#define SAFE_DELETE(A) { if(A != NULL) { delete A; A = NULL; } }
#endif // SAFE_DELETE

#ifndef SAFE_FREE
#define SAFE_FREE(A)   { if(A != NULL) { free(A); A = NULL; } }
#endif // SAFE_FREE

// ----------------------------------------------------------------------------
// Class
// ----------------------------------------------------------------------------
QString getClassName(const char* value);
// #define IS_CLASS(obj, type) (dynamic_cast<type>(obj)!=NULL) // gilgil temp 2014.12.28
#define CLASS_NAME(obj)     getClassName(typeid(obj).name())

// ----------------------------------------------------------------------------
// Constant
// ----------------------------------------------------------------------------
namespace vd
{
  static const int      DEFAULT_BUF_SIZE          = 65536;  // bytes
  static const VTimeout DEFAULT_TIMEOUT           = 10000; // 10 sec
  static const int      DEFAULT_PORT              = 10065;
  static const int      DEFAULT_MEDIAGATEWAY_PORT = 10066;
};

// ----------------------------------------------------------------------------
// VState
// ----------------------------------------------------------------------------
class VState
{
public:
  enum _VState
  {
    None,    // 0
    Closed,  // 1
    Opening, // 2
    Opened,  // 3
    Closing  // 4
  };

protected:
  _VState value;

public:
  VState()                    {                      } // default ctor
  VState(const _VState value) { this->value = value; } // conversion ctor
  operator _VState() const    { return value;        } // cast operator

public:
  VState(const QString s);
  QString str() const;
};

// ----- gilgil temp 2014.12.28 -----
/*
// ----------------------------------------------------------------------------
// VMode
// ----------------------------------------------------------------------------
class VMode
{
  enum _VMode
  {
    None,     // 0
    Read,     // 1
    Write,    // 2
    ReadWrite // 3
  };

protected:
  _VMode value;

public:
  VMode()                   {                      } // default ctor
  VMode(const _VMode value) { this->value = value; } // conversion ctor
  operator _VMode() const   { return value;        } // cast operator

public:
  VMode(const QString s);
  QString str() const;
};
*/
// ----------------------------------

#endif // __V_COMMON_H__
