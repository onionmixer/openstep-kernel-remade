/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12bc2c. */
unsigned __int32 igmp_init()
{
  unsigned __int32 result; // eax

  result = _byteswap_ulong(0xE0000001); /*0x12bc34*/
  dword_1E59AC = result; /*0x12bc36*/
  return result; /*0x12bc3d*/
}
