/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ec70. */
unsigned int __cdecl pmap_pt_entry(_DWORD *a1, unsigned int a2)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)(*a1 + 4 * (a2 >> 22)); /*0x18ec81*/
  if ( (*(_BYTE *)v2 & 1) != 0 ) /*0x18ec86*/
    return (*v2 & 0xFFFFF000) + ((a2 >> 10) & 0xFFC); /*0x18ec9a*/
  else
    return 0; /*0x18eca0*/
}
