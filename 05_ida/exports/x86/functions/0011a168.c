/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11a168. */
int __cdecl bwrite(int *a1)
{
  int v1; // esi
  int result; // eax

  v1 = *a1; /*0x11a171*/
  *a1 &= 0xFFFFFDF8; /*0x11a17b*/
  if ( (v1 & 0x200) == 0 ) /*0x11a185*/
    ++*(_DWORD *)(active_u + 416); /*0x11a18c*/
  if ( a1[5] > a1[6] ) /*0x11a198*/
    panic(aBwrite); /*0x11a19f*/
  result = (*(int (__cdecl **)(int *))(*(_DWORD *)(a1[16] + 28) + 84))(a1); /*0x11a1b1*/
  if ( (v1 & 0x100) != 0 ) /*0x11a1bc*/
  {
    if ( (v1 & 0x200) != 0 ) /*0x11a1ce*/
      *(_BYTE *)a1 |= 0x80u; /*0x11a1d0*/
  }
  else
  {
    biowait((unsigned int)a1); /*0x11a1bf*/
    return brelse((int)a1); /*0x11a1c5*/
  }
  return result; /*0x11a1d6*/
}
