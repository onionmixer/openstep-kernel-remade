/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb9c0. */
int __cdecl _NXAudioSetSpeaker(id a1, int a2)
{
  id v3; // eax
  id v4; // eax

  if ( !a1 ) /*0x1bb9c9*/
    return 202; /*0x1bb9cb*/
  if ( !(unsigned __int8)objc_msgSend(a1, sel_checkOwner_, a2) ) /*0x1bb9e0*/
    return 200; /*0x1bba38*/
  v3 = objc_msgSend(a1, sel_audioDevice); /*0x1bba02*/
  objc_msgSend(v3, sel__setParameter_toInt_forObject_); /*0x1bba0b*/
  v4 = objc_msgSend(a1, sel_audioDevice); /*0x1bba26*/
  objc_msgSend(v4, sel__setParameter_toInt_forObject_); /*0x1bba2f*/
  return 0; /*0x1bba3d*/
}
