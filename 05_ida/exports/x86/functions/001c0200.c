/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0200. */
int __cdecl sub_1C0200(int a1, int a2)
{
  int v2; // esi
  int result; // eax
  id v4; // eax

  v2 = *(_DWORD *)(a1 + 4); /*0x1c020c*/
  result = v2 - 28; /*0x1c0213*/
  if ( (unsigned int)(v2 - 28) <= 0x400 && *(_BYTE *)(a1 + 3) == 1 ) /*0x1c0220*/
  {
    result = *(_DWORD *)(a1 + 24) & 0x3000FFFF; /*0x1c022f*/
    if ( result == 268443650 && (result = 4 * (*(_WORD *)(a1 + 26) & 0xFFF) + 28, v2 == result) ) /*0x1c024e*/
    {
      v4 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1c0269*/
      result = _NXAudioGetDeviceParameters(v4); /*0x1c0272*/
      *(_DWORD *)(a2 + 28) = result; /*0x1c0277*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1c0250*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1c027a*/
    {
      *(_DWORD *)(a2 + 32) = 285220866; /*0x1c0286*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1c0289*/
      *(_DWORD *)(a2 + 4) = 1060; /*0x1c028d*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1c0222*/
  }
  return result; /*0x1c0297*/
}
