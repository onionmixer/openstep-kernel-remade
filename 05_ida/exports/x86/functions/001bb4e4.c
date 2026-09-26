/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb4e4. */
int __cdecl _NXAudioSetBufferOptions(id a1, int a2)
{
  id v3; // eax
  id v4; // eax

  if ( !a1 ) /*0x1bb4ed*/
    return 202; /*0x1bb4ef*/
  if ( !(unsigned __int8)objc_msgSend(a1, sel_checkOwner_, a2) ) /*0x1bb504*/
    return 200; /*0x1bb55c*/
  v3 = objc_msgSend(a1, sel_audioDevice); /*0x1bb526*/
  objc_msgSend(v3, sel__setParameter_toInt_forObject_); /*0x1bb52f*/
  v4 = objc_msgSend(a1, sel_audioDevice); /*0x1bb54a*/
  objc_msgSend(v4, sel__setParameter_toInt_forObject_); /*0x1bb553*/
  return 0; /*0x1bb561*/
}
