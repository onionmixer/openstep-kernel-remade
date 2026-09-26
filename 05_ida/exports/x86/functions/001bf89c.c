/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf89c. */
int __cdecl sub_1BF89C(int a1, int a2)
{
  int result; // eax
  id v3; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf8a6*/
  if ( *(_DWORD *)(a1 + 4) == 24 && result == 1 ) /*0x1bf8b3*/
  {
    v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1bf8c8*/
    result = _NXAudioGetClipCount(v3, (id *)(a2 + 36)); /*0x1bf8d1*/
    *(_DWORD *)(a2 + 28) = result; /*0x1bf8d6*/
    if ( !result ) /*0x1bf8db*/
    {
      *(_DWORD *)(a2 + 32) = 268509186; /*0x1bf8e3*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1bf8e6*/
      *(_DWORD *)(a2 + 4) = 40; /*0x1bf8ea*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf8b5*/
  }
  return result; /*0x1bf8f1*/
}
