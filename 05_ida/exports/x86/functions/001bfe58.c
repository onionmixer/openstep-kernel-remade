/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bfe58. */
int __cdecl sub_1BFE58(int a1, int a2)
{
  int result; // eax
  id v3; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bfe62*/
  if ( *(_DWORD *)(a1 + 4) == 24 && result == 1 ) /*0x1bfe6f*/
  {
    v3 = audio_port_to_stream(*(_DWORD *)(a1 + 12)); /*0x1bfe88*/
    result = _NXAudioGetStreamPeak(v3, a2 + 36, a2 + 44); /*0x1bfe91*/
    *(_DWORD *)(a2 + 28) = result; /*0x1bfe96*/
    if ( !result ) /*0x1bfe9b*/
    {
      *(_DWORD *)(a2 + 32) = 268509186; /*0x1bfea3*/
      *(_DWORD *)(a2 + 40) = 268509186; /*0x1bfeac*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1bfeaf*/
      *(_DWORD *)(a2 + 4) = 48; /*0x1bfeb3*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bfe71*/
  }
  return result; /*0x1bfeba*/
}
