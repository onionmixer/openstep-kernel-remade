/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a6f34. */
int __cdecl -[IODiskPartition writeAsyncAt:length:buffer:pending:client:](
        IODiskPartition *self,
        SEL a2,
        unsigned int a3,
        unsigned int a4,
        char *a5,
        void *a6,
        unsigned int a7)
{
  const char *v7; // eax
  objc_super v9; // [esp+0h] [ebp-8h] BYREF

  if ( self->_labelValid )
  {
    v9.receiver = self; /*0x1a6f83*/
    v9.super_class = (Class)stru_1FA154.super_class; /*0x1a6f8c*/
    return -[IOLogicalDisk writeAsyncAt:length:buffer:pending:client:]( /*0x1a6f93*/
             &v9,
             sel_writeAsyncAt_length_buffer_pending_client_,
             a3,
             a4,
             a5,
             a6,
             a7);
  }
  else
  {
    v7 = -[IODevice name](self, sel_name); /*0x1a6f4e*/
    IOLog((int)"%s: Write attempt with no valid label\n", v7);
    return -706; /*0x1a6f5e*/
  }
}
