/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ce08. */
void __cdecl addupc(int a1, int a2, __int16 a3)
{
  int v3; // ebx
  unsigned int v4; // edx
  unsigned int v5; // eax
  unsigned int v6; // esi
  unsigned __int16 v7; // [esp+12h] [ebp-2h] BYREF

  v3 = a2; /*0x18ce11*/
  if ( a2 ) /*0x18ce16*/
  {
    while ( 1 ) /*0x18ce3c*/
    {
      v4 = ((*(_DWORD *)(v3 + 20) * (unsigned int)(unsigned __int16)(a1 - *(_WORD *)(v3 + 16))) >> 16) /*0x18ce3c*/
         + *(_DWORD *)(v3 + 20) * ((unsigned int)(a1 - *(_DWORD *)(v3 + 16)) >> 16);
      LOBYTE(v4) = v4 & 0xFE; /*0x18ce3e*/
      v5 = *(_DWORD *)(v3 + 8); /*0x18ce41*/
      v6 = v4 + v5; /*0x18ce44*/
      if ( v4 + v5 >= v5 && v6 < *(_DWORD *)(v3 + 12) + v5 ) /*0x18ce50*/
        break; /*0x18ce50*/
      v3 = *(_DWORD *)(v3 + 4); /*0x18ce8c*/
      if ( !v3 ) /*0x18ce91*/
        return; /*0x18ce91*/
    }
    if ( copyin(v6, (unsigned int)&v7, 2) ) /*0x18ce59*/
    {
      *(_DWORD *)(a2 + 20) = 0; /*0x18ce68*/
    }
    else
    {
      v7 += a3; /*0x18ce78*/
      copyout(&v7, v6, 2); /*0x18ce83*/
    }
  }
}
