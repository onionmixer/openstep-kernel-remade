/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x119b5c. */
int __cdecl vfs_putnum(int a1, int a2)
{
  int result; // eax

  if ( a2 >= 0 ) /*0x119b68*/
  {
    *(_BYTE *)((a2 >> 3) + a1) &= __ROL4__(-2, a2 - 8 * (a2 >> 3)); /*0x119b7f*/
    return a2 >> 3; /*0x119b6c*/
  }
  return result; /*0x119b82*/
}
