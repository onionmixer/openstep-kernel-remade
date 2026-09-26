/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14719c. */
char __cdecl ipc_kmsg_clean(_DWORD *a1)
{
  int v1; // esi
  vm_address_t v2; // eax
  int v3; // edx
  int v4; // edx
  unsigned __int8 *v5; // esi
  int v6; // eax
  unsigned int v7; // edi
  _DWORD *v8; // esi
  _BOOL4 v9; // edx
  _DWORD *i; // eax
  unsigned int j; // ebx
  int v12; // eax
  vm_size_t size; // [esp+Ch] [ebp-1Ch]
  _BOOL4 v15; // [esp+14h] [ebp-14h]
  _DWORD *v16; // [esp+18h] [ebp-10h]
  int v17; // [esp+1Ch] [ebp-Ch]
  _BOOL4 v18; // [esp+20h] [ebp-8h]
  vm_address_t v19; // [esp+24h] [ebp-4h]

  v1 = a1[5]; /*0x1471a8*/
  v2 = a1[3]; /*0x1471ab*/
  if ( v2 ) /*0x1471b0*/
    LOBYTE(v2) = ipc_marequest_destroy(a1[3]); /*0x1471b3*/
  v3 = a1[7]; /*0x1471bb*/
  if ( v3 && v3 != -1 ) /*0x1471c5*/
    LOBYTE(v2) = ipc_object_destroy(v3, (unsigned __int8)v1); /*0x1471ce*/
  v4 = a1[8]; /*0x1471d6*/
  if ( v4 && v4 != -1 ) /*0x1471e0*/
    LOBYTE(v2) = ipc_object_destroy(v4, (unsigned __int16)(v1 & 0xFF00) >> 8); /*0x1471ee*/
  if ( v1 < 0 ) /*0x1471f8*/
  {
    v2 = (vm_address_t)a1 + a1[6] + 20; /*0x147204*/
    v19 = v2; /*0x147206*/
    v5 = (unsigned __int8 *)(a1 + 11); /*0x147209*/
    if ( (unsigned int)(a1 + 11) < v2 ) /*0x14720e*/
    {
      do /*0x14730e*/
      {
        v18 = (v5[3] & 0x10) != 0; /*0x147221*/
        if ( (v5[3] & 0x20) != 0 ) /*0x147227*/
        {
          v17 = *((unsigned __int16 *)v5 + 2); /*0x14722d*/
          v6 = *((unsigned __int16 *)v5 + 3); /*0x147230*/
          v7 = *((_DWORD *)v5 + 2); /*0x147234*/
          v8 = v5 + 12; /*0x147237*/
        }
        else
        {
          v17 = *v5; /*0x14723f*/
          v6 = v5[1]; /*0x147242*/
          v7 = *((_WORD *)v5 + 1) & 0xFFF; /*0x14724a*/
          v8 = v5 + 4; /*0x147250*/
        }
        size = (v7 * v6 + 7) >> 3; /*0x14725c*/
        v9 = (unsigned int)(v17 - 16) <= 5; /*0x14726b*/
        if ( (unsigned int)(v17 - 16) <= 5 ) /*0x147270*/
        {
          if ( v18 ) /*0x147276*/
          {
            v16 = v8; /*0x147278*/
            for ( i = &v8[v7]; v19 < (unsigned int)i; --v7 ) /*0x147281*/
              --i; /*0x147284*/
          }
          else
          {
            v16 = (_DWORD *)*v8; /*0x147292*/
          }
          for ( j = 0; j < v7; ++j ) /*0x147299*/
          {
            v12 = v16[j]; /*0x14729f*/
            if ( v12 && v12 != -1 ) /*0x1472a9*/
            {
              v15 = v9; /*0x1472b0*/
              ipc_object_destroy(v12, v17); /*0x1472b3*/
              v9 = v15; /*0x1472bb*/
            }
          }
        }
        if ( v18 ) /*0x1472c7*/
        {
          v2 = size + 3; /*0x1472cc*/
          LOBYTE(v2) = (size + 3) & 0xFC; /*0x1472cf*/
          v5 = (unsigned __int8 *)v8 + v2; /*0x1472d1*/
        }
        else
        {
          v2 = *v8; /*0x1472d8*/
          if ( size ) /*0x1472de*/
          {
            if ( v9 ) /*0x1472e2*/
              LOBYTE(v2) = kfree(v2, size); /*0x1472e9*/
            else
              LOBYTE(v2) = vm_deallocate(ipc_soft_map, v2, size); /*0x147300*/
          }
          v5 = (unsigned __int8 *)(v8 + 1); /*0x147308*/
        }
      }
      while ( v19 > (unsigned int)v5 ); /*0x14730e*/
    }
  }
  return v2; /*0x147317*/
}
