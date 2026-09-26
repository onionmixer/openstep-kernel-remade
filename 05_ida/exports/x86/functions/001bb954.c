/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb954. */
int __cdecl _NXAudioGetSpeaker(id a1, id *a2, id *a3)
{
  id v3; // eax
  id v4; // eax

  if ( !a1 ) /*0x1bb965*/
    return 202; /*0x1bb9b0*/
  v3 = objc_msgSend(a1, sel_audioDevice); /*0x1bb979*/
  *a2 = objc_msgSend(v3, sel__intValueForParameter_forObject_); /*0x1bb987*/
  v4 = objc_msgSend(a1, sel_audioDevice); /*0x1bb99b*/
  *a3 = objc_msgSend(v4, sel__intValueForParameter_forObject_); /*0x1bb9a9*/
  return 0; /*0x1bb9b8*/
}
