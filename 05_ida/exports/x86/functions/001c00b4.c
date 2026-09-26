/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c00b4. */
int __cdecl sub_1C00B4(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // eax
  int v5; // [esp+8h] [ebp-4h] BYREF

  result = *(unsigned __int8 *)(a1 + 3); /*0x1c00c2*/
  if ( *(_DWORD *)(a1 + 4) == 24 && result == 1 ) /*0x1c00cf*/
  {
    v5 = 256; /*0x1c00dc*/
    v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1c00ef*/
    result = _NXAudioGetDeviceName((int)v3, (char *)(a2 + 36), &v5); /*0x1c00f8*/
    *(_DWORD *)(a2 + 28) = result; /*0x1c00fd*/
    if ( !result ) /*0x1c0102*/
    {
      *(_DWORD *)(a2 + 32) = 285214728; /*0x1c010a*/
      v4 = v5; /*0x1c010d*/
      *(_WORD *)(a2 + 34) = v5 & 0xFFF | *(_WORD *)(a2 + 34) & 0xF000; /*0x1c0121*/
      v4 += 3; /*0x1c0125*/
      LOBYTE(v4) = v4 & 0xFC; /*0x1c0128*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1c012a*/
      result = v4 + 36; /*0x1c012e*/
      *(_DWORD *)(a2 + 4) = result; /*0x1c0131*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1c00d1*/
  }
  return result; /*0x1c0137*/
}
