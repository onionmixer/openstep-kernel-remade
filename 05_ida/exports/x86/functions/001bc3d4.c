/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bc3d4. */
int __cdecl _NXAudioGetStreamParameters(id a1)
{
  id v1; // eax
  id v2; // eax

  if ( !a1 ) /*0x1bc3dc*/
    return 202; /*0x1bc420*/
  v1 = objc_msgSend(a1, sel_channel); /*0x1bc401*/
  v2 = objc_msgSend(v1, sel_audioDevice); /*0x1bc40a*/
  objc_msgSend(v2, sel__getParameters_values_count_forObject_); /*0x1bc413*/
  return 0; /*0x1bc41c*/
}
