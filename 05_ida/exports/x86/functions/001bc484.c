/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bc484. */
int __cdecl _NXAudioGetStreamParameterValues(id a1, int a2, int a3, _DWORD *a4)
{
  id v5; // eax
  id v6; // eax
  unsigned __int8 v7; // al
  int v8; // edx

  *a4 = 0; /*0x1bc48d*/
  if ( !a1 ) /*0x1bc495*/
    return 202; /*0x1bc497*/
  v5 = objc_msgSend(a1, sel_channel); /*0x1bc4c0*/
  v6 = objc_msgSend(v5, sel_audioDevice); /*0x1bc4c9*/
  v7 = (unsigned __int8)objc_msgSend(v6, sel__getValues_count_forParameter_forObject_); /*0x1bc4d2*/
  v8 = 0; /*0x1bc4d7*/
  if ( !v7 ) /*0x1bc4db*/
    return 210; /*0x1bc4dd*/
  return v8; /*0x1bc49e*/
}
