/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aae68. */
void __cdecl -[IOEthernet releaseDebuggerLock](IOEthernet *self, SEL a2)
{
  if ( self == (IOEthernet *)dword_1E8700 ) /*0x1aae73*/
  {
    if ( byte_1E5154 ) /*0x1aae7c*/
    {
      _InterlockedExchange((volatile __int32 *)_kernDebuggerLock, 0); /*0x1aae85*/
      byte_1E5154 = 0; /*0x1aae87*/
      splx(dword_1E8704); /*0x1aae95*/
    }
  }
}
