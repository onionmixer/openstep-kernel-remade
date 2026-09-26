/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107a78. */
int setprivexec()
{
  _DWORD *v0; // ebx

  v0 = *(_DWORD **)(dword_1E875C + 36); /*0x107a81*/
  *(_DWORD *)(*(_DWORD *)(active_threads + 132) + 96) = (char)(*(_BYTE *)(*(_DWORD *)active_u + 22) << 7) >> 7; /*0x107aa2*/
  *(_BYTE *)(*(_DWORD *)active_u + 22) = (*v0 != 0) | *(_BYTE *)(*(_DWORD *)active_u + 22) & 0xFE; /*0x107ab9*/
  return 0; /*0x107abe*/
}
