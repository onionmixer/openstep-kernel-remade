/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf538. */
int __cdecl sub_1BF538(int a1, int a2)
{
  int result; // eax
  id v3; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf542*/
  if ( *(_DWORD *)(a1 + 4) == 24 && result == 1 ) /*0x1bf54f*/
  {
    v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1bf568*/
    result = _NXAudioGetBufferOptions(v3, (id *)(a2 + 36), (id *)(a2 + 44)); /*0x1bf571*/
    *(_DWORD *)(a2 + 28) = result; /*0x1bf576*/
    if ( !result ) /*0x1bf57b*/
    {
      *(_DWORD *)(a2 + 32) = 268509186; /*0x1bf583*/
      *(_DWORD *)(a2 + 40) = 268509186; /*0x1bf58c*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1bf58f*/
      *(_DWORD *)(a2 + 4) = 48; /*0x1bf593*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf551*/
  }
  return result; /*0x1bf59a*/
}
