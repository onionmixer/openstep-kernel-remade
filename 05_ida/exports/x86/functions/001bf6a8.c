/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf6a8. */
int __cdecl sub_1BF6A8(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // [esp-Ch] [ebp-10h]
  int v5; // [esp-8h] [ebp-Ch]
  int v6; // [esp-4h] [ebp-8h]

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf6b2*/
  if ( *(_DWORD *)(a1 + 4) == 48 && !*(_BYTE *)(a1 + 3) ) /*0x1bf6be*/
  {
    result = 268509190; /*0x1bf6cc*/
    if ( *(_DWORD *)(a1 + 24) == 268509190 /*0x1bf6e8*/
      && (result = 268509186, *(_DWORD *)(a1 + 32) == 268509186)
      && (result = 268509186, *(_DWORD *)(a1 + 40) == 268509186) )
    {
      v6 = *(_DWORD *)(a1 + 44); /*0x1bf6f7*/
      v5 = *(_DWORD *)(a1 + 36); /*0x1bf6fb*/
      v4 = *(_DWORD *)(a1 + 28); /*0x1bf6ff*/
      v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1bf708*/
      result = _NXAudioAddStream(v3, a2 + 36, v4, v5, v6); /*0x1bf711*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bf716*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bf6ea*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bf719*/
    {
      *(_DWORD *)(a2 + 32) = 268509190; /*0x1bf725*/
      *(_BYTE *)(a2 + 3) = 0; /*0x1bf728*/
      *(_DWORD *)(a2 + 4) = 40; /*0x1bf72c*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf6c0*/
  }
  return result; /*0x1bf733*/
}
