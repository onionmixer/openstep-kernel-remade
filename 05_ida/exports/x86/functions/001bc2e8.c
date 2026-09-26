/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bc2e8. */
int __cdecl _NXAudioGetDataEncodings(id a1, int a2, _DWORD *a3)
{
  id v3; // eax

  *a3 = 0; /*0x1bc2f1*/
  if ( !a1 ) /*0x1bc2f9*/
    return 202; /*0x1bc324*/
  v3 = objc_msgSend(a1, sel_audioDevice); /*0x1bc30f*/
  objc_msgSend(v3, sel_getDataEncodings_count_); /*0x1bc318*/
  return 0; /*0x1bc321*/
}
