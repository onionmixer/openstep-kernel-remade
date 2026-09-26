/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb6f8. */
int __cdecl _NXAudioGetDevicePeak(id a1, int a2, int a3)
{
  id v4; // eax

  if ( !a1 ) /*0x1bb701*/
    return 202; /*0x1bb703*/
  v4 = objc_msgSend(a1, sel_audioDevice); /*0x1bb71e*/
  if ( !objc_msgSend(v4, sel__intValueForParameter_forObject_) ) /*0x1bb727*/
    return 208; /*0x1bb74c*/
  objc_msgSend(a1, sel_getPeakLeft_right_, a2, a3); /*0x1bb743*/
  return 0; /*0x1bb751*/
}
