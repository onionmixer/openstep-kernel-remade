/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aea64. */
int __cdecl -[SCSIGeneric setTarget:lun:isRoot:](
        SCSIGeneric *self,
        SEL a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        char a5)
{
  if ( a3 >= (int)objc_msgSend(self->_controller, sel_numberOfTargets) || a4 > 8u ) /*0x1aeaa4*/
    return -706; /*0x1aeaab*/
  -[SCSIGeneric clearReservation](self, sel_clearReservation); /*0x1aeab8*/
  if ( objc_msgSend(self->_controller, sel_reserveSCSI3Target_lun_forOwner_, a3, 0, a4, 0, self) ) /*0x1aeada*/
  {
    if ( !a5 ) /*0x1aeae7*/
      return -725; /*0x1aeaee*/
  }
  else
  {
    self->_isReserved = 1; /*0x1aeaf0*/
  }
  self->_target = a3; /*0x1aeb00*/
  self->_lun = a4; /*0x1aeb12*/
  *((_BYTE *)self + 292) |= 1u; /*0x1aeb1e*/
  return 0; /*0x1aeb2a*/
}
