/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14bdb4. */
int __cdecl ipc_object_copyout(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  volatile __int32 *v5; // edx
  int result; // eax
  int v7; // edx
  int *v8; // [esp+10h] [ebp-8h] BYREF
  unsigned int v9; // [esp+14h] [ebp-4h] BYREF

  v5 = (volatile __int32 *)(a1 + 8); /*0x14bdc3*/
  do /*0x14bdda*/
  {
    while ( *v5 ) /*0x14bdc8*/
      ; /*0x14bdca*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x14bdda*/
  while ( 1 ) /*0x14bde4*/
  {
    if ( !*(_DWORD *)(a1 + 12) ) /*0x14bde4*/
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14bdec*/
      return 16; /*0x14bdf4*/
    }
    if ( a3 != 18 && ipc_right_reverse(a1, a2, &v9, &v8) ) /*0x14be0c*/
      break; /*0x14be0c*/
    if ( !ipc_entry_get(a1, &v9, &v8) ) /*0x14be2d*/
    {
      do /*0x14be52*/
      {
        while ( *(_DWORD *)a2 ) /*0x14be40*/
          ; /*0x14be42*/
      }
      while ( _InterlockedExchange((volatile __int32 *)a2, 1) == 1 ); /*0x14be52*/
      if ( *(int *)(a2 + 8) >= 0 ) /*0x14be58*/
      {
        _InterlockedExchange((volatile __int32 *)a2, 0); /*0x14be5c*/
        ipc_entry_dealloc((_DWORD *)a1, v9, v8); /*0x14be67*/
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14be6e*/
        return 20; /*0x14be76*/
      }
      v8[1] = a2; /*0x14be7b*/
      break; /*0x14be7b*/
    }
    result = ipc_entry_grow_table(a1); /*0x14be30*/
    if ( result ) /*0x14be3c*/
      return result; /*0x14be3c*/
  }
  v7 = ipc_right_copyout(a1, v9, v8, a3, a4, a2); /*0x14be7e*/
  _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14be99*/
  if ( !v7 ) /*0x14be9e*/
    *a5 = v9; /*0x14bea6*/
  return v7; /*0x14bead*/
}
