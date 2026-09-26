/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10d850. */
int __cdecl soo_rw(int a1, int a2, int a3)
{
  int v3; // eax
  int (__cdecl *v4)(int, int, int, int, int); // eax

  if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x10d864*/
  {
    v3 = *(_DWORD *)(a1 + 8); /*0x10d866*/
    if ( (v3 & 0x2000) != 0 ) /*0x10d86c*/
      *(_WORD *)(a3 + 16) = v3; /*0x10d86e*/
  }
  v4 = sosend; /*0x10d872*/
  if ( !a2 ) /*0x10d87b*/
    v4 = soreceive; /*0x10d87d*/
  return v4(*(_DWORD *)(a1 + 24), 0, a3, 0, 0); /*0x10d891*/
}
