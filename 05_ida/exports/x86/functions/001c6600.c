/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c6600. */
id __cdecl -[IOSVGADisplay hideCursor:](IOSVGADisplay *self, SEL a2, int a3)
{
  id v3; // eax
  $514E7C50D28E54AB164B6500F83867A3 *v4; // eax
  $E63760587FADDAA675F803BB3FBE6402 *v5; // eax

  v3 = -[IOSVGADisplay _shmem](self, sel__shmem); /*0x1c660f*/
  if ( ev_try_lock((volatile signed __int32 *)v3 + 1) ) /*0x1c6618*/
  {
    -[IOSVGADisplay _shmem](self, sel__shmem); /*0x1c662c*/
    v4 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c663a*/
    -[IOSVGADisplay _sysHideCursor:shmem:](self, sel__sysHideCursor_shmem_, v4); /*0x1c664b*/
    v5 = -[IOSVGADisplay _shmem](self, sel__shmem); /*0x1c6658*/
    ev_unlock((_DWORD *)v5 + 1); /*0x1c6661*/
  }
  return self; /*0x1c6668*/
}
