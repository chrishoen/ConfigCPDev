#pragma once

/*==============================================================================
UDP receive  string socket.
UDP transmit string socket.
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "risThreadsSynch.h"
#include "risNetSettings.h"
#include "risSockets.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Ris
{
namespace Net
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
// Udp receive string socket. This class encapsulates a udp socket that
// receives strings.

class UdpRxStringSocket : public Sockets::BaseUdpSocket
{
private:
   typedef Sockets::BaseUdpSocket BaseClass;
public:

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Constants.

   // String size.
   static const int cStringSize = 2048;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   // Settings.
   Settings mSettings;

   // The recvfrom address is stored here.
   Sockets::SocketAddress mFromAddress;

   // Number of bytes received.
   int mRxLength;

   // True if the socket is valid.
   bool mValidFlag;

   // Metrics.
   int mRxCount;

   // Received string buffer.
   char mRxString[cStringSize];

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Constructor.
   UdpRxStringSocket();

   // Initialize variables.
   void initialize(Settings& aSettings);

   // Configure the socket. This does socket and bind calls.
   void configure();

   // Configure the socket to the local address at a port number.
   void configureLocal(int aPort);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Receive a string into the allocated receive buffer.
   // It returns true if successful.
   // The recvfrom address is stored in mFromAddress.
   bool doRecvString ();
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
// Udp transmit message socket. This class encapsulates a udp socket that
// transmits a string.

class UdpTxStringSocket : public Sockets::BaseUdpSocket
{
public:
   typedef Sockets::BaseUdpSocket BaseClass;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Constants.

   // String size.
   static const int cStringSize = 1000;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   // Settings.
   Settings mSettings;

   // The recvfrom address is stored here.
   Sockets::SocketAddress mFromAddress;

   // Number of bytes transmitted.
   int mTxLength;

   // True if the socket is valid.
   bool mValidFlag;

   // Metrics.
   int mTxCount;

   // If true then status prints are disabled.
   bool mPrintDisable;

   // Transmit mutex is used by doSendMsg for mutual exclusion.
   Threads::MutexSemaphore  mTxMutex;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Constructor.
   UdpTxStringSocket();

   // Initialize variables.
   void initialize(Settings& aSettings);

   // Configure the socket. This does socket and bind calls.
   void configure();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Send a string over the socket via a blocking send call.
   // It returns true if successful.
   // It is protected by the transmit mutex.
   bool doSendString(const char* aString);
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace
}//namespace

