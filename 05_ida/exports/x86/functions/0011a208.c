/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11a208. */
int __cdecl bawrite(unsigned int *a1)
{
  int v1; // esi
  int result; // eax

  v1 = *a1 | 0x100; /*0x11a213*/
  *a1 = *a1 & 0xFFFFFCF8 | 0x100; /*0x11a223*/
  if ( (v1 & 0x200) == 0 ) /*0x11a22d*/
    ++*(_DWORD *)(active_u + 416); /*0x11a234*/
  if ( (int)a1[5] > (int)a1[6] ) /*0x11a240*/
    panic(aBwrite); /*0x11a247*/
  result = (*(int (__cdecl **)(unsigned int *))(*(_DWORD *)(a1[16] + 28) + 84))(a1); /*0x11a259*/
  if ( (v1 & 0x100) != 0 ) /*0x11a264*/
  {
    if ( (v1 & 0x200) != 0 ) /*0x11a276*/
      *(_BYTE *)a1 |= 0x80u; /*0x11a278*/
  }
  else
  {
    biowait((unsigned int)a1); /*0x11a267*/
    return brelse((int)a1); /*0x11a26d*/
  }
  return result; /*0x11a27e*/
}
