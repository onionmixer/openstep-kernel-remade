/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bbac8. */
int __cdecl _NXAudioChangeStreamOwner(id a1, int a2)
{
  if ( !a1 || !a2 ) /*0x1bbad7*/
    return 202; /*0x1bbad9*/
  objc_msgSend(a1, sel_setOwner_, a2); /*0x1bbaed*/
  return 0; /*0x1bbae0*/
}
