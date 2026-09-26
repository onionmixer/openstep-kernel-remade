/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb418. */
int __cdecl _NXAudioGetExclusiveUser(id a1, id *a2)
{
  if ( !a1 ) /*0x1bb424*/
    return 202; /*0x1bb43c*/
  *a2 = objc_msgSend(a1, sel_exclusiveUser); /*0x1bb433*/
  return 0; /*0x1bb441*/
}
