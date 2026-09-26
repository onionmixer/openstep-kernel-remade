/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x187980. */
unsigned int us_spin_calibrate()
{
  int v0; // esi
  unsigned __int8 v1; // al
  unsigned __int8 v2; // bl
  unsigned __int8 v3; // al
  unsigned __int16 v4; // bx
  unsigned int result; // eax

  __outbyte(0x43u, 0x30u); /*0x187990*/
  _InterlockedIncrement(&dword_1E75C4); /*0x187991*/
  v0 = splusclock(); /*0x18799d*/
  __outbyte(0x40u, 0xFFu); /*0x1879aa*/
  _InterlockedIncrement(&dword_1E75C4); /*0x1879ab*/
  __outbyte(0x40u, 0xFFu); /*0x1879b2*/
  _InterlockedIncrement(&dword_1E75C4); /*0x1879b3*/
  us_spin(1); /*0x1879bc*/
  __outbyte(0x43u, 0); /*0x1879cb*/
  _InterlockedIncrement(&dword_1E75C4); /*0x1879cc*/
  v1 = __inbyte(0x40u); /*0x1879dc*/
  v2 = v1; /*0x1879e0*/
  v3 = __inbyte(0x40u); /*0x1879e3*/
  v4 = (v3 << 8) | v2; /*0x1879ef*/
  splx(v0); /*0x1879f3*/
  result = us_spin_us_const * (1193167 / (0xFFFF - v4)) / 0xF4240u; /*0x187a29*/
  us_spin_us_const = result; /*0x187a2d*/
  return result; /*0x187a36*/
}
