/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf9d0. */
int __cdecl sub_1BF9D0(int a1, int a2)
{
  int result; // eax
  id v3; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf9da*/
  if ( *(_DWORD *)(a1 + 4) == 24 && result == 1 ) /*0x1bf9e7*/
  {
    v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1bfa00*/
    result = _NXAudioGetSpeaker(v3, (id *)(a2 + 36), (id *)(a2 + 44)); /*0x1bfa09*/
    *(_DWORD *)(a2 + 28) = result; /*0x1bfa0e*/
    if ( !result ) /*0x1bfa13*/
    {
      *(_DWORD *)(a2 + 32) = 268509186; /*0x1bfa1b*/
      *(_DWORD *)(a2 + 40) = 268509186; /*0x1bfa24*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1bfa27*/
      *(_DWORD *)(a2 + 4) = 48; /*0x1bfa2b*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf9e9*/
  }
  return result; /*0x1bfa32*/
}
