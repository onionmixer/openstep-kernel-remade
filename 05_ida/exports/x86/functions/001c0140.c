/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0140. */
int __cdecl sub_1C0140(int a1, int a2)
{
  int v2; // edi
  int result; // eax
  id v4; // eax
  int v5; // [esp-10h] [ebp-20h]
  int v6; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)(a1 + 4); /*0x1c014f*/
  result = v2 - 1064; /*0x1c0156*/
  if ( (unsigned int)(v2 - 1064) > 0x400 || *(_BYTE *)(a1 + 3) ) /*0x1c0152*/
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1c0167*/
  }
  else
  {
    result = 268509190; /*0x1c0174*/
    if ( *(_DWORD *)(a1 + 24) == 268509190 /*0x1c01b5*/
      && (result = *(_DWORD *)(a1 + 32) & 0x3000FFFF, result == 268443650)
      && (v6 = *(_WORD *)(a1 + 34) & 0xFFF, result = 4 * v6 + 1064, v2 == result)
      && (result = 285220866, *(_DWORD *)(a1 + 4 * v6 + 36) == 285220866) )
    {
      v5 = *(_DWORD *)(a1 + 28); /*0x1c01cf*/
      v4 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1c01d4*/
      result = _NXAudioSetDeviceParameters(v4, v5); /*0x1c01dd*/
      *(_DWORD *)(a2 + 28) = result; /*0x1c01e2*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1c01b7*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1c01e5*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1c01eb*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1c01ef*/
    }
  }
  return result; /*0x1c01f9*/
}
