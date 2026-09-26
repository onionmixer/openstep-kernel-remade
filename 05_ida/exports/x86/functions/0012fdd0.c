/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12fdd0. */
int __cdecl sub_12FDD0(int a1)
{
  int result; // eax

  result = a1; /*0x12fdd3*/
  ++rlock_awaken_count; /*0x12fdd6*/
  if ( a1 ) /*0x12fdde*/
    return wakeup(a1); /*0x12fde1*/
  return result; /*0x12fde8*/
}
