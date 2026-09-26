/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14d328. */
int __cdecl ipc_port_alloc_compat(int a1, unsigned int *a2, int *a3)
{
  int v3; // ebx
  unsigned int *v5; // edi
  int *v6; // eax
  unsigned int v7; // eax
  unsigned int i; // edx
  unsigned int *v9; // eax
  unsigned int v10; // [esp+Ch] [ebp-14h]
  int v11; // [esp+10h] [ebp-10h]
  unsigned int v12; // [esp+10h] [ebp-10h]
  unsigned int *v13; // [esp+14h] [ebp-Ch]
  int *v14; // [esp+18h] [ebp-8h] BYREF
  unsigned int v15; // [esp+1Ch] [ebp-4h] BYREF

  v3 = zalloc(ipc_object_zones[0]); /*0x14d33d*/
  if ( !v3 ) /*0x14d344*/
    return 6; /*0x14d346*/
  v13 = (unsigned int *)ipc_table_dnrequests; /*0x14d356*/
  v5 = (unsigned int *)ipc_table_alloc(8 * *(_DWORD *)ipc_table_dnrequests); /*0x14d368*/
  if ( v5 ) /*0x14d36f*/
  {
    v11 = ipc_entry_alloc(a1, &v15, &v14); /*0x14d399*/
    if ( v11 ) /*0x14d3a1*/
    {
      zfree(ipc_object_zones[0], v3); /*0x14d3ab*/
      ipc_table_free(8 * *v13, v5); /*0x14d3be*/
      return v11; /*0x14d3c3*/
    }
    else
    {
      v6 = v14; /*0x14d3cc*/
      v14[1] = v3; /*0x14d3cf*/
      v6[2] = 1; /*0x14d3d2*/
      *v6 |= 0x420000u; /*0x14d3d9*/
      *(_DWORD *)v3 = 0; /*0x14d3df*/
      do /*0x14d3fa*/
      {
        while ( *(_DWORD *)v3 ) /*0x14d3e8*/
          ; /*0x14d3ea*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v3, 1) == 1 ); /*0x14d3fa*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14d401*/
      *(_DWORD *)(v3 + 4) = 1; /*0x14d404*/
      *(_DWORD *)(v3 + 8) = 0x80000000; /*0x14d40b*/
      v7 = v15; /*0x14d412*/
      *(_DWORD *)(v3 + 12) = a1; /*0x14d415*/
      *(_DWORD *)(v3 + 16) = v7; /*0x14d418*/
      *(_DWORD *)(v3 + 24) = 0; /*0x14d41b*/
      *(_DWORD *)(v3 + 28) = 0; /*0x14d422*/
      *(_DWORD *)(v3 + 32) = 0; /*0x14d429*/
      *(_DWORD *)(v3 + 36) = 0; /*0x14d430*/
      *(_DWORD *)(v3 + 40) = 0; /*0x14d437*/
      *(_DWORD *)(v3 + 44) = 0; /*0x14d43e*/
      *(_DWORD *)(v3 + 48) = 0; /*0x14d445*/
      *(_DWORD *)(v3 + 52) = 0; /*0x14d44c*/
      *(_DWORD *)(v3 + 56) = 0; /*0x14d453*/
      *(_DWORD *)(v3 + 60) = 5; /*0x14d45a*/
      ipc_mqueue_init((_DWORD *)(v3 + 64)); /*0x14d465*/
      *(_DWORD *)(v3 + 76) = 0; /*0x14d46d*/
      v12 = *v13; /*0x14d479*/
      v10 = 0; /*0x14d47c*/
      for ( i = 2; v12 > i; ++i ) /*0x14d48a*/
      {
        v9 = &v5[2 * i]; /*0x14d48c*/
        v9[1] = 0; /*0x14d48f*/
        *v9 = v10; /*0x14d499*/
        v10 = i; /*0x14d49b*/
      }
      *v5 = v10; /*0x14d4a7*/
      v5[1] = (unsigned int)v13; /*0x14d4ac*/
      *(_DWORD *)(v3 + 44) = v5; /*0x14d4af*/
      v5[3] = v15; /*0x14d4b5*/
      v5[2] = a1 | 1; /*0x14d4be*/
      ipc_space_reference(a1); /*0x14d4c5*/
      *a2 = v15; /*0x14d4d0*/
      *a3 = v3; /*0x14d4d5*/
      return 0; /*0x14d4d7*/
    }
  }
  else
  {
    zfree(ipc_object_zones[0], v3); /*0x14d379*/
    return 6; /*0x14d37e*/
  }
}
