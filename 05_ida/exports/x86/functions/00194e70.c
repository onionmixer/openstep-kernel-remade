/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x194e70. */
int __cdecl rtcget(int a1)
{
  int i; // ebx

  if ( dword_1E36A8 ) /*0x194e7f*/
  {
    outb(0x70u, 0xAu); /*0x194e85*/
    outb(0x71u, 0x26u); /*0x194e8e*/
    outb(0x70u, 0xBu); /*0x194e97*/
    outb(0x71u, 2u); /*0x194ea0*/
    dword_1E36A8 = 0; /*0x194ea8*/
  }
  outb(0x70u, 0xDu); /*0x194eb6*/
  inb(0x71u); /*0x194ebd*/
  do /*0x194edd*/
    outb(0x70u, 0xAu); /*0x194ec9*/
  while ( (inb(0x71u) & 0x80u) != 0 ); /*0x194edd*/
  for ( i = 0; i <= 13; ++i ) /*0x194edf*/
  {
    outb(0x70u, i); /*0x194ee7*/
    *(_BYTE *)(i + a1) = inb(0x71u); /*0x194ef3*/
  }
  return 0; /*0x194f04*/
}
