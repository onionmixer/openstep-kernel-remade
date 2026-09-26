/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c6460. */
void __cdecl -[IOSVGADisplay _displayCursor:shmem:](
        IOSVGADisplay *self,
        SEL a2,
        $514E7C50D28E54AB164B6500F83867A3 *a3,
        $E63760587FADDAA675F803BB3FBE6402 *a4)
{
  int v4; // edx
  __int16 v5; // cx
  __int16 v6; // ax
  int v7; // ecx

  v4 = *((_DWORD *)a4 + *(_DWORD *)a4 + 14); /*0x1c6469*/
  v5 = *((_WORD *)a4 + 14) - v4; /*0x1c6471*/
  *((_WORD *)a4 + 16) = v5; /*0x1c6474*/
  *((_WORD *)a4 + 17) = v5 + 16; /*0x1c647c*/
  v6 = *((_WORD *)a4 + 15) - HIWORD(v4); /*0x1c6487*/
  *((_WORD *)a4 + 18) = v6; /*0x1c648c*/
  *((_WORD *)a4 + 19) = v6 + 16; /*0x1c6494*/
  -[IOSVGADisplay _VGADisplayCursor:shmem:](self, sel__VGADisplayCursor_shmem_, a3, a4); /*0x1c64a7*/
  v7 = *((_DWORD *)a4 + 9); /*0x1c64af*/
  *((_DWORD *)a4 + 10) = *((_DWORD *)a4 + 8); /*0x1c64b2*/
  *((_DWORD *)a4 + 11) = v7; /*0x1c64b5*/
}
