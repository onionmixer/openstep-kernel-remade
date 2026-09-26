/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb758. */
int __cdecl _NXAudioGetClipCount(id a1, id *a2)
{
  if ( !a1 ) /*0x1bb764*/
    return 202; /*0x1bb77c*/
  *a2 = objc_msgSend(a1, sel_clipCount); /*0x1bb773*/
  return 0; /*0x1bb781*/
}
