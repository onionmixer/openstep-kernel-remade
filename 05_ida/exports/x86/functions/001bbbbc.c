/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bbbbc. */
int __cdecl _NXAudioStreamInfo(id a1, int a2, int a3)
{
  if ( !a1 ) /*0x1bbbc4*/
    return 202; /*0x1bbbe4*/
  objc_msgSend(a1, sel_bytesProcessed_atTime_, a2, a3); /*0x1bbbd6*/
  return 0; /*0x1bbbdf*/
}
