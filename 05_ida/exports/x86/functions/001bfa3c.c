/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bfa3c. */
int __cdecl sub_1BFA3C(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // [esp-Ch] [ebp-10h]

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bfa46*/
  if ( *(_DWORD *)(a1 + 4) == 48 && !*(_BYTE *)(a1 + 3) ) /*0x1bfa52*/
  {
    result = 268509190; /*0x1bfa60*/
    if ( *(_DWORD *)(a1 + 24) == 268509190 /*0x1bfa7c*/
      && (result = 268509186, *(_DWORD *)(a1 + 32) == 268509186)
      && (result = 268509186, *(_DWORD *)(a1 + 40) == 268509186) )
    {
      v4 = *(_DWORD *)(a1 + 28); /*0x1bfa93*/
      v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1bfa98*/
      result = _NXAudioSetSpeaker(v3, v4); /*0x1bfaa1*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bfaa6*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bfa7e*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bfaa9*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bfaaf*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bfab3*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bfa54*/
  }
  return result; /*0x1bfaba*/
}
