/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aad2c. */
int __cdecl releaseDebuggerLock(int a1)
{
  int result; // eax

  result = dword_1E8700; /*0x1aad2f*/
  if ( a1 == dword_1E8700 ) /*0x1aad37*/
  {
    if ( byte_1E5154 ) /*0x1aad40*/
    {
      result = _kernDebuggerLock; /*0x1aad42*/
      _InterlockedExchange((volatile __int32 *)_kernDebuggerLock, 0); /*0x1aad49*/
      byte_1E5154 = 0; /*0x1aad4b*/
    }
  }
  return result; /*0x1aad54*/
}
