/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c06ac. */
int __cdecl sub_1C06AC(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // ecx
  int v5; // [esp+8h] [ebp-4h] BYREF

  result = *(unsigned __int8 *)(a1 + 3); /*0x1c06ba*/
  if ( *(_DWORD *)(a1 + 4) == 24 && result == 1 ) /*0x1c06c7*/
  {
    v5 = 256; /*0x1c06d4*/
    v3 = audio_port_to_stream(*(_DWORD *)(a1 + 12)); /*0x1c06e7*/
    result = _NXAudioGetStreamSupportedParameters(v3, a2 + 36, &v5); /*0x1c06f0*/
    *(_DWORD *)(a2 + 28) = result; /*0x1c06f5*/
    if ( !result ) /*0x1c06fa*/
    {
      *(_DWORD *)(a2 + 32) = 285220866; /*0x1c0702*/
      v4 = v5; /*0x1c0705*/
      *(_WORD *)(a2 + 34) = v5 & 0xFFF | *(_WORD *)(a2 + 34) & 0xF000; /*0x1c0718*/
      result = 4 * v4 + 36; /*0x1c071c*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1c0723*/
      *(_DWORD *)(a2 + 4) = result; /*0x1c0727*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1c06c9*/
  }
  return result; /*0x1c072d*/
}
