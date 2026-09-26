/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb478. */
int __cdecl _NXAudioGetBufferOptions(id a1, id *a2, id *a3)
{
  id v3; // eax
  id v4; // eax

  if ( !a1 ) /*0x1bb489*/
    return 202; /*0x1bb4d4*/
  v3 = objc_msgSend(a1, sel_audioDevice); /*0x1bb49d*/
  *a2 = objc_msgSend(v3, sel__intValueForParameter_forObject_); /*0x1bb4ab*/
  v4 = objc_msgSend(a1, sel_audioDevice); /*0x1bb4bf*/
  *a3 = objc_msgSend(v4, sel__intValueForParameter_forObject_); /*0x1bb4cd*/
  return 0; /*0x1bb4dc*/
}
