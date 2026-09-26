/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bbd90. */
int __cdecl _NXAudioSetStreamPeakOptions(id a1)
{
  id v1; // eax
  id v2; // eax

  if ( !a1 ) /*0x1bbd98*/
    return 202; /*0x1bbde0*/
  v1 = objc_msgSend(a1, sel_channel); /*0x1bbdc3*/
  v2 = objc_msgSend(v1, sel_audioDevice); /*0x1bbdcc*/
  objc_msgSend(v2, sel__setParameter_toInt_forObject_); /*0x1bbdd5*/
  return 0; /*0x1bbdde*/
}
