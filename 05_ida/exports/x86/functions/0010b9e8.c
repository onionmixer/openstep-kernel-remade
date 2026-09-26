/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10b9e8. */
__int32 __cdecl thread_psignal(int a1, unsigned int a2)
{
  __int32 result; // eax
  int v3; // ebx
  int v4; // ecx
  volatile __int32 *v5; // edx
  int v6; // [esp+0h] [ebp-8h]

  result = a2; /*0x10b9f0*/
  if ( a2 <= 0x20 ) /*0x10b9f6*/
  {
    v3 = 1 << (a2 - 1); /*0x10ba00*/
    if ( (v3 & 0x1EF8) == 0 ) /*0x10ba08*/
    {
      printf("signal = %d\n", v6); /*0x10ba0f*/
      panic(aThreadPsignalS); /*0x10ba19*/
    }
    result = *(_DWORD *)(a1 + 12); /*0x10ba1e*/
    v4 = *(_DWORD *)(result + 60); /*0x10ba21*/
    if ( (v3 & *(_DWORD *)(v4 + 32)) == 0 || (*(_BYTE *)(v4 + 40) & 0x10) != 0 ) /*0x10ba2d*/
    {
      v5 = (volatile __int32 *)(v4 + 112); /*0x10ba2f*/
      do /*0x10ba46*/
      {
        while ( *v5 ) /*0x10ba34*/
          ; /*0x10ba36*/
      }
      while ( _InterlockedExchange(v5, 1) == 1 ); /*0x10ba46*/
      *(_DWORD *)(*(_DWORD *)(a1 + 132) + 124) |= v3; /*0x10ba4e*/
      return _InterlockedExchange((volatile __int32 *)(v4 + 112), 0); /*0x10ba53*/
    }
  }
  return result; /*0x10ba59*/
}
