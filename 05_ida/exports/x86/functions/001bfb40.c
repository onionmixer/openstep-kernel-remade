/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bfb40. */
int __cdecl sub_1BFB40(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // [esp-4h] [ebp-8h]

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bfb4a*/
  if ( *(_DWORD *)(a1 + 4) == 32 && !*(_BYTE *)(a1 + 3) ) /*0x1bfb56*/
  {
    result = 268509190; /*0x1bfb64*/
    if ( *(_DWORD *)(a1 + 24) == 268509190 ) /*0x1bfb6c*/
    {
      v4 = *(_DWORD *)(a1 + 28); /*0x1bfb7b*/
      v3 = audio_port_to_stream(*(_DWORD *)(a1 + 12)); /*0x1bfb80*/
      result = _NXAudioChangeStreamOwner(v3, v4); /*0x1bfb89*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bfb8e*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bfb6e*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bfb91*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bfb97*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bfb9b*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bfb58*/
  }
  return result; /*0x1bfba2*/
}
