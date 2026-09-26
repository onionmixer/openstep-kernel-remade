/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0328. */
int __cdecl sub_1C0328(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // ecx
  int v5; // [esp-Ch] [ebp-18h]
  int v6; // [esp+8h] [ebp-4h] BYREF

  result = *(unsigned __int8 *)(a1 + 3); /*0x1c0336*/
  if ( *(_DWORD *)(a1 + 4) == 32 && result == 1 ) /*0x1c0343*/
  {
    result = 268509186; /*0x1c0350*/
    if ( *(_DWORD *)(a1 + 24) == 268509186 ) /*0x1c0358*/
    {
      v6 = 256; /*0x1c0364*/
      v5 = *(_DWORD *)(a1 + 28); /*0x1c0376*/
      v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1c037b*/
      result = _NXAudioGetDeviceParameterValues(v3, v5, a2 + 36, &v6); /*0x1c0384*/
      *(_DWORD *)(a2 + 28) = result; /*0x1c0389*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1c035a*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1c038c*/
    {
      *(_DWORD *)(a2 + 32) = 285220866; /*0x1c0398*/
      v4 = v6; /*0x1c039b*/
      *(_WORD *)(a2 + 34) = v6 & 0xFFF | *(_WORD *)(a2 + 34) & 0xF000; /*0x1c03ae*/
      result = 4 * v4 + 36; /*0x1c03b2*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1c03b9*/
      *(_DWORD *)(a2 + 4) = result; /*0x1c03bd*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1c0345*/
  }
  return result; /*0x1c03c3*/
}
