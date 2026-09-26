/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c64c0. */
void __cdecl -[IOSVGADisplay _sysHideCursor:shmem:](
        IOSVGADisplay *self,
        SEL a2,
        $514E7C50D28E54AB164B6500F83867A3 *a3,
        $E63760587FADDAA675F803BB3FBE6402 *a4)
{
  char v4; // al

  v4 = *((_BYTE *)a4 + 8); /*0x1c64c6*/
  *((_BYTE *)a4 + 8) = v4 + 1; /*0x1c64c9*/
  if ( !v4 ) /*0x1c64ce*/
    -[IOSVGADisplay _VGARemoveCursor:shmem:](self, sel__VGARemoveCursor_shmem_, a3, a4); /*0x1c64e0*/
}
