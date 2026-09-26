/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf830. */
int __cdecl sub_1BF830(int a1, int a2)
{
  int result; // eax
  id v3; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf83a*/
  if ( *(_DWORD *)(a1 + 4) == 24 && result == 1 ) /*0x1bf847*/
  {
    v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1bf860*/
    result = _NXAudioGetDevicePeak(v3, a2 + 36, a2 + 44); /*0x1bf869*/
    *(_DWORD *)(a2 + 28) = result; /*0x1bf86e*/
    if ( !result ) /*0x1bf873*/
    {
      *(_DWORD *)(a2 + 32) = 268509186; /*0x1bf87b*/
      *(_DWORD *)(a2 + 40) = 268509186; /*0x1bf884*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1bf887*/
      *(_DWORD *)(a2 + 4) = 48; /*0x1bf88b*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf849*/
  }
  return result; /*0x1bf892*/
}
