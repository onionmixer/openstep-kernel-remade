/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c001c. */
int __cdecl sub_1C001C(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // [esp-10h] [ebp-14h]
  int v5; // [esp-Ch] [ebp-10h]
  int v6; // [esp-8h] [ebp-Ch]
  int v7; // [esp-4h] [ebp-8h]

  result = *(unsigned __int8 *)(a1 + 3); /*0x1c0026*/
  if ( *(_DWORD *)(a1 + 4) == 56 && !*(_BYTE *)(a1 + 3) ) /*0x1c0032*/
  {
    result = 268509186; /*0x1c0040*/
    if ( *(_DWORD *)(a1 + 24) == 268509186 /*0x1c0066*/
      && (result = 268509186, *(_DWORD *)(a1 + 32) == 268509186)
      && (result = 268509190, *(_DWORD *)(a1 + 40) == 268509190)
      && (result = 268509186, *(_DWORD *)(a1 + 48) == 268509186) )
    {
      v7 = *(_DWORD *)(a1 + 52); /*0x1c0077*/
      v6 = *(_DWORD *)(a1 + 44); /*0x1c007b*/
      v5 = *(_DWORD *)(a1 + 36); /*0x1c007f*/
      v4 = *(_DWORD *)(a1 + 28); /*0x1c0083*/
      v3 = audio_port_to_stream(*(_DWORD *)(a1 + 12)); /*0x1c0088*/
      result = _NXAudioRecordStreamData(v3, v4, v5, v6, v7); /*0x1c0091*/
      *(_DWORD *)(a2 + 28) = result; /*0x1c0096*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1c0068*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1c0099*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1c009f*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1c00a3*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1c0034*/
  }
  return result; /*0x1c00aa*/
}
