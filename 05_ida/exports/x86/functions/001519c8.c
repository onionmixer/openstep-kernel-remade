/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1519c8. */
int ipc_table_init()
{
  unsigned int v0; // ebx
  vm_size_t v1; // esi
  vm_size_t i; // edi
  unsigned int j; // esi
  unsigned int v4; // ebx
  vm_size_t v5; // esi
  vm_size_t k; // edi
  unsigned int m; // esi
  int result; // eax
  unsigned int v9; // [esp+10h] [ebp-14h]
  unsigned int v10; // [esp+10h] [ebp-14h]
  unsigned int v11; // [esp+14h] [ebp-10h]
  int v12; // [esp+18h] [ebp-Ch]
  unsigned int v13; // [esp+1Ch] [ebp-8h]
  int v14; // [esp+20h] [ebp-4h]

  ipc_table_entries = kalloc(4 * ipc_table_entries_size); /*0x1519e4*/
  v14 = ipc_table_entries; /*0x1519e9*/
  v13 = ipc_table_entries_size - 1; /*0x1519f3*/
  v0 = 0; /*0x1519f9*/
  v9 = 1; /*0x1519fb*/
  if ( ipc_table_entries_size != 1 ) /*0x151a04*/
  {
    v1 = page_size; /*0x151a06*/
    do /*0x151a30*/
    {
      if ( v9 >= v1 ) /*0x151a0f*/
        break; /*0x151a0f*/
      if ( v9 >= 0x40 ) /*0x151a15*/
        *(_DWORD *)(v14 + 4 * v0++) = v9 / 0x10; /*0x151a26*/
      v9 *= 2; /*0x151a2a*/
    }
    while ( v13 > v0 ); /*0x151a30*/
  }
  for ( i = page_size; v13 > v0; i *= 2 ) /*0x151a3b*/
  {
    for ( j = 0; j <= 0xE; ++j ) /*0x151a40*/
    {
      if ( v13 <= v0 ) /*0x151a47*/
        break; /*0x151a47*/
      if ( v9 >= 0x40 ) /*0x151a4d*/
        *(_DWORD *)(v14 + 4 * v0++) = v9 / 0x10; /*0x151a5e*/
      v9 += i; /*0x151a63*/
    }
  }
  *(_DWORD *)(ipc_table_entries + 4 * ipc_table_entries_size - 4) = *(_DWORD *)(ipc_table_entries /*0x151a81*/
                                                                              + 4 * ipc_table_entries_size
                                                                              - 8);
  ipc_table_dnrequests = kalloc(4 * ipc_table_dnrequests_size); /*0x151a98*/
  v12 = ipc_table_dnrequests; /*0x151a9d*/
  v11 = ipc_table_dnrequests_size - 1; /*0x151aa7*/
  v4 = 0; /*0x151aaa*/
  v10 = 1; /*0x151aac*/
  if ( ipc_table_dnrequests_size != 1 ) /*0x151ab5*/
  {
    v5 = page_size; /*0x151ab7*/
    do /*0x151ae4*/
    {
      if ( v10 >= v5 ) /*0x151ac3*/
        break; /*0x151ac3*/
      if ( v10 >= 0x10 ) /*0x151ac9*/
        *(_DWORD *)(v12 + 4 * v4++) = v10 / 8; /*0x151ada*/
      v10 *= 2; /*0x151ade*/
    }
    while ( v11 > v4 ); /*0x151ae4*/
  }
  for ( k = page_size; v11 > v4; k *= 2 ) /*0x151aef*/
  {
    for ( m = 0; m <= 0xE; ++m ) /*0x151af4*/
    {
      if ( v11 <= v4 ) /*0x151afb*/
        break; /*0x151afb*/
      if ( v10 >= 0x10 ) /*0x151b01*/
        *(_DWORD *)(v12 + 4 * v4++) = v10 / 8; /*0x151b12*/
      v10 += k; /*0x151b17*/
    }
  }
  result = ipc_table_dnrequests; /*0x151b2c*/
  *(_DWORD *)(ipc_table_dnrequests + 4 * ipc_table_dnrequests_size - 4) = 0; /*0x151b31*/
  return result; /*0x151b3c*/
}
