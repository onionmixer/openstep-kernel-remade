/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1abd54. */
int __cdecl -[IOSCSIController reserveSCSI3Target:lun:forOwner:](
        IOSCSIController *self,
        SEL a2,
        unsigned __int64 a3,
        unsigned __int64 a4,
        id a5)
{
  int v5; // edi
  int v6; // eax
  $BAB6C68F9D34F0972F921D3DB17D7446 *p_reserveQ; // ecx
  queue_entry *prev; // edx

  v5 = 0; /*0x1abd60*/
  objc_msgSend(self->_reserveLock, sel_lock); /*0x1abd76*/
  if ( (int)a3 >= -[IOSCSIController numberOfTargets](self, sel_numberOfTargets) /*0x1abda4*/
    || -[IOSCSIController searchReserveQ:lun:](self, sel_searchReserveQ_lun_, a3, a4) )
  {
    v5 = 1; /*0x1abdb0*/
  }
  else
  {
    v6 = IOMalloc(0x1Cu); /*0x1abdce*/
    *(_QWORD *)v6 = a3; /*0x1abdd6*/
    *(_QWORD *)(v6 + 8) = a4; /*0x1abde1*/
    *(_DWORD *)(v6 + 16) = a5; /*0x1abded*/
    p_reserveQ = &self->_reserveQ; /*0x1abdf3*/
    if ( ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->_reserveQ.next == &self->_reserveQ ) /*0x1abdff*/
    {
      self->_reserveQ.next = (queue_entry *)v6; /*0x1abdb8*/
      self->_reserveQ.prev = (queue_entry *)v6; /*0x1abdbe*/
      *(_DWORD *)(v6 + 20) = p_reserveQ; /*0x1abdc4*/
      *(_DWORD *)(v6 + 24) = p_reserveQ; /*0x1abdc7*/
    }
    else
    {
      prev = self->_reserveQ.prev; /*0x1abe01*/
      *(_DWORD *)(v6 + 24) = prev; /*0x1abe07*/
      *(_DWORD *)(v6 + 20) = p_reserveQ; /*0x1abe0a*/
      self->_reserveQ.prev = (queue_entry *)v6; /*0x1abe0d*/
      *((_DWORD *)prev + 5) = v6; /*0x1abe13*/
    }
    ++self->_reserveCount; /*0x1abe16*/
  }
  objc_msgSend(self->_reserveLock, sel_unlock); /*0x1abe2a*/
  return v5; /*0x1abe34*/
}
