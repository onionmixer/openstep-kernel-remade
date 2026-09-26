/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x187400. */
int PMConnect()
{
  dword_1E75BC = MEMORY[0x11368]; /*0x18740a*/
  dword_1E75C0 = MEMORY[0x1136A]; /*0x187417*/
  if ( !MEMORY[0x11388] ) /*0x187424*/
    return 65536134; /*0x187448*/
  dword_1E75B8 = 1; /*0x187426*/
  sub_1871E8(); /*0x187430*/
  printf("Power management is enabled.\n"); /*0x18743a*/
  return 0; /*0x187443*/
}
