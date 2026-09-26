/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0734. */
int __cdecl sub_1C0734(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // ecx
  int v5; // [esp-Ch] [ebp-18h]
  int v6; // [esp+8h] [ebp-4h] BYREF

  result = *(unsigned __int8 *)(a1 + 3); /*0x1c0742*/
  if ( *(_DWORD *)(a1 + 4) == 32 && result == 1 ) /*0x1c074f*/
  {
    result = 268509186; /*0x1c075c*/
    if ( *(_DWORD *)(a1 + 24) == 268509186 ) /*0x1c0764*/
    {
      v6 = 256; /*0x1c0770*/
      v5 = *(_DWORD *)(a1 + 28); /*0x1c0782*/
      v3 = audio_port_to_stream(*(_DWORD *)(a1 + 12)); /*0x1c0787*/
      result = _NXAudioGetStreamParameterValues(v3, v5, a2 + 36, &v6); /*0x1c0790*/
      *(_DWORD *)(a2 + 28) = result; /*0x1c0795*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1c0766*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1c0798*/
    {
      *(_DWORD *)(a2 + 32) = 285220866; /*0x1c07a4*/
      v4 = v6; /*0x1c07a7*/
      *(_WORD *)(a2 + 34) = v6 & 0xFFF | *(_WORD *)(a2 + 34) & 0xF000; /*0x1c07ba*/
      result = 4 * v4 + 36; /*0x1c07be*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1c07c5*/
      *(_DWORD *)(a2 + 4) = result; /*0x1c07c9*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1c0751*/
  }
  return result; /*0x1c07cf*/
}
