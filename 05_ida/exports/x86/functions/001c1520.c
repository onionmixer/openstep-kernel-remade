/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c1520. */
int __cdecl -[IOEISADeviceDescription setChannelList:num:](
        IOEISADeviceDescription *self,
        SEL a2,
        unsigned int *a3,
        unsigned int a4)
{
  int v4; // ebx
  id v5; // eax
  int *eisa_private; // ebx
  int v7; // eax

  v4 = -702; /*0x1c1528*/
  v5 = -[IOEISADeviceDescription _delegate](self, sel__delegate); /*0x1c1549*/
  if ( objc_msgSend(v5, sel_allocateItems_numItems_forKey_) ) /*0x1c1552*/
  {
    eisa_private = (int *)self->_eisa_private; /*0x1c155e*/
    v7 = eisa_private[1]; /*0x1c1561*/
    if ( v7 ) /*0x1c1566*/
      IOFree(*eisa_private, 4 * v7); /*0x1c156f*/
    eisa_private[1] = 0; /*0x1c1574*/
    return 0; /*0x1c157b*/
  }
  return v4; /*0x1c1582*/
}
