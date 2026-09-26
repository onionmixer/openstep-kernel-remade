/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12ed7c. */
int __cdecl nfs_netboot_prealloc(int a1)
{
  unsigned int i; // ebx
  unsigned int j; // ebx
  int result; // eax
  char *v4; // edi
  unsigned int v5; // ebx
  int v6; // esi
  _DWORD v7[6]; // [esp+Ch] [ebp-18h]

  MAXCLIENTS += 3; /*0x12ed90*/
  for ( i = 0; MAXCLIENTS > i; ++i ) /*0x12ed99*/
    v7[i] = sub_12EA98(a1, *(_DWORD *)(active_u + 28)); /*0x12edab*/
  for ( j = 0; MAXCLIENTS > j; ++j ) /*0x12edc3*/
  {
    if ( v7[j] ) /*0x12edc8*/
      sub_12EE3C(v7[j]); /*0x12edd1*/
  }
  result = kalloc(8800 * MAXCLIENTS); /*0x12edf8*/
  v4 = (char *)result; /*0x12edfd*/
  v5 = 0; /*0x12edff*/
  if ( MAXCLIENTS ) /*0x12ee0a*/
  {
    v6 = 0; /*0x12ee0c*/
    do /*0x12ee30*/
    {
      result = clntkudp_realloc(dword_1EEF38[v6], v4); /*0x12ee18*/
      v4 += 8800; /*0x12ee1d*/
      v6 += 3; /*0x12ee26*/
      ++v5; /*0x12ee29*/
    }
    while ( MAXCLIENTS > v5 ); /*0x12ee30*/
  }
  return result; /*0x12ee35*/
}
