/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ac85c. */
int __cdecl -[SCSIDisk writeAsyncAt:length:buffer:pending:client:](
        SCSIDisk *self,
        SEL a2,
        unsigned int a3,
        unsigned int a4,
        char *a5,
        void *a6,
        unsigned int a7)
{
  return -[SCSIDisk deviceRwCommon:block:length:buffer:client:pending:actualLength:]( /*0x1ac889*/
           self,
           sel_deviceRwCommon_block_length_buffer_client_pending_actualLength_,
           1,
           a3,
           a4,
           a5,
           a7,
           a6,
           0);
}
