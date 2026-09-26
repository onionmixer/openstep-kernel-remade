/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a469c. */
char __cdecl +[IODevice removeFromCdevsw](id a1, SEL a2)
{
  id v2; // eax

  v2 = objc_msgSend(a1, sel_characterMajor); /*0x1a46ab*/
  if ( v2 == (id)-1 ) /*0x1a46b6*/
    return 0; /*0x1a46d4*/
  IORemoveFromCdevsw(v2); /*0x1a46b9*/
  objc_msgSend(a1, sel_setCharacterMajor_, -1); /*0x1a46c8*/
  return 1; /*0x1a46d6*/
}
