/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x147320. */
char __cdecl ipc_kmsg_clean_partial(_DWORD *a1, unsigned __int8 *a2, int a3, unsigned int a4)
{
  int v4; // ebx
  int v5; // eax
  int v6; // edx
  unsigned __int8 *v7; // esi
  int v8; // eax
  unsigned int v9; // edi
  _DWORD *v10; // esi
  _BOOL4 v11; // edx
  unsigned __int8 *i; // eax
  unsigned int j; // ebx
  int v14; // eax
  int v15; // edx
  int *v16; // ecx
  int v17; // edi
  int *v18; // esi
  unsigned int k; // ebx
  vm_size_t size; // [esp+Ch] [ebp-20h]
  vm_size_t sizea; // [esp+Ch] [ebp-20h]
  _BOOL4 v23; // [esp+14h] [ebp-18h]
  vm_size_t v24; // [esp+18h] [ebp-14h]
  _BOOL4 v25; // [esp+1Ch] [ebp-10h]
  _DWORD *v26; // [esp+20h] [ebp-Ch]
  int v27; // [esp+24h] [ebp-8h]
  _BOOL4 v28; // [esp+28h] [ebp-4h]
  int *v29; // [esp+38h] [ebp+Ch]

  v4 = a1[5]; /*0x14732c*/
  LOBYTE(v5) = ipc_object_destroy(a1[7], (unsigned __int8)v4); /*0x147337*/
  v6 = a1[8]; /*0x14733c*/
  if ( v6 && v6 != -1 ) /*0x147349*/
    LOBYTE(v5) = ipc_object_destroy(v6, (unsigned __int16)(v4 & 0xFF00) >> 8); /*0x147357*/
  v7 = (unsigned __int8 *)(a1 + 11); /*0x14735f*/
  while ( a2 > v7 ) /*0x147365*/
  {
    v28 = (v7[3] & 0x10) != 0; /*0x147378*/
    if ( (v7[3] & 0x20) != 0 ) /*0x14737e*/
    {
      v27 = *((unsigned __int16 *)v7 + 2); /*0x147384*/
      v8 = *((unsigned __int16 *)v7 + 3); /*0x147387*/
      v9 = *((_DWORD *)v7 + 2); /*0x14738b*/
      v10 = v7 + 12; /*0x14738e*/
    }
    else
    {
      v27 = *v7; /*0x147397*/
      v8 = v7[1]; /*0x14739a*/
      v9 = *((_WORD *)v7 + 1) & 0xFFF; /*0x1473a2*/
      v10 = v7 + 4; /*0x1473a8*/
    }
    size = (v9 * v8 + 7) >> 3; /*0x1473b4*/
    v11 = (unsigned int)(v27 - 16) <= 5; /*0x1473c3*/
    if ( (unsigned int)(v27 - 16) <= 5 ) /*0x1473c8*/
    {
      if ( v28 ) /*0x1473ce*/
      {
        v26 = v10; /*0x1473d0*/
        for ( i = (unsigned __int8 *)&v10[v9]; a2 < i; --v9 ) /*0x1473d9*/
          i -= 4; /*0x1473dc*/
      }
      else
      {
        v26 = (_DWORD *)*v10; /*0x1473ea*/
      }
      for ( j = 0; j < v9; ++j ) /*0x1473f1*/
      {
        v14 = v26[j]; /*0x1473f7*/
        if ( v14 && v14 != -1 ) /*0x147401*/
        {
          v23 = v11; /*0x147408*/
          ipc_object_destroy(v14, v27); /*0x14740b*/
          v11 = v23; /*0x147413*/
        }
      }
    }
    if ( v28 ) /*0x14741f*/
    {
      v5 = size + 3; /*0x147424*/
      LOBYTE(v5) = (size + 3) & 0xFC; /*0x147427*/
      v7 = (unsigned __int8 *)v10 + v5; /*0x147429*/
    }
    else
    {
      v5 = *v10; /*0x147430*/
      if ( size ) /*0x147436*/
      {
        if ( v11 ) /*0x14743a*/
          LOBYTE(v5) = kfree(v5, size); /*0x147441*/
        else
          LOBYTE(v5) = vm_deallocate(ipc_soft_map, v5, size); /*0x147458*/
      }
      v7 = (unsigned __int8 *)(v10 + 1); /*0x147460*/
    }
  }
  if ( a3 ) /*0x14746c*/
  {
    v25 = (a2[3] & 0x10) != 0; /*0x147482*/
    if ( (a2[3] & 0x20) != 0 ) /*0x147488*/
    {
      sizea = *((unsigned __int16 *)a2 + 2); /*0x147491*/
      v15 = *((unsigned __int16 *)a2 + 3); /*0x147497*/
      v5 = *((_DWORD *)a2 + 2); /*0x14749b*/
      v16 = (int *)(a2 + 12); /*0x14749e*/
    }
    else
    {
      sizea = *a2; /*0x1474aa*/
      v15 = a2[1]; /*0x1474b0*/
      v5 = *((_WORD *)a2 + 1) & 0xFFF; /*0x1474b8*/
      v16 = (int *)(a2 + 4); /*0x1474bd*/
    }
    v29 = v16; /*0x1474c0*/
    v24 = (unsigned int)(v15 * v5 + 7) >> 3; /*0x1474cc*/
    LOBYTE(v5) = sizea - 16 <= 5; /*0x1474d8*/
    v17 = (unsigned __int8)v5; /*0x1474db*/
    if ( sizea - 16 <= 5 ) /*0x1474e0*/
    {
      v18 = v16; /*0x1474e2*/
      if ( !v25 ) /*0x1474e9*/
        v18 = (int *)*v16; /*0x1474eb*/
      for ( k = 0; a4 > k; ++k ) /*0x1474f2*/
      {
        v5 = v18[k]; /*0x1474f4*/
        if ( v5 && v5 != -1 ) /*0x1474fe*/
          LOBYTE(v5) = ipc_object_destroy(v5, sizea); /*0x147505*/
      }
    }
    if ( !v25 ) /*0x147517*/
    {
      v5 = *v29; /*0x14751c*/
      if ( v24 ) /*0x147522*/
      {
        if ( v17 ) /*0x147526*/
          LOBYTE(v5) = kfree(v5, v24); /*0x14752d*/
        else
          LOBYTE(v5) = vm_deallocate(ipc_soft_map, v5, v24); /*0x147540*/
      }
    }
  }
  return v5; /*0x147548*/
}
