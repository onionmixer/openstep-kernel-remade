/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x190b5c. */
int __cdecl pmap_change_wiring(_DWORD *a1, unsigned int a2, int a3)
{
  _BYTE *v3; // eax
  int v4; // ecx
  _BYTE *v5; // edx
  int v6; // eax
  unsigned int v8; // [esp+Ch] [ebp-Ch]
  int v9; // [esp+14h] [ebp-4h]

  v9 = splvm(); /*0x190b70*/
  v3 = (_BYTE *)(*a1 + 4 * (a2 >> 22)); /*0x190b7b*/
  if ( (*v3 & 1) == 0 || (v8 = ((a2 >> 10) & 0xFFC) + (*(_DWORD *)v3 & 0xFFFFF000)) == 0 ) /*0x190ba3*/
    panic(aPmapChangeWiri); /*0x190baa*/
  if ( a3 ) /*0x190bb6*/
  {
    if ( (*(_BYTE *)(((a2 >> 10) & 0xFFC) + (*(_DWORD *)v3 & 0xFFFFF000) + 1) & 2) == 0 ) /*0x190bc0*/
      sub_19108C(a1, a2); /*0x190bc4*/
  }
  else if ( (*(_BYTE *)(((a2 >> 10) & 0xFFC) + (*(_DWORD *)v3 & 0xFFFFF000) + 1) & 2) != 0 ) /*0x190bd4*/
  {
    sub_1910E4(a1, a2); /*0x190bd8*/
  }
  v4 = ptes_per_vm_page - 1; /*0x190be8*/
  if ( ptes_per_vm_page > 0 ) /*0x190beb*/
  {
    v5 = (_BYTE *)(v8 + 1); /*0x190bfa*/
    do /*0x190c0d*/
    {
      *v5 = (2 * (a3 & 1)) | *v5 & 0xFD; /*0x190c03*/
      v5 += 4; /*0x190c05*/
      v6 = v4--; /*0x190c08*/
    }
    while ( v6 > 0 ); /*0x190c0d*/
  }
  return splx(v9); /*0x190c1b*/
}
