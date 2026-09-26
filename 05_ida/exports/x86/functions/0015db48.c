/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15db48. */
int mach_net_init()
{
  int *v0; // eax
  int v2; // [esp+0h] [ebp-4h] BYREF

  listener_zone = zinit(20, 2000, 20, 0, aNetListenerZon); /*0x15db63*/
  dword_1E5BAC = 17; /*0x15db68*/
  dword_1E5BB0 = 2028; /*0x15db72*/
  dword_1E5BB4 = 0; /*0x15db7c*/
  dword_1E5BB8 = 0; /*0x15db86*/
  dword_1E5BC0 = 1959; /*0x15db90*/
  v0 = (int *)&listeners; /*0x15db9a*/
  if ( &listeners < (_UNKNOWN *)&mach_net_kmsg_zone ) /*0x15dba7*/
  {
    do /*0x15dbba*/
    {
      *v0 = 0; /*0x15dbac*/
      v0 += 2; /*0x15dbb2*/
    }
    while ( v0 < &mach_net_kmsg_zone ); /*0x15dbba*/
  }
  mach_net_kmsg_zone = zinit(2048, 0x2000, 2048, 0, aMachNetMessage); /*0x15dbd7*/
  zchange(mach_net_kmsg_zone, 0, 0, 0, 0); /*0x15dbe5*/
  kmem_alloc_wired(kernel_map, &v2, 0x2000); /*0x15dbfd*/
  return zcram(mach_net_kmsg_zone, v2, 0x2000); /*0x15dc17*/
}
