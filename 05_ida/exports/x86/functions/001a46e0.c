/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a46e0. */
char __cdecl +[IODevice removeFromBdevsw](id a1, SEL a2)
{
  id v2; // eax

  v2 = objc_msgSend(a1, sel_blockMajor); /*0x1a46ef*/
  if ( v2 == (id)-1 ) /*0x1a46fa*/
    return 0; /*0x1a4718*/
  IORemoveFromBdevsw(v2); /*0x1a46fd*/
  objc_msgSend(a1, sel_setBlockMajor_, -1); /*0x1a470c*/
  return 1; /*0x1a471a*/
}
