/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf4cc. */
int __cdecl sub_1BF4CC(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // [esp-4h] [ebp-8h]

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf4d6*/
  if ( *(_DWORD *)(a1 + 4) == 32 && !*(_BYTE *)(a1 + 3) ) /*0x1bf4e2*/
  {
    result = 268509190; /*0x1bf4f0*/
    if ( *(_DWORD *)(a1 + 24) == 268509190 ) /*0x1bf4f8*/
    {
      v4 = *(_DWORD *)(a1 + 28); /*0x1bf507*/
      v3 = audio_port_to_device(*(_DWORD *)(a1 + 12)); /*0x1bf50c*/
      result = _NXAudioSetExclusiveUser(v3, v4); /*0x1bf515*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bf51a*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bf4fa*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bf51d*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bf523*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bf527*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf4e4*/
  }
  return result; /*0x1bf52e*/
}
