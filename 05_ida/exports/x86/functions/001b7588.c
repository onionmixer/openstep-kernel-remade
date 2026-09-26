/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b7588. */
int __cdecl sub_1B7588(int a1, int a2)
{
  if ( byte_1E5380 ) /*0x1b7592*/
  {
    dword_1E5384 += dword_1E5388; /*0x1b759a*/
    if ( dword_1E538C ) /*0x1b75a7*/
      return dword_1E538C(); /*0x1b75a9*/
  }
  IOGetTimestamp(&dword_1E8710); /*0x1b75b5*/
  return IOSendInterrupt(a1, a2, 2302757); /*0x1b75ad*/
}
