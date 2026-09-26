/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c03cc. */
int __cdecl sub_1C03CC(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // ecx
  int v5; // [esp+8h] [ebp-4h] BYREF

  result = *(unsigned __int8 *)(a1 + 3); /*0x1c03da*/
  if ( *(_DWORD *)(a1 + 4) == 24 && result == 1 ) /*0x1c03e7*/
  {
    v5 = 256; /*0x1c03f4*/
    v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1c0413*/
    result = _NXAudioGetSamplingRates(v3, (_DWORD *)(a2 + 36), a2 + 44, a2 + 52, a2 + 60, &v5); /*0x1c041c*/
    *(_DWORD *)(a2 + 28) = result; /*0x1c0421*/
    if ( !result ) /*0x1c0426*/
    {
      *(_DWORD *)(a2 + 32) = 268509186; /*0x1c042e*/
      *(_DWORD *)(a2 + 40) = 268509186; /*0x1c0437*/
      *(_DWORD *)(a2 + 48) = 268509186; /*0x1c0440*/
      *(_DWORD *)(a2 + 56) = 285220866; /*0x1c0449*/
      v4 = v5; /*0x1c044c*/
      *(_WORD *)(a2 + 58) = v5 & 0xFFF | *(_WORD *)(a2 + 58) & 0xF000; /*0x1c045f*/
      result = 4 * v4 + 60; /*0x1c0463*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1c046a*/
      *(_DWORD *)(a2 + 4) = result; /*0x1c046e*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1c03e9*/
  }
  return result; /*0x1c0474*/
}
