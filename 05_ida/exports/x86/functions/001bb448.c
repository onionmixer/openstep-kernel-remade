/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb448. */
int __cdecl _NXAudioSetExclusiveUser(id a1, int a2)
{
  if ( !a1 ) /*0x1bb450*/
    return 202; /*0x1bb46c*/
  objc_msgSend(a1, sel_setExclusiveUser_, a2); /*0x1bb45e*/
  return 0; /*0x1bb467*/
}
