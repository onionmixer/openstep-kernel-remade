/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16a490. */
int __cdecl zinit(int a1, int a2, vm_size_t a3, char a4, int a5)
{
  vm_size_t v5; // esi
  int v6; // ebx
  int v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // esi
  char v10; // al

  v5 = a3; /*0x16a499*/
  if ( zone_zone ) /*0x16a4a3*/
    v6 = zalloc(zone_zone); /*0x16a4d6*/
  else
    v6 = zget_space(&_zone_default_space, 68, 0); /*0x16a4b3*/
  if ( !v6 ) /*0x16a4dd*/
    panic(aZinit); /*0x16a4e4*/
  if ( !a3 ) /*0x16a4ee*/
    v5 = page_size; /*0x16a4f0*/
  if ( !a1 ) /*0x16a4fa*/
    a1 = 4; /*0x16a4fc*/
  v7 = a1 + 15; /*0x16a506*/
  v8 = ~page_mask & (page_mask + a2); /*0x16a51c*/
  v9 = ~page_mask & (v5 + page_mask); /*0x16a522*/
  if ( v8 < v9 ) /*0x16a526*/
    v8 = v9; /*0x16a528*/
  *(_DWORD *)(v6 + 16) = 0; /*0x16a52a*/
  *(_DWORD *)(v6 + 12) = 0; /*0x16a531*/
  *(_DWORD *)(v6 + 20) = 0; /*0x16a538*/
  *(_DWORD *)(v6 + 24) = v8; /*0x16a53f*/
  LOBYTE(v7) = (a1 + 15) & 0xF0; /*0x16a509*/
  *(_DWORD *)(v6 + 28) = v7; /*0x16a545*/
  *(_DWORD *)(v6 + 32) = v9; /*0x16a548*/
  *(_BYTE *)(v6 + 44) = a4 & 1 | *(_BYTE *)(v6 + 44) & 0xFE; /*0x16a558*/
  *(_DWORD *)(v6 + 40) = a5; /*0x16a55e*/
  *(_DWORD *)(v6 + 8) = 0; /*0x16a561*/
  *(_DWORD *)(v6 + 36) = 0; /*0x16a568*/
  v10 = *(_BYTE *)(v6 + 44) & 0xF1 | 8; /*0x16a574*/
  *(_BYTE *)(v6 + 44) = v10; /*0x16a576*/
  if ( (v10 & 1) != 0 ) /*0x16a57b*/
    lock_init((_DWORD *)(v6 + 48), 1); /*0x16a4c2*/
  else
    *(_DWORD *)v6 = 0; /*0x16a581*/
  sub_16AF6C(v6); /*0x16a588*/
  *(_DWORD *)(v6 + 64) = 0; /*0x16a58d*/
  do /*0x16a5ad*/
  {
    while ( all_zones_lock ) /*0x16a59b*/
      ; /*0x16a599*/
  }
  while ( _InterlockedExchange(&all_zones_lock, 1) == 1 ); /*0x16a5ad*/
  *(_DWORD *)last_zone = v6; /*0x16a5b4*/
  last_zone = v6 + 64; /*0x16a5b9*/
  ++num_zones; /*0x16a5bf*/
  _InterlockedExchange(&all_zones_lock, 0); /*0x16a5c7*/
  return v6; /*0x16a5d2*/
}
