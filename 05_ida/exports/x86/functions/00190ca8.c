/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x190ca8. */
unsigned int __cdecl pmap_resident_extract(_DWORD *a1, unsigned int a2)
{
  _BYTE *v2; // eax
  _DWORD *v3; // eax

  v2 = (_BYTE *)(*a1 + 4 * (a2 >> 22)); /*0x190cb9*/
  if ( (*v2 & 1) != 0 /*0x190cd9*/
    && (v3 = (_DWORD *)((*(_DWORD *)v2 & 0xFFFFF000) + ((a2 >> 10) & 0xFFC))) != nullptr
    && (*(_BYTE *)v3 & 1) != 0 )
  {
    return (*v3 & 0xFFFFF000) + (a2 & 0xFFF); /*0x190cf3*/
  }
  else
  {
    return 0; /*0x190cdb*/
  }
}
