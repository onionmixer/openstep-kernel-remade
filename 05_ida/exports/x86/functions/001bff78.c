/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bff78. */
int __cdecl sub_1BFF78(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // [esp-14h] [ebp-18h]
  int v5; // [esp-10h] [ebp-14h]
  int v6; // [esp-Ch] [ebp-10h]
  int v7; // [esp-8h] [ebp-Ch]
  int v8; // [esp-4h] [ebp-8h]

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bff82*/
  if ( *(_DWORD *)(a1 + 4) == 64 && !*(_BYTE *)(a1 + 3) ) /*0x1bff8e*/
  {
    result = *(_BYTE *)(a1 + 27) & 0x30; /*0x1bff9f*/
    if ( (_BYTE)result == 32 /*0x1bffca*/
      && *(_DWORD *)(a1 + 28) == 524297
      && (result = 268509186, *(_DWORD *)(a1 + 40) == 268509186)
      && (result = 268509190, *(_DWORD *)(a1 + 48) == 268509190)
      && (result = 268509186, *(_DWORD *)(a1 + 56) == 268509186) )
    {
      v8 = *(_DWORD *)(a1 + 60); /*0x1bffdb*/
      v7 = *(_DWORD *)(a1 + 52); /*0x1bffdf*/
      v6 = *(_DWORD *)(a1 + 44); /*0x1bffe3*/
      v5 = *(_DWORD *)(a1 + 32); /*0x1bffe7*/
      v4 = *(_DWORD *)(a1 + 36); /*0x1bffeb*/
      v3 = audio_port_to_stream(*(_DWORD *)(a1 + 12)); /*0x1bfff0*/
      result = _NXAudioPlayStreamData(v3, v4, v5, v6, v7, v8); /*0x1bfff9*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bfffe*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bffcc*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1c0001*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1c0007*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1c000b*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bff90*/
  }
  return result; /*0x1c0012*/
}
