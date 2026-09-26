/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x148c20. */
int __cdecl ipc_kmsg_copyout_object(int a1, unsigned int a2, int a3, int *a4)
{
  volatile __int32 *v4; // edx
  int v5; // ebx
  _DWORD *v7; // [esp+Ch] [ebp-4h] BYREF

  if ( !a2 || a2 == -1 ) /*0x148c36*/
  {
    *a4 = a2; /*0x148c3b*/
    return 0; /*0x148c3d*/
  }
  if ( a3 == 17 ) /*0x148c48*/
  {
    v4 = (volatile __int32 *)(a1 + 8); /*0x148c4c*/
    do /*0x148c62*/
    {
      while ( *v4 ) /*0x148c50*/
        ; /*0x148c52*/
    }
    while ( _InterlockedExchange(v4, 1) == 1 ); /*0x148c62*/
    if ( *(_DWORD *)(a1 + 12) ) /*0x148c64*/
    {
      do /*0x148c7e*/
      {
        while ( *(_DWORD *)a2 ) /*0x148c6c*/
          ; /*0x148c6e*/
      }
      while ( _InterlockedExchange((volatile __int32 *)a2, 1) == 1 ); /*0x148c7e*/
      if ( *(int *)(a2 + 8) < 0 && ipc_hash_local_lookup(a1, a2, a4, &v7) ) /*0x148c90*/
      {
        --*(_DWORD *)(a2 + 28); /*0x148ca8*/
        --*(_DWORD *)(a2 + 4); /*0x148cab*/
        _InterlockedExchange((volatile __int32 *)a2, 0); /*0x148cb0*/
        if ( *(_WORD *)v7 != 0xFFFE ) /*0x148cbc*/
          ++*v7; /*0x148cbe*/
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x148cc2*/
        return 0; /*0x148cc5*/
      }
      _InterlockedExchange((volatile __int32 *)a2, 0); /*0x148c9e*/
    }
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x148ca2*/
  }
  v5 = ipc_object_copyout(a1, a2, a3, 1, a4); /*0x148cd9*/
  if ( !v5 ) /*0x148ce0*/
    return 0; /*0x148d1c*/
  ipc_object_destroy(a2, a3); /*0x148ce7*/
  if ( v5 == 20 ) /*0x148cef*/
  {
    *a4 = -1; /*0x148cf4*/
    return 0; /*0x148cfa*/
  }
  *a4 = 0; /*0x148cff*/
  if ( v5 == 6 ) /*0x148d08*/
    return 2048; /*0x148d0a*/
  else
    return 0x2000; /*0x148d14*/
}
