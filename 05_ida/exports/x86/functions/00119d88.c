/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x119d88. */
void __cdecl vnReadAhead(int a1, int a2, int a3)
{
  _DWORD *v3; // ebx
  int v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]
  int savedregs; // [esp+8h] [ebp+0h]

  if ( a2 && !incore(a1, a2) ) /*0x119d99*/
  {
    v3 = (_DWORD *)getblk(a1, a2, a3); /*0x119db0*/
    if ( (*v3 & 2) != 0 ) /*0x119db9*/
    {
      brelse((int)v3); /*0x119dbc*/
    }
    else
    {
      *v3 |= 0x101u; /*0x119dc9*/
      if ( v3[5] > v3[6] ) /*0x119dd1*/
        panic(aBreadrabp_0); /*0x119dd8*/
      (*(void (__stdcall **)(_DWORD *, int, int, int))(*(_DWORD *)(v3[16] + 28) + 84))(v3, v4, v5, savedregs); /*0x119dea*/
      ++*(_DWORD *)(active_u + 412); /*0x119df1*/
    }
  }
}
