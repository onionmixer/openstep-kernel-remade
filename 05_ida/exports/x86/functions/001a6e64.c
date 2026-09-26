/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a6e64. */
int __cdecl -[IODiskPartition readAsyncAt:length:buffer:pending:client:](
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
    v9.receiver = self; /*0x1a6eb3*/
    v9.super_class = (Class)stru_1FA154.super_class; /*0x1a6ebc*/
    return -[IOLogicalDisk readAsyncAt:length:buffer:pending:client:]( /*0x1a6ec3*/
             &v9,
             sel_readAsyncAt_length_buffer_pending_client_,
             a3,
             a4,
             a5,
             a6,
             a7);
  }
  else
  {
    v7 = -[IODevice name](self, sel_name); /*0x1a6e7e*/
    IOLog((int)"%s: Read attempt with no valid label\n", v7);
    return -706; /*0x1a6e8e*/
  }
}
