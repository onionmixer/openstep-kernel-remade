/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15d8d0. */
int __cdecl netipc_msg_send(int a1)
{
  if ( *(_DWORD *)(a1 + 40) != 1959 ) /*0x15d8dd*/
    return 0; /*0x15d8f0*/
  sub_15D6B8(a1); /*0x15d8e0*/
  return 1; /*0x15d8ec*/
}
