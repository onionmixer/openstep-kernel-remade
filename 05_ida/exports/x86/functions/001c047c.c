/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c047c. */
int __cdecl sub_1C047C(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // ecx
  int v5; // [esp+8h] [ebp-4h] BYREF

  result = *(unsigned __int8 *)(a1 + 3); /*0x1c048a*/
  if ( *(_DWORD *)(a1 + 4) == 24 && result == 1 ) /*0x1c0497*/
  {
    v5 = 256; /*0x1c04a4*/
    v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1c04b7*/
    result = _NXAudioGetDataEncodings(v3, a2 + 36, &v5); /*0x1c04c0*/
    *(_DWORD *)(a2 + 28) = result; /*0x1c04c5*/
    if ( !result ) /*0x1c04ca*/
    {
      *(_DWORD *)(a2 + 32) = 285220866; /*0x1c04d2*/
      v4 = v5; /*0x1c04d5*/
      *(_WORD *)(a2 + 34) = v5 & 0xFFF | *(_WORD *)(a2 + 34) & 0xF000; /*0x1c04e8*/
      result = 4 * v4 + 36; /*0x1c04ec*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1c04f3*/
      *(_DWORD *)(a2 + 4) = result; /*0x1c04f7*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1c0499*/
  }
  return result; /*0x1c04fd*/
}
