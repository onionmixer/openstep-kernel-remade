/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bfddc. */
int __cdecl sub_1BFDDC(int a1, int a2)
{
  int result; // eax
  id v3; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bfde6*/
  if ( *(_DWORD *)(a1 + 4) == 40 && result == 1 ) /*0x1bfdf3*/
  {
    result = 268509186; /*0x1bfe00*/
    if ( *(_DWORD *)(a1 + 24) == 268509186 && (result = 268509186, *(_DWORD *)(a1 + 32) == 268509186) ) /*0x1bfe12*/
    {
      v3 = audio_port_to_stream(*(_DWORD *)(a1 + 12)); /*0x1bfe2c*/
      result = _NXAudioSetStreamPeakOptions(v3); /*0x1bfe35*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bfe3a*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bfe14*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bfe3d*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bfe43*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bfe47*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bfdf5*/
  }
  return result; /*0x1bfe4e*/
}
