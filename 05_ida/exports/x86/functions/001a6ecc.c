/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a6ecc. */
int __cdecl -[IODiskPartition writeAt:length:buffer:actualLength:client:](
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
    v9.receiver = self; /*0x1a6f1b*/
    v9.super_class = (Class)stru_1FA154.super_class; /*0x1a6f24*/
    return -[IOLogicalDisk writeAt:length:buffer:actualLength:client:]( /*0x1a6f2b*/
             &v9,
             sel_writeAt_length_buffer_actualLength_client_,
             a3,
             a4,
             a5,
             a6,
             a7);
  }
  else
  {
    v7 = -[IODevice name](self, sel_name); /*0x1a6ee6*/
    IOLog((int)"%s: Write attempt with no valid label\n", v7);
    return -706; /*0x1a6ef6*/
  }
}
