/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c6764. */
id __cdecl -[IOSVGADisplay showCursor:frame:token:](
        IOSVGADisplay *self,
        SEL a2,
        $9B414A52084CF78D000E95AF47DF0AD5 *a3,
        int a4,
        int a5)
{
  id v5; // ebx
  $514E7C50D28E54AB164B6500F83867A3 *v7; // eax
  $514E7C50D28E54AB164B6500F83867A3 *v8; // eax

  v5 = -[IOSVGADisplay _shmem](self, sel__shmem); /*0x1c677a*/
  if ( !ev_try_lock((volatile signed __int32 *)v5 + 1) ) /*0x1c6780*/
    return self; /*0x1c678c*/
  *(_DWORD *)v5 = a4; /*0x1c6793*/
  *(($9B414A52084CF78D000E95AF47DF0AD5 *)v5 + 7) = *a3; /*0x1c679a*/
  if ( *((_BYTE *)v5 + 10) ) /*0x1c679d*/
  {
    v7 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c67ac*/
    -[IOSVGADisplay _checkShield:shmem:](self, sel__checkShield_shmem_, v7); /*0x1c67bd*/
  }
  v8 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c67ce*/
  -[IOSVGADisplay _sysShowCursor:shmem:](self, sel__sysShowCursor_shmem_, v8); /*0x1c67df*/
  ev_unlock((_DWORD *)v5 + 1); /*0x1c67e5*/
  return self; /*0x1c67ef*/
}
