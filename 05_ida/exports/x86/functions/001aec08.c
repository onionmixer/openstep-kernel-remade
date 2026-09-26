/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aec08. */
int __cdecl -[SCSIGeneric setController:](SCSIGeneric *self, SEL a2, unsigned int a3)
{
  int v4; // [esp+Ch] [ebp-10h] BYREF
  char __s1[12]; // [esp+10h] [ebp-Ch] BYREF

  if ( self->_controllerNum == a3 ) /*0x1aec1d*/
    return 0; /*0x1aec1f*/
  -[SCSIGeneric clearReservation](self, sel_clearReservation); /*0x1aec2c*/
  sprintf(__s1, "sc%d", a3); /*0x1aec3b*/
  if ( IOGetObjectForDeviceName(__s1, (int)&v4) ) /*0x1aec45*/
    return -704; /*0x1aec68*/
  self->_controllerNum = a3; /*0x1aec4e*/
  self->_controller = (id)v4; /*0x1aec57*/
  *((_BYTE *)self + 292) &= ~1u; /*0x1aec5d*/
  return 0; /*0x1aec70*/
}
