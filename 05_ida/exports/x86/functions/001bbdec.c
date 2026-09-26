/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bbdec. */
int __cdecl _NXAudioGetStreamPeak(id a1, int a2, int a3)
{
  id v4; // eax
  id v5; // eax

  if ( !a1 ) /*0x1bbdf5*/
    return 202; /*0x1bbdf7*/
  v4 = objc_msgSend(a1, sel_channel); /*0x1bbe1c*/
  v5 = objc_msgSend(v4, sel_audioDevice); /*0x1bbe25*/
  if ( !objc_msgSend(v5, sel__intValueForParameter_forObject_) ) /*0x1bbe2e*/
    return 208; /*0x1bbe54*/
  objc_msgSend(a1, sel_getPeakLeft_right_, a2, a3); /*0x1bbe4a*/
  return 0; /*0x1bbe59*/
}
