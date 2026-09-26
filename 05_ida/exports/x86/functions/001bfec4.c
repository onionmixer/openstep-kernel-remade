/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bfec4. */
int __cdecl sub_1BFEC4(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // [esp-18h] [ebp-1Ch]
  int v5; // [esp-14h] [ebp-18h]
  int v6; // [esp-10h] [ebp-14h]
  int v7; // [esp-Ch] [ebp-10h]
  int v8; // [esp-8h] [ebp-Ch]
  int v9; // [esp-4h] [ebp-8h]

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bfece*/
  if ( *(_DWORD *)(a1 + 4) == 72 && !*(_BYTE *)(a1 + 3) ) /*0x1bfeda*/
  {
    result = 268509186; /*0x1bfee8*/
    if ( *(_DWORD *)(a1 + 24) == 268509186 /*0x1bff22*/
      && (result = 268509186, *(_DWORD *)(a1 + 32) == 268509186)
      && (result = 268509186, *(_DWORD *)(a1 + 40) == 268509186)
      && (result = 268509186, *(_DWORD *)(a1 + 48) == 268509186)
      && (result = 268509190, *(_DWORD *)(a1 + 56) == 268509190)
      && (result = 268509186, *(_DWORD *)(a1 + 64) == 268509186) )
    {
      v9 = *(_DWORD *)(a1 + 68); /*0x1bff33*/
      v8 = *(_DWORD *)(a1 + 60); /*0x1bff37*/
      v7 = *(_DWORD *)(a1 + 52); /*0x1bff3b*/
      v6 = *(_DWORD *)(a1 + 44); /*0x1bff3f*/
      v5 = *(_DWORD *)(a1 + 36); /*0x1bff43*/
      v4 = *(_DWORD *)(a1 + 28); /*0x1bff47*/
      v3 = audio_port_to_stream(*(_DWORD *)(a1 + 12)); /*0x1bff4c*/
      result = _NXAudioRecordStream(v3, v4, v5, v6, v7, v8, v9); /*0x1bff55*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bff5a*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bff24*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bff5d*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bff63*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bff67*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bfedc*/
  }
  return result; /*0x1bff6e*/
}
