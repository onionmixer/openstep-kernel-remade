/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bba44. */
int __cdecl _NXAudioSetStreamGain(id a1)
{
  id v1; // eax
  id v2; // eax
  id v3; // eax
  id v4; // eax

  v1 = objc_msgSend(a1, sel_channel); /*0x1bba6f*/
  v2 = objc_msgSend(v1, sel_audioDevice); /*0x1bba78*/
  objc_msgSend(v2, sel__setParameter_toInt_forObject_); /*0x1bba81*/
  v3 = objc_msgSend(a1, sel_channel); /*0x1bbaa3*/
  v4 = objc_msgSend(v3, sel_audioDevice); /*0x1bbaac*/
  objc_msgSend(v4, sel__setParameter_toInt_forObject_); /*0x1bbab5*/
  return 0; /*0x1bbabf*/
}
