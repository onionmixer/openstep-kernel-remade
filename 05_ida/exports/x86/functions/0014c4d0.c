/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c4d0. */
int __cdecl ipc_port_dngrow(int a1)
{
  unsigned int v2; // ebx
  unsigned int i; // edx
  unsigned int *v4; // eax
  int v5; // eax
  int v6; // [esp+Ch] [ebp-18h]
  unsigned int v7; // [esp+10h] [ebp-14h]
  int *v8; // [esp+14h] [ebp-10h]
  unsigned int *v9; // [esp+18h] [ebp-Ch]
  unsigned int *v10; // [esp+1Ch] [ebp-8h]
  unsigned int *v11; // [esp+20h] [ebp-4h]

  v10 = *(unsigned int **)(a1 + 44); /*0x14c4df*/
  if ( v10 ) /*0x14c4e4*/
    v11 = (unsigned int *)(v10[1] + 4); /*0x14c4fd*/
  else
    v11 = (unsigned int *)ipc_table_dnrequests; /*0x14c4ec*/
  ++*(_DWORD *)(a1 + 4); /*0x14c500*/
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14c505*/
  if ( *v11 && (v9 = (unsigned int *)ipc_table_alloc(8 * *v11)) != nullptr ) /*0x14c521*/
  {
    do /*0x14c546*/
    {
      while ( *(_DWORD *)a1 ) /*0x14c534*/
        ; /*0x14c536*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14c546*/
    --*(_DWORD *)(a1 + 4); /*0x14c548*/
    if ( *(int *)(a1 + 8) < 0 && *(unsigned int **)(a1 + 44) == v10 && (!v10 || v11 == (unsigned int *)(v10[1] + 4)) ) /*0x14c56e*/
    {
      v8 = nullptr; /*0x14c574*/
      if ( v10 ) /*0x14c57f*/
      {
        v8 = (int *)v10[1]; /*0x14c587*/
        v6 = *v8; /*0x14c58c*/
        v2 = *v10; /*0x14c592*/
        bcopy(v10 + 2, v9 + 2, 8 * *v8 - 8); /*0x14c5aa*/
      }
      else
      {
        v6 = 1; /*0x14c5b4*/
        v2 = 0; /*0x14c5bb*/
      }
      v7 = *v11; /*0x14c5c2*/
      for ( i = v6; v7 > i; ++i ) /*0x14c5ca*/
      {
        v4 = &v9[2 * i]; /*0x14c5cf*/
        v4[1] = 0; /*0x14c5d2*/
        *v4 = v2; /*0x14c5d9*/
        v2 = i; /*0x14c5db*/
      }
      *v9 = v2; /*0x14c5e8*/
      v9[1] = (unsigned int)v11; /*0x14c5ed*/
      *(_DWORD *)(a1 + 44) = v9; /*0x14c5f0*/
      _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14c5f5*/
      if ( v10 ) /*0x14c5fb*/
        ipc_table_free(8 * *v8, v10); /*0x14c604*/
    }
    else
    {
      v5 = *(_DWORD *)(a1 + 4); /*0x14c608*/
      _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14c60d*/
      if ( !v5 ) /*0x14c611*/
        zfree(ipc_object_zones[*(_WORD *)(a1 + 10) & 0x7FFF], a1); /*0x14c625*/
      ipc_table_free(8 * *v11, v9); /*0x14c63e*/
    }
    return 0; /*0x14c643*/
  }
  else
  {
    ipc_object_release(a1); /*0x14c524*/
    return 6; /*0x14c529*/
  }
}
