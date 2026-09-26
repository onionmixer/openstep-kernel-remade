/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c060c. */
int __cdecl sub_1C060C(int a1, int a2)
{
  int v2; // esi
  int result; // eax
  id v4; // eax

  v2 = *(_DWORD *)(a1 + 4); /*0x1c0618*/
  result = v2 - 28; /*0x1c061f*/
  if ( (unsigned int)(v2 - 28) <= 0x400 && *(_BYTE *)(a1 + 3) == 1 ) /*0x1c062c*/
  {
    result = *(_DWORD *)(a1 + 24) & 0x3000FFFF; /*0x1c063b*/
    if ( result == 268443650 && (result = 4 * (*(_WORD *)(a1 + 26) & 0xFFF) + 28, v2 == result) ) /*0x1c065a*/
    {
      v4 = audio_port_to_stream(*(_DWORD *)(a1 + 12)); /*0x1c0675*/
      result = _NXAudioGetStreamParameters(v4); /*0x1c067e*/
      *(_DWORD *)(a2 + 28) = result; /*0x1c0683*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1c065c*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1c0686*/
    {
      *(_DWORD *)(a2 + 32) = 285220866; /*0x1c0692*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1c0695*/
      *(_DWORD *)(a2 + 4) = 1060; /*0x1c0699*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1c062e*/
  }
  return result; /*0x1c06a3*/
}
