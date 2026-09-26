/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bfc2c. */
int __cdecl sub_1BFC2C(int a1, int a2)
{
  int result; // eax
  id v3; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bfc36*/
  if ( *(_DWORD *)(a1 + 4) == 24 && result == 1 ) /*0x1bfc43*/
  {
    v3 = audio_port_to_stream(*(_DWORD *)(a1 + 12)); /*0x1bfc5c*/
    result = _NXAudioStreamInfo(v3, a2 + 36, a2 + 44); /*0x1bfc65*/
    *(_DWORD *)(a2 + 28) = result; /*0x1bfc6a*/
    if ( !result ) /*0x1bfc6f*/
    {
      *(_DWORD *)(a2 + 32) = 268509186; /*0x1bfc77*/
      *(_DWORD *)(a2 + 40) = 268509186; /*0x1bfc80*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1bfc83*/
      *(_DWORD *)(a2 + 4) = 48; /*0x1bfc87*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bfc45*/
  }
  return result; /*0x1bfc8e*/
}
