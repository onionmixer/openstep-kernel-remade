/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c6520. */
void __cdecl -[IOSVGADisplay _checkShield:shmem:](
        IOSVGADisplay *self,
        SEL a2,
        $514E7C50D28E54AB164B6500F83867A3 *a3,
        $E63760587FADDAA675F803BB3FBE6402 *a4)
{
  int v4; // eax
  int v5; // edx
  unsigned __int16 v6; // bx
  int v7; // ebx
  __int16 v8; // si
  int v9; // [esp+Ch] [ebp-4h]

  v4 = *(_DWORD *)a4; /*0x1c652c*/
  v5 = *((_DWORD *)a4 + *(_DWORD *)a4 + 14); /*0x1c652e*/
  v6 = *((_WORD *)a4 + 14) - v5; /*0x1c6539*/
  LOWORD(v4) = v6 + 16; /*0x1c653c*/
  v7 = v6 | (v4 << 16); /*0x1c654a*/
  v8 = *((_WORD *)a4 + 15) - HIWORD(v5); /*0x1c6556*/
  v9 = 0; /*0x1c6567*/
  if ( *((__int16 *)a4 + 11) > (__int16)v7 && *((__int16 *)a4 + 10) < SHIWORD(v7) && *((__int16 *)a4 + 13) > v8 ) /*0x1c6583*/
    v9 = *((_WORD *)a4 + 12) < (unsigned __int16)(v8 + 16); /*0x1c6590*/
  if ( v9 != *((char *)a4 + 11) ) /*0x1c659a*/
  {
    *((_BYTE *)a4 + 11) = v9; /*0x1c659f*/
    if ( (_BYTE)v9 ) /*0x1c65a4*/
      -[IOSVGADisplay _sysHideCursor:shmem:](self, sel__sysHideCursor_shmem_, a3, a4); /*0x1c65b1*/
    else
      -[IOSVGADisplay _sysShowCursor:shmem:](self, sel__sysShowCursor_shmem_, a3, a4); /*0x1c65c4*/
  }
}
