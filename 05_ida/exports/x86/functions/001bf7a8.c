/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf7a8. */
int __cdecl sub_1BF7A8(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // [esp-Ch] [ebp-10h]

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf7b2*/
  if ( *(_DWORD *)(a1 + 4) == 48 && !*(_BYTE *)(a1 + 3) ) /*0x1bf7be*/
  {
    result = 268509190; /*0x1bf7cc*/
    if ( *(_DWORD *)(a1 + 24) == 268509190 /*0x1bf7e8*/
      && (result = 268509186, *(_DWORD *)(a1 + 32) == 268509186)
      && (result = 268509186, *(_DWORD *)(a1 + 40) == 268509186) )
    {
      v4 = *(_DWORD *)(a1 + 28); /*0x1bf7ff*/
      v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1bf804*/
      result = _NXAudioSetDevicePeakOptions(v3, v4); /*0x1bf80d*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bf812*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bf7ea*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bf815*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bf81b*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bf81f*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf7c0*/
  }
  return result; /*0x1bf826*/
}
