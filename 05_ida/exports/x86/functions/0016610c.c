/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16610c. */
int __cdecl task_dowait(int a1, int a2)
{
  _DWORD *v2; // edi
  _DWORD *v3; // ebx
  int v5; // [esp+Ch] [ebp-Ch]
  thread_act_t v6; // [esp+10h] [ebp-8h]
  _DWORD *v7; // [esp+14h] [ebp-4h]

  v5 = 0; /*0x166118*/
  v6 = active_threads; /*0x166125*/
  v7 = (_DWORD *)(a1 + 28); /*0x16612b*/
  v2 = nullptr; /*0x16612e*/
  do /*0x166142*/
  {
    while ( *(_DWORD *)a1 ) /*0x166130*/
      ; /*0x166132*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x166142*/
  v3 = (_DWORD *)*v7; /*0x166147*/
  if ( v7 != (_DWORD *)*v7 ) /*0x16614b*/
  {
    while ( *(_DWORD *)(a1 + 8) || a2 ) /*0x16615a*/
    {
      if ( (_DWORD *)v6 != v3 ) /*0x16616b*/
      {
        thread_reference(v3); /*0x16616e*/
        _InterlockedExchange((volatile __int32 *)a1, 0); /*0x166178*/
        if ( v2 ) /*0x16617c*/
          thread_deallocate(v2); /*0x16617f*/
        thread_dowait(v3, 1); /*0x16618a*/
        v2 = v3; /*0x16618f*/
        do /*0x1661a6*/
        {
          while ( *(_DWORD *)a1 ) /*0x166194*/
            ; /*0x166196*/
        }
        while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x1661a6*/
      }
      v3 = (_DWORD *)v3[4]; /*0x1661a8*/
      if ( v7 == v3 ) /*0x1661ae*/
        goto LABEL_15; /*0x1661ae*/
    }
    v5 = 5; /*0x16615c*/
  }
LABEL_15:
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x1661b0*/
  if ( v2 ) /*0x1661b6*/
    thread_deallocate(v2); /*0x1661b9*/
  return v5; /*0x1661c4*/
}
