/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bc0f8. */
int __cdecl _NXAudioSetDeviceParameters(id a1, int a2)
{
  id v3; // eax
  unsigned __int8 v4; // al
  int v5; // edx

  if ( !a1 ) /*0x1bc101*/
    return 202; /*0x1bc103*/
  if ( !(unsigned __int8)objc_msgSend(a1, sel_checkOwner_, a2) ) /*0x1bc118*/
    return 200; /*0x1bc124*/
  v3 = objc_msgSend(a1, sel_audioDevice); /*0x1bc148*/
  v4 = (unsigned __int8)objc_msgSend(v3, sel__setParameters_toValues_count_forObject_); /*0x1bc151*/
  v5 = 0; /*0x1bc156*/
  if ( !v4 ) /*0x1bc15a*/
    return 210; /*0x1bc15c*/
  return v5; /*0x1bc163*/
}
