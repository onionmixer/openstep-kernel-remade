/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aeb34. */
int __cdecl -[SCSIGeneric setSCSI3Target:lun:isRoot:](
        SCSIGeneric *self,
        SEL a2,
        unsigned __int64 a3,
        unsigned __int64 a4,
        char a5)
{
  if ( (int)objc_msgSend(self->_controller, sel_numberOfTargets) <= a3 || a4 > 8 ) /*0x1aeb87*/
    return -706; /*0x1aeb8e*/
  -[SCSIGeneric clearReservation](self, sel_clearReservation); /*0x1aeb98*/
  if ( objc_msgSend(self->_controller, sel_reserveSCSI3Target_lun_forOwner_, a3, a4, self) ) /*0x1aebb4*/
  {
    if ( !a5 ) /*0x1aebc1*/
      return -725; /*0x1aebc8*/
  }
  else
  {
    self->_isReserved = 1; /*0x1aebcc*/
  }
  self->_target = a3; /*0x1aebd6*/
  self->_lun = (unsigned int)a4; /*0x1aebe5*/
  *((_BYTE *)self + 292) |= 1u; /*0x1aebf4*/
  return 0; /*0x1aec00*/
}
