/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ac7cc. */
int __cdecl -[SCSIDisk readAt:length:buffer:actualLength:client:](
        SCSIDisk *self,
        SEL a2,
        unsigned int a3,
        unsigned int a4,
        char *a5,
        unsigned int *a6,
        unsigned int a7)
{
  return -[SCSIDisk deviceRwCommon:block:length:buffer:client:pending:actualLength:]( /*0x1ac7f9*/
           self,
           sel_deviceRwCommon_block_length_buffer_client_pending_actualLength_,
           0,
           a3,
           a4,
           a5,
           a7,
           0,
           a6);
}
