/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5f74. */
int __cdecl -[IOLogicalDisk writeAsyncAt:length:buffer:pending:client:](
        IOLogicalDisk *self,
        SEL a2,
        unsigned int a3,
        unsigned int a4,
        char *a5,
        void *a6,
        unsigned int a7)
{
  int result; // eax
  int v8; // [esp+4h] [ebp-8h] BYREF
  int v9; // [esp+8h] [ebp-4h] BYREF

  if ( -[IODisk isWriteProtected](self, sel_isWriteProtected) ) /*0x1a5f86*/
    return -719; /*0x1a5f92*/
  result = -[IOLogicalDisk _diskParamCommon:length:deviceOffset:bytesToMove:]( /*0x1a5fb4*/
             self,
             sel__diskParamCommon_length_deviceOffset_bytesToMove_,
             a3,
             a4,
             &v9,
             &v8);
  if ( !result ) /*0x1a5fbe*/
    return (int)objc_msgSend(self->_physicalDisk, sel_writeAsyncAt_length_buffer_pending_client_, v9, v8, a5, a6, a7); /*0x1a5fe2*/
  return result; /*0x1a5fe7*/
}
