/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf5a4. */
int __cdecl sub_1BF5A4(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // [esp-Ch] [ebp-10h]

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf5ae*/
  if ( *(_DWORD *)(a1 + 4) == 48 && !*(_BYTE *)(a1 + 3) ) /*0x1bf5ba*/
  {
    result = 268509190; /*0x1bf5c8*/
    if ( *(_DWORD *)(a1 + 24) == 268509190 /*0x1bf5e4*/
      && (result = 268509186, *(_DWORD *)(a1 + 32) == 268509186)
      && (result = 268509186, *(_DWORD *)(a1 + 40) == 268509186) )
    {
      v4 = *(_DWORD *)(a1 + 28); /*0x1bf5fb*/
      v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1bf600*/
      result = _NXAudioSetBufferOptions(v3, v4); /*0x1bf609*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bf60e*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bf5e6*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bf611*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bf617*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bf61b*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf5bc*/
  }
  return result; /*0x1bf622*/
}
