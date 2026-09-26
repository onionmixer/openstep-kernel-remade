/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bfac4. */
int __cdecl sub_1BFAC4(int a1, int a2)
{
  int result; // eax
  id v3; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bface*/
  if ( *(_DWORD *)(a1 + 4) == 40 && result == 1 ) /*0x1bfadb*/
  {
    result = 268509186; /*0x1bfae8*/
    if ( *(_DWORD *)(a1 + 24) == 268509186 && (result = 268509186, *(_DWORD *)(a1 + 32) == 268509186) ) /*0x1bfafa*/
    {
      v3 = audio_port_to_stream(*(_DWORD *)(a1 + 12)); /*0x1bfb14*/
      result = _NXAudioSetStreamGain(v3); /*0x1bfb1d*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bfb22*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bfafc*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bfb25*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bfb2b*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bfb2f*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bfadd*/
  }
  return result; /*0x1bfb36*/
}
