/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12f42c. */
int __cdecl setdirgid(int a1)
{
  if ( (*(_BYTE *)(*(_DWORD *)(a1 + 36) + 12) & 0x10) != 0 || (*(_BYTE *)(*(_DWORD *)(a1 + 48) + 133) & 4) != 0 ) /*0x12f445*/
    return *(__int16 *)(*(_DWORD *)(a1 + 48) + 136); /*0x12f45b*/
  else
    return *(__int16 *)(*(_DWORD *)(active_u + 28) + 4); /*0x12f44f*/
}
