/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c6670. */
id __cdecl -[IOSVGADisplay moveCursor:frame:token:](
        IOSVGADisplay *self,
        SEL a2,
        $9B414A52084CF78D000E95AF47DF0AD5 *a3,
        int a4,
        int a5)
{
  id v5; // ebx
  char v7; // al
  $514E7C50D28E54AB164B6500F83867A3 *v8; // eax
  char v9; // al
  $514E7C50D28E54AB164B6500F83867A3 *v10; // eax
  char v11; // al
  $514E7C50D28E54AB164B6500F83867A3 *v12; // eax

  v5 = -[IOSVGADisplay _shmem](self, sel__shmem); /*0x1c6689*/
  if ( !ev_try_lock((volatile signed __int32 *)v5 + 1) ) /*0x1c668f*/
    return self; /*0x1c669b*/
  *(_DWORD *)v5 = a4; /*0x1c66a7*/
  *(($9B414A52084CF78D000E95AF47DF0AD5 *)v5 + 7) = *a3; /*0x1c66ab*/
  v7 = *((_BYTE *)v5 + 8); /*0x1c66ae*/
  *((_BYTE *)v5 + 8) = v7 + 1; /*0x1c66b1*/
  if ( !v7 ) /*0x1c66b6*/
  {
    v8 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c66c1*/
    -[IOSVGADisplay _VGARemoveCursor:shmem:](self, sel__VGARemoveCursor_shmem_, v8); /*0x1c66d2*/
  }
  if ( *((_BYTE *)v5 + 9) ) /*0x1c66da*/
  {
    *((_BYTE *)v5 + 9) = 0; /*0x1c66e0*/
    v9 = *((_BYTE *)v5 + 8); /*0x1c66e4*/
    if ( v9 ) /*0x1c66e9*/
      *((_BYTE *)v5 + 8) = v9 - 1; /*0x1c66ed*/
  }
  if ( *((_BYTE *)v5 + 10) ) /*0x1c66f0*/
  {
    v10 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c66ff*/
    -[IOSVGADisplay _checkShield:shmem:](self, sel__checkShield_shmem_, v10); /*0x1c6710*/
  }
  v11 = *((_BYTE *)v5 + 8); /*0x1c6718*/
  if ( v11 ) /*0x1c671d*/
  {
    *((_BYTE *)v5 + 8) = v11 - 1; /*0x1c6723*/
    if ( v11 == 1 ) /*0x1c6728*/
    {
      v12 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c6733*/
      -[IOSVGADisplay _displayCursor:shmem:](self, sel__displayCursor_shmem_, v12); /*0x1c6744*/
    }
  }
  ev_unlock((_DWORD *)v5 + 1); /*0x1c6750*/
  return self; /*0x1c675a*/
}
