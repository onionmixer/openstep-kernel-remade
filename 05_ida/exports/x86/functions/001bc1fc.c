/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bc1fc. */
int __cdecl _NXAudioGetDeviceParameterValues(id a1, int a2, int a3, _DWORD *a4)
{
  id v5; // eax
  unsigned __int8 v6; // al
  int v7; // edx

  *a4 = 0; /*0x1bc205*/
  if ( !a1 ) /*0x1bc20d*/
    return 202; /*0x1bc20f*/
  v5 = objc_msgSend(a1, sel_audioDevice); /*0x1bc231*/
  v6 = (unsigned __int8)objc_msgSend(v5, sel__getValues_count_forParameter_forObject_); /*0x1bc23a*/
  v7 = 0; /*0x1bc23f*/
  if ( !v6 ) /*0x1bc243*/
    return 210; /*0x1bc245*/
  return v7; /*0x1bc216*/
}
