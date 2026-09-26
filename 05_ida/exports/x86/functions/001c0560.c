/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0560. */
int __cdecl sub_1C0560(int a1, int a2)
{
  int v2; // edi
  int result; // eax
  int v4; // esi
  id v5; // eax

  v2 = *(_DWORD *)(a1 + 4); /*0x1c056c*/
  result = v2 - 1056; /*0x1c0573*/
  if ( (unsigned int)(v2 - 1056) <= 0x400 && *(_BYTE *)(a1 + 3) == 1 ) /*0x1c0583*/
  {
    result = *(_DWORD *)(a1 + 24) & 0x3000FFFF; /*0x1c0593*/
    if ( result == 268443650 /*0x1c05c4*/
      && (v4 = *(_WORD *)(a1 + 26) & 0xFFF, result = 4 * v4 + 1056, v2 == result)
      && (result = 285220866, *(_DWORD *)(a1 + 4 * v4 + 28) == 285220866) )
    {
      v5 = audio_port_to_stream(*(_DWORD *)(a1 + 12)); /*0x1c05dd*/
      result = _NXAudioSetStreamParameters(v5); /*0x1c05e6*/
      *(_DWORD *)(a2 + 28) = result; /*0x1c05eb*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1c05c6*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1c05ee*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1c05f4*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1c05f8*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1c0585*/
  }
  return result; /*0x1c0602*/
}
