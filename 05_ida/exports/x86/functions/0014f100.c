/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14f100. */
_BOOL4 __cdecl ipc_right_copyin_check(int a1, int a2, int *a3, int a4)
{
  int v4; // ebx
  _BOOL4 result; // eax
  int v6; // ecx
  int v7; // eax

  v4 = *a3; /*0x14f10b*/
  switch ( a4 ) /*0x14f119*/
  {
    case 16: /*0x14f119*/
    case 20: /*0x14f119*/
    case 21: /*0x14f119*/
      return (v4 & 0x20000) != 0; /*0x14f13e*/
    case 17: /*0x14f119*/
    case 18: /*0x14f119*/
    case 19: /*0x14f119*/
      if ( (v4 & 0x100000) != 0 ) /*0x14f14a*/
        return 1; /*0x14f14a*/
      if ( (v4 & 0x50000) == 0 ) /*0x14f152*/
        return 0; /*0x14f152*/
      v6 = a3[1]; /*0x14f154*/
      do /*0x14f16a*/
      {
        while ( *(_DWORD *)v6 ) /*0x14f158*/
          ; /*0x14f15a*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x14f16a*/
      v7 = *(_DWORD *)(v6 + 8) >> 31; /*0x14f16f*/
      _InterlockedExchange((volatile __int32 *)v6, 0); /*0x14f174*/
      if ( v7 ) /*0x14f178*/
      {
        if ( a4 == 18 ) /*0x14f187*/
        {
          if ( (v4 & 0x40000) == 0 ) /*0x14f18f*/
            return 0; /*0x14f18f*/
        }
        else if ( (v4 & 0x10000) == 0 ) /*0x14f19a*/
        {
          return 0; /*0x14f19a*/
        }
      }
      else if ( (v4 & 0x400000) != 0 ) /*0x14f180*/
      {
        return 0; /*0x14f142*/
      }
      return 1;
    default:
      panic(aIpcRightCopyin); /*0x14f1a5*/
      return result; /*0x14f1a5*/
  }
}
