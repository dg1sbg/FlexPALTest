#include <CoreFoundation/CoreFoundation.h>
#include <FlexPAL/FlexPALCInterface.h>

int main (int argc, const char * argv[]) 
{
  tFlexPALrc nRC = FLEXPAL_SUCCESS;
  
  void       * pFPCInstance = NULL;
  int          nNrDevices   = 0;
  
  uint32       nModel       = 0;
  uint32       nSerialNr    = 0;
  uint32       nFirmwareRev = 0;
  bool         bTRXOK       = false;
  bool         bRFIOOK      = false;
  bool         bPAOK        = false;
  bool         bRX2OK       = false;
  int          nRegion      = -1;
  bool         bStatus      = false;
  
  pFPCInstance = FlexPALGetInstance();
  
  FlexPALSetDebugLevel( pFPCInstance, 1 );
  
  nNrDevices = FlexPALGetNumberOfDevices( pFPCInstance );
  
  if( nNrDevices > 0 )
  {
    nRC = FlexPALSelectDeviceByID( pFPCInstance, 0 );

    nRC = FlexPALInitialize( pFPCInstance );
    nRC = FlexPALGetModel( pFPCInstance, &nModel );
    nRC = FlexPALGetSerialNum( pFPCInstance, &nSerialNr );
    
    nRC = FlexPALGetFirmwareRev( pFPCInstance, &nFirmwareRev );
    
    nRC = FlexPALGetTRXOK( pFPCInstance, &bTRXOK );
    nRC = FlexPALGetRFIOOK( pFPCInstance, &bRFIOOK );
    nRC = FlexPALGetPAOK( pFPCInstance, &bPAOK );
    nRC = FlexPALGetRX2OK( pFPCInstance, &bRX2OK );  

    nRC = FlexPALGetRegion( pFPCInstance, &nRegion );
    
    nRC = FlexPALSetStandby( pFPCInstance, true );

    //sleep( 3 );
    
    nRC = FlexPALSetATUEnable( pFPCInstance, true );

    nRC = FlexPALGetStatus( pFPCInstance, &bStatus );


  }
  
  return 0;
}
