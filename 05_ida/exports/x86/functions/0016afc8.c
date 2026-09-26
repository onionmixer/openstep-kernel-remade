/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16afc8. */
void zone_bootstrap()
{
  int *v0; // ebx
  unsigned int v1; // edx
  unsigned int v2; // esi
  char v3; // al
  unsigned int v4; // esi
  int *v5; // ebx
  int v6; // eax
  unsigned int v7; // eax
  int *v8; // eax
  unsigned int v9; // esi
  int *v10; // ebx
  int v11; // eax
  unsigned int v12; // eax
  int *v13; // eax
  unsigned int v14; // esi
  vm_size_t v15; // edi
  int *v16; // ebx
  int v17; // eax
  unsigned int v18; // eax
  int *v19; // eax
  int *v20; // [esp+Ch] [ebp-8h]
  int *v21; // [esp+Ch] [ebp-8h]
  int *v22; // [esp+10h] [ebp-4h]

  all_zones_lock = 0; /*0x16afd1*/
  first_zone = 0; /*0x16afdb*/
  last_zone = (int)&first_zone; /*0x16afe5*/
  num_zones = 0; /*0x16afef*/
  zget_space_lock = 0; /*0x16aff9*/
  dword_1F6DC4 = (int)&_zone_default_space_hint; /*0x16b003*/
  dword_1F6DC8 = 1; /*0x16b00d*/
  zone_free_space[0] = (int)_zone_default_space; /*0x16b017*/
  zone_free_space_count = 1; /*0x16b021*/
  zone_zone = 0; /*0x16b02b*/
  v0 = zget_space(_zone_default_space, 0x44u, 0); /*0x16b04f*/
  if ( !v0 ) /*0x16b056*/
    panic(aZinit); /*0x16b05d*/
  v1 = ~page_mask & (page_mask + 8704); /*0x16b07f*/
  v2 = ~page_mask & (page_mask + 68); /*0x16b085*/
  if ( v1 < v2 ) /*0x16b089*/
    v1 = ~page_mask & (page_mask + 68); /*0x16b08b*/
  v0[4] = 0; /*0x16b08d*/
  v0[3] = 0; /*0x16b094*/
  v0[5] = 0; /*0x16b09b*/
  v0[6] = v1; /*0x16b0a2*/
  v0[7] = 80; /*0x16b0a8*/
  v0[8] = v2; /*0x16b0ab*/
  *((_BYTE *)v0 + 44) &= ~1u; /*0x16b0ae*/
  v0[10] = (int)aZones; /*0x16b0b2*/
  v0[2] = 0; /*0x16b0b9*/
  v0[9] = 0; /*0x16b0c0*/
  v3 = v0[11] & 0xF1 | 8; /*0x16b0cc*/
  *((_BYTE *)v0 + 44) = v3; /*0x16b0ce*/
  if ( (v3 & 1) != 0 ) /*0x16b0d3*/
    lock_init(v0 + 12, 1); /*0x16b0db*/
  else
    *v0 = 0; /*0x16b0e8*/
  sub_16AF6C(v0); /*0x16b0ef*/
  v0[16] = 0; /*0x16b0f4*/
  do /*0x16b119*/
  {
    while ( all_zones_lock ) /*0x16b107*/
      ; /*0x16b105*/
  }
  while ( _InterlockedExchange(&all_zones_lock, 1) == 1 ); /*0x16b119*/
  *(_DWORD *)last_zone = v0; /*0x16b120*/
  last_zone = (int)(v0 + 16); /*0x16b125*/
  ++num_zones; /*0x16b12b*/
  _InterlockedExchange(&all_zones_lock, 0); /*0x16b133*/
  zone_zone = (int)v0; /*0x16b139*/
  v4 = 16; /*0x16b13f*/
  if ( (unsigned int)zone_free_space_count <= 7 ) /*0x16b14c*/
  {
    v20 = &zone_free_space[zone_free_space_count++]; /*0x16b159*/
    v5 = zget_space(_zone_default_space, 0x1Cu, 0); /*0x16b170*/
    *v5 = 16; /*0x16b172*/
    v5[1] = 96; /*0x16b178*/
    v5[2] = 0; /*0x16b17f*/
    v5[3] = 0; /*0x16b186*/
    v5[4] = 0; /*0x16b18d*/
    do /*0x16b1a9*/
    {
      v6 = v5[4]; /*0x16b198*/
      v5[4] = v6 + 1; /*0x16b19e*/
      v4 >>= 1; /*0x16b1a1*/
    }
    while ( (v4 & 1) == 0 ); /*0x16b1a9*/
    v7 = (unsigned int)v5[1] >> (v6 + 1); /*0x16b1b3*/
    v5[6] = v7; /*0x16b1b5*/
    v8 = zget_space(_zone_default_space, 16 * v7, 0); /*0x16b1c3*/
    v5[5] = (int)v8; /*0x16b1ca*/
    bzero(v8, 16 * v5[6]); /*0x16b1d5*/
    *v20 = (int)v5; /*0x16b1dd*/
  }
  v9 = 128; /*0x16b1e2*/
  if ( (unsigned int)zone_free_space_count <= 7 ) /*0x16b1ef*/
  {
    v21 = &zone_free_space[zone_free_space_count++]; /*0x16b1fc*/
    v10 = zget_space(_zone_default_space, 0x1Cu, 0); /*0x16b213*/
    *v10 = 128; /*0x16b215*/
    v10[1] = 768; /*0x16b21b*/
    v10[2] = 0; /*0x16b222*/
    v10[3] = 0; /*0x16b229*/
    v10[4] = 0; /*0x16b230*/
    do /*0x16b24d*/
    {
      v11 = v10[4]; /*0x16b23c*/
      v10[4] = v11 + 1; /*0x16b242*/
      v9 >>= 1; /*0x16b245*/
    }
    while ( (v9 & 1) == 0 ); /*0x16b24d*/
    v12 = (unsigned int)v10[1] >> (v11 + 1); /*0x16b257*/
    v10[6] = v12; /*0x16b259*/
    v13 = zget_space(_zone_default_space, 16 * v12, 0); /*0x16b267*/
    v10[5] = (int)v13; /*0x16b26e*/
    bzero(v13, 16 * v10[6]); /*0x16b279*/
    *v21 = (int)v10; /*0x16b281*/
  }
  v14 = 1024; /*0x16b286*/
  v15 = page_size; /*0x16b28b*/
  if ( (unsigned int)zone_free_space_count <= 7 ) /*0x16b29c*/
  {
    v22 = &zone_free_space[zone_free_space_count++]; /*0x16b2a9*/
    v16 = zget_space(_zone_default_space, 0x1Cu, 0); /*0x16b2c0*/
    *v16 = 1024; /*0x16b2c2*/
    v16[1] = v15; /*0x16b2c8*/
    v16[2] = 0; /*0x16b2cb*/
    v16[3] = 0; /*0x16b2d2*/
    v16[4] = 0; /*0x16b2d9*/
    do /*0x16b2f5*/
    {
      v17 = v16[4]; /*0x16b2e4*/
      v16[4] = v17 + 1; /*0x16b2ea*/
      v14 >>= 1; /*0x16b2ed*/
    }
    while ( (v14 & 1) == 0 ); /*0x16b2f5*/
    v18 = (unsigned int)v16[1] >> (v17 + 1); /*0x16b2ff*/
    v16[6] = v18; /*0x16b301*/
    v19 = zget_space(_zone_default_space, 16 * v18, 0); /*0x16b30f*/
    v16[5] = (int)v19; /*0x16b316*/
    bzero(v19, 16 * v16[6]); /*0x16b321*/
    *v22 = (int)v16; /*0x16b329*/
  }
}
