/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb63c. */
int __cdecl _NXAudioGetDevicePeakOptions(id a1, id *a2, _DWORD *a3)
{
  id v3; // eax

  if ( !a1 ) /*0x1bb64c*/
    return 202; /*0x1bb67c*/
  v3 = objc_msgSend(a1, sel_audioDevice); /*0x1bb660*/
  *a2 = objc_msgSend(v3, sel__intValueForParameter_forObject_); /*0x1bb66e*/
  *a3 = 1; /*0x1bb670*/
  return 0; /*0x1bb684*/
}
