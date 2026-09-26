/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf8f8. */
int __cdecl sub_1BF8F8(int a1, int a2)
{
  int result; // eax
  id v3; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf902*/
  if ( *(_DWORD *)(a1 + 4) == 24 && result == 1 ) /*0x1bf90f*/
  {
    v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1bf924*/
    result = _NXAudioGetSndoutOptions(v3, (_DWORD *)(a2 + 36)); /*0x1bf92d*/
    *(_DWORD *)(a2 + 28) = result; /*0x1bf932*/
    if ( !result ) /*0x1bf937*/
    {
      *(_DWORD *)(a2 + 32) = 268509186; /*0x1bf93f*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1bf942*/
      *(_DWORD *)(a2 + 4) = 40; /*0x1bf946*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf911*/
  }
  return result; /*0x1bf94d*/
}
