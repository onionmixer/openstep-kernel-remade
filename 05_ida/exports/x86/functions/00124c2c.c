/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x124c2c. */
int __cdecl sub_124C2C(int a1, int a2, int a3, _DWORD *a4)
{
  __int16 v4; // ax
  int result; // eax
  __int16 v6; // ax
  __int16 v7; // ax

  v4 = *(_WORD *)(a1 + 12); /*0x124c3b*/
  LOBYTE(v4) = v4 & 0xFE; /*0x124c3f*/
  *(_WORD *)(a2 + 16) = v4; /*0x124c41*/
  result = ifioctl(a3, -2145359600, (_DWORD *)a2); /*0x124c4c*/
  if ( !result ) /*0x124c56*/
  {
    v6 = *(_WORD *)(a1 + 12); /*0x124c58*/
    HIBYTE(v6) &= ~0x40u; /*0x124c5c*/
    *(_WORD *)(a1 + 12) = v6; /*0x124c5f*/
    bzero((void *)(a2 + 16), 0x10u); /*0x124c69*/
    *(_WORD *)(a2 + 16) = 2; /*0x124c6e*/
    result = ifioctl(a3, -2145359594, (_DWORD *)a2); /*0x124c7b*/
    if ( !result ) /*0x124c85*/
    {
      *(_DWORD *)(a2 + 20) = *a4; /*0x124c8c*/
      result = ifioctl(a3, -2145359604, (_DWORD *)a2); /*0x124c96*/
      if ( !result ) /*0x124c9d*/
      {
        v7 = *(_WORD *)(a1 + 12); /*0x124c9f*/
        HIBYTE(v7) |= 0x80u; /*0x124ca3*/
        *(_WORD *)(a1 + 12) = v7; /*0x124ca6*/
        return 0; /*0x124caa*/
      }
    }
  }
  return result; /*0x124caf*/
}
