/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c318. */
int __cdecl ipc_object_copyout_name_compat(unsigned int a1, unsigned int a2, int a3, unsigned int a4)
{
  int result; // eax
  unsigned int v5; // eax
  unsigned int *v6; // eax
  unsigned int v7; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v8[4]; // [esp+10h] [ebp-Ch] BYREF
  _BYTE v9[4]; // [esp+14h] [ebp-8h] BYREF
  unsigned int *v10; // [esp+18h] [ebp-4h] BYREF

  do /*0x14c332*/
  {
    result = ipc_entry_alloc_name(a1, a4, &v10); /*0x14c332*/
    if ( result ) /*0x14c33e*/
      break; /*0x14c33e*/
    if ( ipc_right_inuse(a1, a4, v10) ) /*0x14c34a*/
      return 13; /*0x14c35b*/
    if ( a3 != 18 && ipc_right_reverse(a1, a2, v9, v8) ) /*0x14c370*/
    {
      _InterlockedExchange((volatile __int32 *)a2, 0); /*0x14c37e*/
      ipc_entry_dealloc((_DWORD *)a1, a4, (int *)v10); /*0x14c386*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14c38d*/
      return 21; /*0x14c395*/
    }
    do /*0x14c3ae*/
    {
      while ( *(_DWORD *)a2 ) /*0x14c39c*/
        ; /*0x14c39e*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a2, 1) == 1 ); /*0x14c3ae*/
    if ( *(int *)(a2 + 8) >= 0 ) /*0x14c3b4*/
    {
      _InterlockedExchange((volatile __int32 *)a2, 0); /*0x14c3b8*/
      ipc_entry_dealloc((_DWORD *)a1, a4, (int *)v10); /*0x14c3c0*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14c3c7*/
      return 20; /*0x14c3cf*/
    }
    v5 = a1; /*0x14c3d8*/
    LOBYTE(v5) = a1 | 1; /*0x14c3da*/
    if ( !ipc_port_dnrequest(a2, a4, v5, &v7) ) /*0x14c3df*/
    {
      ipc_space_reference(a1); /*0x14c3ee*/
      v6 = v10; /*0x14c3f3*/
      v10[1] = a2; /*0x14c3f6*/
      v6[2] = v7; /*0x14c3fc*/
      *v6 |= 0x400000u; /*0x14c3ff*/
      result = ipc_right_copyout(a1, a4, v6, a3, 1, a2); /*0x14c412*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14c41b*/
      return result; /*0x14c420*/
    }
    ipc_entry_dealloc((_DWORD *)a1, a4, (int *)v10); /*0x14c42a*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14c434*/
    result = ipc_port_dngrow(a2); /*0x14c438*/
  }
  while ( !result ); /*0x14c332*/
  return result; /*0x14c44d*/
}
