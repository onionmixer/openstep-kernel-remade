/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aace0. */
int __cdecl reserveDebuggerLock(int a1)
{
  int result; // eax
  volatile __int32 *v2; // edx

  result = dword_1E8700; /*0x1aace3*/
  if ( a1 == dword_1E8700 )
  {
    if ( byte_1E5154 )
    {
      return IOLog((int)"reserveDebuggerLock: already locked\n");
    }
    else
    {
      v2 = (volatile __int32 *)_kernDebuggerLock; /*0x1aad04*/
      do /*0x1aad1e*/
      {
        while ( *v2 ) /*0x1aad0c*/
          ; /*0x1aad0e*/
        result = _InterlockedExchange(v2, 1) ^ 1; /*0x1aad19*/
      }
      while ( !result ); /*0x1aad1e*/
      byte_1E5154 = 1; /*0x1aad20*/
    }
  }
  return result; /*0x1aad02*/
}
