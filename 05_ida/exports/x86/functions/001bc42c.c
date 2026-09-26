/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bc42c. */
int __cdecl _NXAudioGetStreamSupportedParameters(id a1, int a2, _DWORD *a3)
{
  id v3; // eax
  id v4; // eax

  *a3 = 0; /*0x1bc435*/
  if ( !a1 ) /*0x1bc43d*/
    return 202; /*0x1bc478*/
  v3 = objc_msgSend(a1, sel_channel); /*0x1bc45b*/
  v4 = objc_msgSend(v3, sel_audioDevice); /*0x1bc464*/
  objc_msgSend(v4, sel__getSupportedParameters_count_forObject_); /*0x1bc46d*/
  return 0; /*0x1bc476*/
}
