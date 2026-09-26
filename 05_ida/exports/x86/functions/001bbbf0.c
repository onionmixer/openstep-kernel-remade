/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bbbf0. */
int __cdecl _NXAudioRemoveStream(id a1)
{
  id v1; // eax

  if ( !a1 ) /*0x1bbbf8*/
    return 202; /*0x1bbc20*/
  v1 = objc_msgSend(a1, sel_channel); /*0x1bbc0a*/
  objc_msgSend(v1, sel_removeStream_); /*0x1bbc13*/
  return 0; /*0x1bbc1c*/
}
