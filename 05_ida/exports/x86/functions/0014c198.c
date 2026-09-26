/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c198. */
int __cdecl ipc_object_copyout_compat(int a1, int a2, int a3, _DWORD *a4)
{
  volatile __int32 *v4; // edx
  int result; // eax
  int v6; // eax
  int *v7; // eax
  int v8; // edx
  volatile __int32 *v9; // [esp+Ch] [ebp-10h]
  int v10; // [esp+10h] [ebp-Ch] BYREF
  int *v11; // [esp+14h] [ebp-8h] BYREF
  unsigned int v12; // [esp+18h] [ebp-4h] BYREF

  v4 = (volatile __int32 *)(a1 + 8); /*0x14c1a7*/
  do /*0x14c1be*/
  {
    while ( *v4 ) /*0x14c1ac*/
      ; /*0x14c1ae*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x14c1be*/
  while ( 1 ) /*0x14c1c0*/
  {
    if ( !*(_DWORD *)(a1 + 12) ) /*0x14c1c0*/
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14c1c8*/
      return 16; /*0x14c1d0*/
    }
    if ( a3 != 18 && ipc_right_reverse(a1, a2, &v12, &v11) ) /*0x14c1e8*/
      break; /*0x14c1e8*/
    if ( ipc_entry_get(a1, &v12, &v11) ) /*0x14c201*/
    {
      result = ipc_entry_grow_table(a1); /*0x14c210*/
      if ( result ) /*0x14c21c*/
        return result; /*0x14c21c*/
    }
    else
    {
      do /*0x14c236*/
      {
        while ( *(_DWORD *)a2 ) /*0x14c224*/
          ; /*0x14c226*/
      }
      while ( _InterlockedExchange((volatile __int32 *)a2, 1) == 1 ); /*0x14c236*/
      if ( *(int *)(a2 + 8) >= 0 ) /*0x14c23c*/
      {
        _InterlockedExchange((volatile __int32 *)a2, 0); /*0x14c240*/
        ipc_entry_dealloc((_DWORD *)a1, v12, v11); /*0x14c24b*/
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14c252*/
        return 20; /*0x14c25a*/
      }
      v6 = a1; /*0x14c264*/
      LOBYTE(v6) = a1 | 1; /*0x14c266*/
      if ( !ipc_port_dnrequest(a2, v12, v6, &v10) ) /*0x14c27a*/
      {
        ipc_space_reference(a1); /*0x14c2c9*/
        v7 = v11; /*0x14c2ce*/
        v11[1] = a2; /*0x14c2d1*/
        v7[2] = v10; /*0x14c2d7*/
        *v7 |= 0x400000u; /*0x14c2da*/
        break; /*0x14c2da*/
      }
      ipc_entry_dealloc((_DWORD *)a1, v12, v11); /*0x14c285*/
      v9 = (volatile __int32 *)(a1 + 8); /*0x14c28d*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14c295*/
      result = ipc_port_dngrow(a2); /*0x14c299*/
      if ( result ) /*0x14c2a5*/
        return result; /*0x14c2a5*/
      do /*0x14c2be*/
      {
        while ( *v9 ) /*0x14c2ac*/
          ; /*0x14c2ae*/
      }
      while ( _InterlockedExchange(v9, 1) == 1 ); /*0x14c2be*/
    }
  }
  v8 = ipc_right_copyout(a1, v12, v11, a3, 1, a2); /*0x14c2e3*/
  _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14c2fc*/
  if ( !v8 ) /*0x14c301*/
    *a4 = v12; /*0x14c309*/
  return v8; /*0x14c310*/
}
