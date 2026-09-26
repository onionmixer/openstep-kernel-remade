/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x194f0c. */
unsigned __int8 __cdecl rtcput(int a1, unsigned __int8 a2)
{
  int i; // ebx
  char v4; // [esp+8h] [ebp-4h]

  if ( dword_1E36A8 ) /*0x194f1e*/
  {
    outb(0x70u, 0xAu); /*0x194f24*/
    outb(0x71u, 0x26u); /*0x194f2d*/
    outb(0x70u, 0xBu); /*0x194f36*/
    outb(0x71u, 2u); /*0x194f3f*/
    dword_1E36A8 = 0; /*0x194f47*/
  }
  outb(0x70u, 0xBu); /*0x194f55*/
  v4 = inb(0x71u); /*0x194f61*/
  outb(0x70u, 0xBu); /*0x194f68*/
  outb(0x71u, v4 | 0x80); /*0x194f7a*/
  for ( i = 0; i <= 9; ++i ) /*0x194f7f*/
  {
    outb(0x70u, i); /*0x194f87*/
    outb(0x71u, *(_BYTE *)(i + a1)); /*0x194f93*/
  }
  outb(0x70u, 0x32u); /*0x194fa5*/
  outb(0x71u, a2); /*0x194fb0*/
  outb(0x70u, 0xBu); /*0x194fb9*/
  return outb(0x71u, v4 & 0x7F); /*0x194fcf*/
}
