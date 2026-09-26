/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aa550. */
char __cdecl -[IOEthernet isUnwantedMulticastPacket:](IOEthernet *self, SEL a2, $BAB958AC952E8DB6BD4A54AF207A7289 *a3)
{
  int v3; // eax
  $3D9F9298DBF9489C64856F2E59AA9D10 *v4; // ebx

  if ( (a3->var0[0] & 1) == 0 || self->_promiscEnabled ) /*0x1aa562*/
    return 0; /*0x1aa562*/
  v3 = 0; /*0x1aa56b*/
  while ( a3->var0[v3] == 0xFF ) /*0x1aa574*/
  {
    if ( ++v3 > 5 ) /*0x1aa57a*/
      return 0; /*0x1aa57a*/
  }
  objc_msgSend(self->_multiLock, sel_lock); /*0x1aa58e*/
  v4 = -[IOEthernet searchMulti:](self, sel_searchMulti_, a3); /*0x1aa5a1*/
  objc_msgSend(self->_multiLock, sel_unlock); /*0x1aa5b1*/
  return !v4; /*0x1aa5c4*/
}
