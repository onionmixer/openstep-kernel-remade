/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14beb4. */
int __cdecl ipc_object_copyout_name(unsigned int a1, unsigned int a2, int a3, int a4, unsigned int a5)
{
  int result; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-Ch] BYREF
  int v7; // [esp+10h] [ebp-8h] BYREF
  unsigned int *v8; // [esp+14h] [ebp-4h] BYREF

  result = ipc_entry_alloc_name(a1, a5, &v8); /*0x14becc*/
  if ( result ) /*0x14bed8*/
    return result; /*0x14bed8*/
  if ( a3 == 18 || !ipc_right_reverse(a1, a2, &v7, v6) ) /*0x14beee*/
  {
    if ( ipc_right_inuse(a1, a5, v8) ) /*0x14bf26*/
      return 13; /*0x14bf37*/
    do /*0x14bf4e*/
    {
      while ( *(_DWORD *)a2 ) /*0x14bf3c*/
        ; /*0x14bf3e*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a2, 1) == 1 ); /*0x14bf4e*/
    if ( *(int *)(a2 + 8) >= 0 ) /*0x14bf54*/
    {
      _InterlockedExchange((volatile __int32 *)a2, 0); /*0x14bf58*/
      ipc_entry_dealloc((_DWORD *)a1, a5, (int *)v8); /*0x14bf60*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14bf67*/
      return 20; /*0x14bf6f*/
    }
    v8[1] = a2; /*0x14bf77*/
    goto LABEL_15; /*0x14bf77*/
  }
  if ( v7 == a5 ) /*0x14befd*/
  {
LABEL_15:
    result = ipc_right_copyout(a1, a5, v8, a3, a4, a2); /*0x14bf7a*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14bf92*/
    return result; /*0x14bf92*/
  }
  _InterlockedExchange((volatile __int32 *)a2, 0); /*0x14bf01*/
  if ( (*((_BYTE *)v8 + 2) & 0x1F) == 0 ) /*0x14bf0a*/
    ipc_entry_dealloc((_DWORD *)a1, a5, (int *)v8); /*0x14bf0f*/
  _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14bf16*/
  return 21; /*0x14bf9a*/
}
