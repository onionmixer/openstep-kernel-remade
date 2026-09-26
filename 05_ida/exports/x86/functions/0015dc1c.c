/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15dc1c. */
int __cdecl netipc_msg_release(int a1)
{
  return zfree(mach_net_kmsg_zone, a1); /*0x15dc30*/
}
