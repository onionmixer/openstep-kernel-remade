/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aaac8. */
void __cdecl -[IOEthernet enableMulticast:](IOEthernet *self, SEL a2, $D91DDCA3822F03E96939068EA8DE741A *a3)
{
  $3D9F9298DBF9489C64856F2E59AA9D10 *v3; // eax
  int var2; // ecx
  int v5; // eax
  int v6; // edx
  $BAB6C68F9D34F0972F921D3DB17D7446 *p_multicastQueue; // ecx
  queue_entry *prev; // eax

  if ( (a3->var0[0] & 1) != 0 ) /*0x1aaad7*/
  {
    objc_msgSend(self->_multiLock, sel_lock); /*0x1aaaeb*/
    v3 = -[IOEthernet searchMulti:](self, sel_searchMulti_, a3); /*0x1aaaf9*/
    if ( v3 ) /*0x1aab05*/
    {
      var2 = v3->var2; /*0x1aab07*/
      v3->var2 = var2 + 1; /*0x1aab0d*/
      if ( var2 + 1 < 0 ) /*0x1aab15*/
        v3->var2 = var2; /*0x1aab1b*/
    }
    else
    {
      v5 = IOMalloc(0x14u); /*0x1aab36*/
      v6 = v5; /*0x1aab3b*/
      *($D91DDCA3822F03E96939068EA8DE741A *)v5 = *a3; /*0x1aab3f*/
      *(_DWORD *)(v5 + 16) = 1; /*0x1aab49*/
      p_multicastQueue = &self->_multicastQueue; /*0x1aab53*/
      if ( ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->_multicastQueue.next == &self->_multicastQueue ) /*0x1aab5f*/
      {
        self->_multicastQueue.next = (queue_entry *)v5; /*0x1aab20*/
        self->_multicastQueue.prev = (queue_entry *)v5; /*0x1aab26*/
        *(_DWORD *)(v5 + 8) = p_multicastQueue; /*0x1aab2c*/
        *(_DWORD *)(v5 + 12) = p_multicastQueue; /*0x1aab2f*/
      }
      else
      {
        prev = self->_multicastQueue.prev; /*0x1aab61*/
        *(_DWORD *)(v6 + 12) = prev; /*0x1aab67*/
        *(_DWORD *)(v6 + 8) = p_multicastQueue; /*0x1aab6a*/
        self->_multicastQueue.prev = (queue_entry *)v6; /*0x1aab6d*/
        *((_DWORD *)prev + 2) = v6; /*0x1aab73*/
      }
      self->_multiAddr = ($0F52D4C2E1E8F22E8199E6D21C589DA7)*a3; /*0x1aab78*/
      objc_msgSend(self->_driverCmd, sel_send_, 7); /*0x1aab99*/
    }
    objc_msgSend(self->_multiLock, sel_unlock); /*0x1aabac*/
  }
}
