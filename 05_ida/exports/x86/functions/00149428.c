/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x149428. */
char __cdecl ipc_kmsg_copyout_dest(_DWORD *a1, int a2)
{
  int v2; // edi
  int v3; // ecx
  int v4; // esi
  int v5; // edx
  int v6; // ecx
  unsigned int v7; // eax
  unsigned __int8 *v8; // esi
  int v9; // eax
  unsigned int v10; // edi
  _DWORD *v11; // esi
  vm_size_t v12; // ecx
  _DWORD *i; // eax
  unsigned int j; // ebx
  int v15; // eax
  vm_size_t v17; // [esp+10h] [ebp-24h]
  _DWORD *v18; // [esp+18h] [ebp-1Ch]
  int v19; // [esp+1Ch] [ebp-18h]
  _BOOL4 v20; // [esp+20h] [ebp-14h]
  unsigned int v21; // [esp+24h] [ebp-10h]
  int v22; // [esp+28h] [ebp-Ch]
  int v23; // [esp+30h] [ebp-4h] BYREF

  v2 = a1[5]; /*0x149434*/
  v3 = a1[7]; /*0x149437*/
  v4 = a1[8]; /*0x14943a*/
  v22 = (unsigned __int16)(v2 & 0xFF00) >> 8; /*0x149452*/
  do /*0x14946a*/
  {
    while ( *(_DWORD *)v3 ) /*0x149458*/
      ; /*0x14945a*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v3, 1) == 1 ); /*0x14946a*/
  if ( *(int *)(v3 + 8) >= 0 ) /*0x149470*/
  {
    v5 = *(_DWORD *)(v3 + 4) - 1; /*0x14948f*/
    *(_DWORD *)(v3 + 4) = v5; /*0x149492*/
    _InterlockedExchange((volatile __int32 *)v3, 0); /*0x149498*/
    if ( !v5 ) /*0x14949c*/
      zfree(ipc_object_zones[*(_WORD *)(v3 + 10) & 0x7FFF], v3); /*0x1494b0*/
    v23 = -1; /*0x1494b8*/
  }
  else
  {
    ipc_object_copyout_dest(a2, v3, (unsigned __int8)v2, &v23); /*0x14947f*/
  }
  if ( !v4 || v4 == -1 ) /*0x1494c6*/
  {
    v6 = v4; /*0x1494dc*/
  }
  else
  {
    ipc_object_destroy(v4, v22); /*0x1494cd*/
    v6 = 0; /*0x1494d2*/
  }
  v7 = v22 | ((unsigned __int8)v2 << 8) | v2 & 0xFFFF0000; /*0x1494ee*/
  a1[5] = v7; /*0x1494f0*/
  a1[8] = v23; /*0x1494f6*/
  a1[7] = v6; /*0x1494f9*/
  if ( v2 < 0 ) /*0x1494fe*/
  {
    v7 = (unsigned int)a1 + a1[6] + 20; /*0x14950a*/
    v21 = v7; /*0x14950c*/
    v8 = (unsigned __int8 *)(a1 + 11); /*0x14950f*/
    if ( (unsigned int)(a1 + 11) < v7 ) /*0x149514*/
    {
      do /*0x149617*/
      {
        v20 = (v8[3] & 0x10) != 0; /*0x149527*/
        if ( (v8[3] & 0x20) != 0 ) /*0x149530*/
        {
          v19 = *((unsigned __int16 *)v8 + 2); /*0x149536*/
          v9 = *((unsigned __int16 *)v8 + 3); /*0x149539*/
          v10 = *((_DWORD *)v8 + 2); /*0x14953d*/
          v11 = v8 + 12; /*0x149540*/
        }
        else
        {
          v19 = *v8; /*0x14954b*/
          v9 = v8[1]; /*0x14954e*/
          v10 = *((_WORD *)v8 + 1) & 0xFFF; /*0x149556*/
          v11 = v8 + 4; /*0x14955c*/
        }
        v12 = (v10 * v9 + 7) >> 3; /*0x149567*/
        if ( (unsigned int)(v19 - 16) <= 5 ) /*0x149583*/
        {
          if ( v20 ) /*0x149589*/
          {
            v18 = v11; /*0x14958b*/
            for ( i = &v11[v10]; v21 < (unsigned int)i; --v10 ) /*0x149594*/
              --i; /*0x149598*/
          }
          else
          {
            v18 = (_DWORD *)*v11; /*0x1495a6*/
          }
          for ( j = 0; j < v10; ++j ) /*0x1495ad*/
          {
            v15 = v18[j]; /*0x1495b3*/
            if ( v15 && v15 != -1 ) /*0x1495bd*/
            {
              v17 = v12; /*0x1495c4*/
              ipc_object_destroy(v15, v19); /*0x1495c7*/
              v12 = v17; /*0x1495cf*/
            }
          }
        }
        if ( v20 ) /*0x1495db*/
        {
          v7 = v12 + 3; /*0x1495dd*/
          LOBYTE(v7) = (v12 + 3) & 0xFC; /*0x1495e0*/
          v8 = (unsigned __int8 *)v11 + v7; /*0x1495e2*/
        }
        else
        {
          v7 = *v11; /*0x1495e8*/
          if ( v12 ) /*0x1495ec*/
          {
            if ( (unsigned int)(v19 - 16) > 5 ) /*0x1495f2*/
              LOBYTE(v7) = vm_deallocate(ipc_soft_map, v7, v12); /*0x149609*/
            else
              LOBYTE(v7) = kfree(v7, v12); /*0x1495f6*/
          }
          v8 = (unsigned __int8 *)(v11 + 1); /*0x149611*/
        }
      }
      while ( v21 > (unsigned int)v8 ); /*0x149617*/
    }
  }
  return v7; /*0x149620*/
}
