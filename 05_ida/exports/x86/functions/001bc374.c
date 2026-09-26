/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bc374. */
int __cdecl _NXAudioSetStreamParameters(id a1)
{
  id v2; // eax
  id v3; // eax
  unsigned __int8 v4; // al
  int v5; // edx

  if ( !a1 ) /*0x1bc37c*/
    return 202; /*0x1bc37e*/
  v2 = objc_msgSend(a1, sel_channel); /*0x1bc3ab*/
  v3 = objc_msgSend(v2, sel_audioDevice); /*0x1bc3b4*/
  v4 = (unsigned __int8)objc_msgSend(v3, sel__setParameters_toValues_count_forObject_); /*0x1bc3bd*/
  v5 = 0; /*0x1bc3c2*/
  if ( !v4 ) /*0x1bc3c6*/
    return 210; /*0x1bc3c8*/
  return v5; /*0x1bc385*/
}
