/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13f52c. */
int __cdecl sub_13F52C(int a1, int a2, __int16 a3, int a4)
{
  unsigned __int16 v4; // ax
  unsigned int v5; // ecx
  unsigned __int16 v6; // dx
  int v7; // eax

  v4 = *(_WORD *)(a2 + 4); /*0x13f544*/
  if ( (v4 & 3) == 0 ) /*0x13f54a*/
  {
    v5 = v4; /*0x13f54c*/
    if ( v4 <= 1024 - (a3 & 0x3FF) ) /*0x13f551*/
    {
      v6 = *(_WORD *)(a2 + 6); /*0x13f553*/
      v7 = v6 + 4; /*0x13f55a*/
      LOBYTE(v7) = (v6 + 4) & 0xFC; /*0x13f55d*/
      if ( v5 >= v7 + 8 && v6 <= 0xFFu && (!dirchk || !sub_13F5D8(a2 + 8, v6)) ) /*0x13f57b*/
        return 0; /*0x13f5a0*/
    }
  }
  sub_13F5AC(a1, aMangledEntry_0, a4); /*0x13f594*/
  return 1; /*0x13f5a5*/
}
