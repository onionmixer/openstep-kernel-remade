/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0504. */
int __cdecl sub_1C0504(int a1, int a2)
{
  int result; // eax
  id v3; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1c050e*/
  if ( *(_DWORD *)(a1 + 4) == 24 && result == 1 ) /*0x1c051b*/
  {
    v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1c0530*/
    result = _NXAudioGetChannelCountLimit(v3, (id *)(a2 + 36)); /*0x1c0539*/
    *(_DWORD *)(a2 + 28) = result; /*0x1c053e*/
    if ( !result ) /*0x1c0543*/
    {
      *(_DWORD *)(a2 + 32) = 268509186; /*0x1c054b*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1c054e*/
      *(_DWORD *)(a2 + 4) = 40; /*0x1c0552*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1c051d*/
  }
  return result; /*0x1c0559*/
}
