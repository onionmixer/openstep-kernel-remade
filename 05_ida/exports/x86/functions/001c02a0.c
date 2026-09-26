/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c02a0. */
int __cdecl sub_1C02A0(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // ecx
  int v5; // [esp+8h] [ebp-4h] BYREF

  result = *(unsigned __int8 *)(a1 + 3); /*0x1c02ae*/
  if ( *(_DWORD *)(a1 + 4) == 24 && result == 1 ) /*0x1c02bb*/
  {
    v5 = 256; /*0x1c02c8*/
    v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1c02db*/
    result = _NXAudioGetDeviceSupportedParameters(v3, a2 + 36, &v5); /*0x1c02e4*/
    *(_DWORD *)(a2 + 28) = result; /*0x1c02e9*/
    if ( !result ) /*0x1c02ee*/
    {
      *(_DWORD *)(a2 + 32) = 285220866; /*0x1c02f6*/
      v4 = v5; /*0x1c02f9*/
      *(_WORD *)(a2 + 34) = v5 & 0xFFF | *(_WORD *)(a2 + 34) & 0xF000; /*0x1c030c*/
      result = 4 * v4 + 36; /*0x1c0310*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1c0317*/
      *(_DWORD *)(a2 + 4) = result; /*0x1c031b*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1c02bd*/
  }
  return result; /*0x1c0321*/
}
