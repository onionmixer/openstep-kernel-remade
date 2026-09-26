/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a0d90. */
unsigned __int8 keyboard_reboot()
{
  if ( dword_1E4B78 ) /*0x1a0d9a*/
    dword_1E4B78(); /*0x1a0d9c*/
  while ( (inb(0x64u) & 2) != 0 ) /*0x1a0dac*/
    ; /*0x1a0da0*/
  return outb(0x64u, 0xFEu); /*0x1a0dbc*/
}
