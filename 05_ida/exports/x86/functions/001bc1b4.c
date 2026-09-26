/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bc1b4. */
int __cdecl _NXAudioGetDeviceSupportedParameters(id a1, int a2, _DWORD *a3)
{
  id v3; // eax

  *a3 = 0; /*0x1bc1bd*/
  if ( !a1 ) /*0x1bc1c5*/
    return 202; /*0x1bc1f0*/
  v3 = objc_msgSend(a1, sel_audioDevice); /*0x1bc1dc*/
  objc_msgSend(v3, sel__getSupportedParameters_count_forObject_); /*0x1bc1e5*/
  return 0; /*0x1bc1ee*/
}
