/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bc330. */
int __cdecl _NXAudioGetChannelCountLimit(id a1, id *a2)
{
  id v2; // eax

  *a2 = nullptr; /*0x1bc33a*/
  if ( !a1 ) /*0x1bc342*/
    return 202; /*0x1bc368*/
  v2 = objc_msgSend(a1, sel_audioDevice); /*0x1bc353*/
  *a2 = objc_msgSend(v2, sel_channelCountLimit); /*0x1bc361*/
  return 0; /*0x1bc36d*/
}
