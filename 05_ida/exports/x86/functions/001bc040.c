/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bc040. */
int __cdecl _NXAudioRecordStreamData(id a1, int a2, int a3, int a4, int a5)
{
  if ( !a1 ) /*0x1bc048*/
    return 202; /*0x1bc04a*/
  if ( (unsigned __int8)objc_msgSend(a1, sel_recordSize_tag_replyTo_replyMsgs_, a2, a3, a4, a5) ) /*0x1bc06c*/
    return 0; /*0x1bc080*/
  return 204; /*0x1bc051*/
}
