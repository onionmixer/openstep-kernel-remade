/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bc16c. */
int __cdecl _NXAudioGetDeviceParameters(id a1)
{
  id v1; // eax

  if ( !a1 ) /*0x1bc174*/
    return 202; /*0x1bc1a8*/
  v1 = objc_msgSend(a1, sel_audioDevice); /*0x1bc192*/
  objc_msgSend(v1, sel__getParameters_values_count_forObject_); /*0x1bc19b*/
  return 0; /*0x1bc1a4*/
}
