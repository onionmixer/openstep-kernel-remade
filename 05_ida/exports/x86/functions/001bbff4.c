/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bbff4. */
int __cdecl _NXAudioPlayStreamData(id a1, int a2, int a3, int a4, int a5, int a6)
{
  if ( !a1 ) /*0x1bbffc*/
    return 202; /*0x1bbffe*/
  if ( (unsigned __int8)objc_msgSend(a1, sel_playBuffer_size_tag_replyTo_replyMsgs_, a2, a3, a4, a5, a6) ) /*0x1bc024*/
    return 0; /*0x1bc038*/
  return 204; /*0x1bc005*/
}
