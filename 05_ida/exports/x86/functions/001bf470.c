/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf470. */
int __cdecl sub_1BF470(int a1, int a2)
{
  int result; // eax
  id v3; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf47a*/
  if ( *(_DWORD *)(a1 + 4) == 24 && result == 1 ) /*0x1bf487*/
  {
    v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1bf49c*/
    result = _NXAudioGetExclusiveUser(v3, (id *)(a2 + 36)); /*0x1bf4a5*/
    *(_DWORD *)(a2 + 28) = result; /*0x1bf4aa*/
    if ( !result ) /*0x1bf4af*/
    {
      *(_DWORD *)(a2 + 32) = 268509190; /*0x1bf4b7*/
      *(_BYTE *)(a2 + 3) = 0; /*0x1bf4ba*/
      *(_DWORD *)(a2 + 4) = 40; /*0x1bf4be*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf489*/
  }
  return result; /*0x1bf4c5*/
}
