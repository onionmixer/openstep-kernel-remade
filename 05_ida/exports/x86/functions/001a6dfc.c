/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a6dfc. */
int __cdecl -[IODiskPartition readAt:length:buffer:actualLength:client:](
        IODiskPartition *self,
        SEL a2,
        unsigned int a3,
        unsigned int a4,
        char *a5,
        unsigned int *a6,
        unsigned int a7)
{
  const char *v7; // eax
  objc_super v9; // [esp+0h] [ebp-8h] BYREF

  if ( self->_labelValid )
  {
    v9.receiver = self; /*0x1a6e4b*/
    v9.super_class = (Class)stru_1FA154.super_class; /*0x1a6e54*/
    return -[IOLogicalDisk readAt:length:buffer:actualLength:client:]( /*0x1a6e5b*/
             &v9,
             sel_readAt_length_buffer_actualLength_client_,
             a3,
             a4,
             a5,
             a6,
             a7);
  }
  else
  {
    v7 = -[IODevice name](self, sel_name); /*0x1a6e16*/
    IOLog((int)"%s: Read attempt with no valid label\n", v7);
    return -706; /*0x1a6e26*/
  }
}
