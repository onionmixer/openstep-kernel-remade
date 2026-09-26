/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aefd4. */
void __cdecl -[SCSIGeneric clearReservation](SCSIGeneric *self, SEL a2)
{
  const char *v2; // eax

  if ( self->_isReserved )
  {
    if ( (*((_BYTE *)self + 292) & 1) != 0 )
    {
      objc_msgSend( /*0x1af018*/
        self->_controller,
        sel_releaseSCSI3Target_lun_forOwner_,
        LODWORD(self->_target),
        HIDWORD(self->_target),
        LODWORD(self->_lun),
        HIDWORD(self->_lun),
        self);
      *((_BYTE *)self + 292) &= ~1u; /*0x1af01d*/
    }
    else
    {
      v2 = -[IODevice name](self, sel_name); /*0x1af030*/
      IOLog((int)"%s: clearReservation, no valid target\n", v2);
    }
    self->_isReserved = 0; /*0x1af040*/
  }
  *((_BYTE *)self + 292) &= ~1u; /*0x1af04a*/
}
