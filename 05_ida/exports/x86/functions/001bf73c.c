/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf73c. */
int __cdecl sub_1BF73C(int a1, int a2)
{
  int result; // eax
  id v3; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf746*/
  if ( *(_DWORD *)(a1 + 4) == 24 && result == 1 ) /*0x1bf753*/
  {
    v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1bf76c*/
    result = _NXAudioGetDevicePeakOptions(v3, (id *)(a2 + 36), (_DWORD *)(a2 + 44)); /*0x1bf775*/
    *(_DWORD *)(a2 + 28) = result; /*0x1bf77a*/
    if ( !result ) /*0x1bf77f*/
    {
      *(_DWORD *)(a2 + 32) = 268509186; /*0x1bf787*/
      *(_DWORD *)(a2 + 40) = 268509186; /*0x1bf790*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1bf793*/
      *(_DWORD *)(a2 + 4) = 48; /*0x1bf797*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf755*/
  }
  return result; /*0x1bf79e*/
}
