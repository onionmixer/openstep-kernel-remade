/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb844. */
int __cdecl _NXAudioSetSndoutOptions(id a1, int a2, char a3)
{
  id v4; // eax
  void *v5; // ebx

  if ( !a1 ) /*0x1bb852*/
    return 202; /*0x1bb854*/
  if ( !(unsigned __int8)objc_msgSend(a1, sel_checkOwner_, a2) ) /*0x1bb86c*/
    return 200; /*0x1bb878*/
  v4 = objc_msgSend(a1, sel_audioDevice); /*0x1bb88c*/
  v5 = v4; /*0x1bb891*/
  if ( (a3 & 1) != 0 ) /*0x1bb89c*/
    objc_msgSend(v4, sel__setParameter_toInt_forObject_, 5, 1, a1); /*0x1bb8a1*/
  else
    objc_msgSend(v4, sel__setParameter_toInt_forObject_, 5, 0, a1); /*0x1bb8b1*/
  if ( (a3 & 2) != 0 ) /*0x1bb8bf*/
    objc_msgSend(v5, sel__setParameter_toInt_forObject_, 3, 1, a1); /*0x1bb8c4*/
  else
    objc_msgSend(v5, sel__setParameter_toInt_forObject_, 3, 0, a1); /*0x1bb8d5*/
  if ( (a3 & 4) != 0 ) /*0x1bb8e3*/
    objc_msgSend(v5, sel__setParameter_toInt_forObject_, 4, 1, a1); /*0x1bb8e8*/
  else
    objc_msgSend(v5, sel__setParameter_toInt_forObject_, 4, 0, a1); /*0x1bb8f9*/
  if ( (a3 & 8) != 0 ) /*0x1bb907*/
    objc_msgSend(v5, sel__setParameter_toInt_forObject_, 6, 1, a1); /*0x1bb90c*/
  else
    objc_msgSend(v5, sel__setParameter_toInt_forObject_, 6, 0, a1); /*0x1bb91d*/
  if ( (a3 & 0x10) != 0 ) /*0x1bb92b*/
    objc_msgSend(v5, sel__setParameter_toInt_forObject_, 7, 0, a1); /*0x1bb930*/
  else
    objc_msgSend(v5, sel__setParameter_toInt_forObject_, 7, 1, a1); /*0x1bb941*/
  return 0; /*0x1bb94b*/
}
