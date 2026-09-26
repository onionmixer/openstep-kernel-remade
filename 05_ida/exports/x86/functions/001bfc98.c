/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bfc98. */
int __cdecl sub_1BFC98(int a1, int a2)
{
  int result; // eax
  id v3; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bfca2*/
  if ( *(_DWORD *)(a1 + 4) == 24 && result == 1 ) /*0x1bfcaf*/
  {
    v3 = audio_port_to_stream(*(_DWORD *)(a1 + 12)); /*0x1bfcc0*/
    result = _NXAudioRemoveStream(v3); /*0x1bfcc6*/
    *(_DWORD *)(a2 + 28) = result; /*0x1bfccb*/
    if ( !result ) /*0x1bfcd0*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bfcd2*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bfcd6*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bfcb1*/
  }
  return result; /*0x1bfcdd*/
}
