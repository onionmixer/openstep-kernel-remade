/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb68c. */
int __cdecl _NXAudioSetDevicePeakOptions(id a1, int a2)
{
  id v3; // eax

  if ( !a1 ) /*0x1bb695*/
    return 202; /*0x1bb697*/
  if ( !(unsigned __int8)objc_msgSend(a1, sel_checkOwner_, a2) ) /*0x1bb6ac*/
    return 200; /*0x1bb6ec*/
  v3 = objc_msgSend(a1, sel_audioDevice); /*0x1bb6d7*/
  objc_msgSend(v3, sel__setParameter_toInt_forObject_); /*0x1bb6e0*/
  return 0; /*0x1bb6f1*/
}
