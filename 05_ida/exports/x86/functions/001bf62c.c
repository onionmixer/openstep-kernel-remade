/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf62c. */
int __cdecl sub_1BF62C(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // [esp-8h] [ebp-Ch]
  unsigned int v5; // [esp-4h] [ebp-8h]

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf636*/
  if ( *(_DWORD *)(a1 + 4) == 40 && !*(_BYTE *)(a1 + 3) ) /*0x1bf642*/
  {
    result = 268509190; /*0x1bf650*/
    if ( *(_DWORD *)(a1 + 24) == 268509190 && (result = 268509186, *(_DWORD *)(a1 + 32) == 268509186) ) /*0x1bf662*/
    {
      v5 = *(_DWORD *)(a1 + 36); /*0x1bf673*/
      v4 = *(_DWORD *)(a1 + 28); /*0x1bf677*/
      v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1bf67c*/
      result = _NXAudioControlStreams(v3, v4, v5); /*0x1bf685*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bf68a*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bf664*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bf68d*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bf693*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bf697*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf644*/
  }
  return result; /*0x1bf69e*/
}
