/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bfbac. */
int __cdecl sub_1BFBAC(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // [esp-Ch] [ebp-10h]
  int v5; // [esp-8h] [ebp-Ch]
  int v6; // [esp-4h] [ebp-8h]

  result = a1; /*0x1bfbb0*/
  if ( *(_DWORD *)(a1 + 4) == 44 && *(_BYTE *)(a1 + 3) == 1 ) /*0x1bfbc3*/
  {
    if ( *(_DWORD *)(a1 + 24) == 268509186 && *(_DWORD *)(a1 + 32) == 268574722 ) /*0x1bfbe4*/
    {
      v6 = *(_DWORD *)(a1 + 40); /*0x1bfbf3*/
      v5 = *(_DWORD *)(a1 + 36); /*0x1bfbf7*/
      v4 = *(_DWORD *)(a1 + 28); /*0x1bfbfb*/
      v3 = audio_port_to_stream(*(_DWORD *)(a1 + 12)); /*0x1bfc00*/
      result = _NXAudioStreamControl(v3, v4, v5, v6); /*0x1bfc09*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bfc0e*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bfbe6*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bfc11*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bfc17*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bfc1b*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bfbc5*/
  }
  return result; /*0x1bfc22*/
}
