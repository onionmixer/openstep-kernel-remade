/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aae10. */
void __cdecl -[IOEthernet reserveDebuggerLock](IOEthernet *self, SEL a2)
{
  volatile __int32 *v2; // edx

  if ( self == (IOEthernet *)dword_1E8700 )
  {
    if ( byte_1E5154 )
    {
      IOLog((int)"reserveDebuggerLock: already locked\n");
    }
    else
    {
      dword_1E8704 = debuggerIplRoutine(); /*0x1aae3b*/
      v2 = (volatile __int32 *)_kernDebuggerLock; /*0x1aae40*/
      do /*0x1aae5a*/
      {
        while ( *v2 ) /*0x1aae48*/
          ; /*0x1aae4a*/
      }
      while ( _InterlockedExchange(v2, 1) == 1 ); /*0x1aae5a*/
      byte_1E5154 = 1; /*0x1aae5c*/
    }
  }
}
