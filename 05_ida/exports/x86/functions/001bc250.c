/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bc250. */
int __cdecl _NXAudioGetSamplingRates(id a1, _DWORD *a2, int a3, int a4, int a5, _DWORD *a6)
{
  id v6; // eax
  id v7; // eax
  id v8; // eax

  *a6 = 0; /*0x1bc25f*/
  if ( !a1 ) /*0x1bc267*/
    return 202; /*0x1bc2d8*/
  v6 = objc_msgSend(a1, sel_audioDevice); /*0x1bc278*/
  *a2 = (char)objc_msgSend(v6, sel_acceptsContinuousSamplingRates); /*0x1bc289*/
  v7 = objc_msgSend(a1, sel_audioDevice); /*0x1bc2a2*/
  objc_msgSend(v7, sel_getSamplingRatesLow_high_); /*0x1bc2ab*/
  v8 = objc_msgSend(a1, sel_audioDevice); /*0x1bc2c4*/
  objc_msgSend(v8, sel_getSamplingRates_count_); /*0x1bc2cd*/
  return 0; /*0x1bc2e0*/
}
