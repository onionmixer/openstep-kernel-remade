/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a7fd4. */
int __cdecl -[IODeviceDescription setInterruptList:num:](
        IODeviceDescription *self,
        SEL a2,
        unsigned int *a3,
        unsigned int a4)
{
  int v4; // ebx
  id v5; // eax
  int *v6; // ebx
  int v7; // eax

  v4 = -702; /*0x1a7fdc*/
  v5 = -[IODeviceDescription _delegate](self, sel__delegate); /*0x1a7ffd*/
  if ( objc_msgSend(v5, sel_allocateItems_numItems_forKey_) ) /*0x1a8006*/
  {
    v6 = (int *)self->_private; /*0x1a8012*/
    v7 = v6[1]; /*0x1a8015*/
    if ( v7 ) /*0x1a801a*/
      IOFree(*v6, 4 * v7); /*0x1a8023*/
    v6[1] = 0; /*0x1a8028*/
    return 0; /*0x1a802f*/
  }
  return v4; /*0x1a8036*/
}
