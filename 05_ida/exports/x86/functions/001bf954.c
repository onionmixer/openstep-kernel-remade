/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf954. */
int __cdecl sub_1BF954(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // [esp-8h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-8h]

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf95e*/
  if ( *(_DWORD *)(a1 + 4) == 40 && !*(_BYTE *)(a1 + 3) ) /*0x1bf96a*/
  {
    result = 268509190; /*0x1bf978*/
    if ( *(_DWORD *)(a1 + 24) == 268509190 && (result = 268509186, *(_DWORD *)(a1 + 32) == 268509186) ) /*0x1bf98a*/
    {
      v5 = *(_DWORD *)(a1 + 36); /*0x1bf99b*/
      v4 = *(_DWORD *)(a1 + 28); /*0x1bf99f*/
      v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1bf9a4*/
      result = _NXAudioSetSndoutOptions(v3, v4, v5); /*0x1bf9ad*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bf9b2*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bf98c*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bf9b5*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bf9bb*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bf9bf*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf96c*/
  }
  return result; /*0x1bf9c6*/
}
