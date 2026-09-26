/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14bc64. */
__int32 __cdecl ipc_object_copyin_from_kernel(int a1, int a2)
{
  __int32 result; // eax

  result = a2 - 5; /*0x14bc6d*/
  switch ( a2 ) /*0x14bc79*/
  {
    case 5: /*0x14bc79*/
    case 16: /*0x14bc79*/
      do /*0x14bcd6*/
      {
        while ( *(_DWORD *)a1 ) /*0x14bcc4*/
          ; /*0x14bcc6*/
      }
      while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14bcd6*/
      *(_DWORD *)(a1 + 24) = 0; /*0x14bcd8*/
      *(_DWORD *)(a1 + 16) = 0; /*0x14bcdf*/
      *(_DWORD *)(a1 + 12) = 0; /*0x14bce6*/
      return _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14bce6*/
    case 6: /*0x14bc79*/
    case 19: /*0x14bc79*/
      do /*0x14bd0a*/
      {
        while ( *(_DWORD *)a1 ) /*0x14bcf8*/
          ; /*0x14bcfa*/
      }
      while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14bd0a*/
      if ( *(int *)(a1 + 8) < 0 ) /*0x14bd10*/
        ++*(_DWORD *)(a1 + 28); /*0x14bd12*/
      ++*(_DWORD *)(a1 + 4); /*0x14bd15*/
      return _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14bd18*/
    case 17: /*0x14bc79*/
    case 18: /*0x14bc79*/
      return result;
    case 20: /*0x14bc79*/
      do /*0x14bd2e*/
      {
        while ( *(_DWORD *)a1 ) /*0x14bd1c*/
          ; /*0x14bd1e*/
      }
      while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14bd2e*/
      ++*(_DWORD *)(a1 + 4); /*0x14bd30*/
      ++*(_DWORD *)(a1 + 24); /*0x14bd33*/
      ++*(_DWORD *)(a1 + 28); /*0x14bd36*/
      return _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14bd39*/
    case 21: /*0x14bc79*/
      do /*0x14bd4e*/
      {
        while ( *(_DWORD *)a1 ) /*0x14bd3c*/
          ; /*0x14bd3e*/
      }
      while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14bd4e*/
      ++*(_DWORD *)(a1 + 4); /*0x14bd50*/
      ++*(_DWORD *)(a1 + 32); /*0x14bd53*/
      return _InterlockedExchange((volatile __int32 *)a1, 0);
    default:
      panic(aIpcObjectCopyi_0); /*0x14bd5d*/
      return result; /*0x14bd5d*/
  }
}
