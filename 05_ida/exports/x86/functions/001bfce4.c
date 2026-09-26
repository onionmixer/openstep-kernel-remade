/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bfce4. */
int __cdecl sub_1BFCE4(int a1, int a2)
{
  int result; // eax
  id v3; // eax
  int v4; // [esp-2Ch] [ebp-30h]
  int v5; // [esp-28h] [ebp-2Ch]
  int v6; // [esp-24h] [ebp-28h]
  int v7; // [esp-20h] [ebp-24h]
  int v8; // [esp-1Ch] [ebp-20h]
  int v9; // [esp-18h] [ebp-1Ch]
  int v10; // [esp-14h] [ebp-18h]
  int v11; // [esp-10h] [ebp-14h]
  int v12; // [esp-Ch] [ebp-10h]
  int v13; // [esp-8h] [ebp-Ch]
  int v14; // [esp-4h] [ebp-8h]

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bfcee*/
  if ( *(_DWORD *)(a1 + 4) == 112 && !*(_BYTE *)(a1 + 3) ) /*0x1bfcfa*/
  {
    result = *(_BYTE *)(a1 + 27) & 0x30; /*0x1bfd0b*/
    if ( (_BYTE)result != 32 ) /*0x1bfd0f*/
      goto LABEL_15; /*0x1bfd0f*/
    if ( *(_DWORD *)(a1 + 28) != 524297 ) /*0x1bfd18*/
      goto LABEL_15; /*0x1bfd18*/
    result = 268509186; /*0x1bfd1a*/
    if ( *(_DWORD *)(a1 + 40) != 268509186 ) /*0x1bfd22*/
      goto LABEL_15; /*0x1bfd22*/
    result = 268509186; /*0x1bfd24*/
    if ( *(_DWORD *)(a1 + 48) != 268509186 ) /*0x1bfd2c*/
      goto LABEL_15; /*0x1bfd2c*/
    result = 268509186; /*0x1bfd2e*/
    if ( *(_DWORD *)(a1 + 56) == 268509186 /*0x1bfd72*/
      && (result = 268509186, *(_DWORD *)(a1 + 64) == 268509186)
      && (result = 268509186, *(_DWORD *)(a1 + 72) == 268509186)
      && (result = 268509186, *(_DWORD *)(a1 + 80) == 268509186)
      && (result = 268509186, *(_DWORD *)(a1 + 88) == 268509186)
      && (result = 268509190, *(_DWORD *)(a1 + 96) == 268509190)
      && (result = 268509186, *(_DWORD *)(a1 + 104) == 268509186) )
    {
      v14 = *(_DWORD *)(a1 + 108); /*0x1bfd83*/
      v13 = *(_DWORD *)(a1 + 100); /*0x1bfd87*/
      v12 = *(_DWORD *)(a1 + 92); /*0x1bfd8b*/
      v11 = *(_DWORD *)(a1 + 84); /*0x1bfd8f*/
      v10 = *(_DWORD *)(a1 + 76); /*0x1bfd93*/
      v9 = *(_DWORD *)(a1 + 68); /*0x1bfd97*/
      v8 = *(_DWORD *)(a1 + 60); /*0x1bfd9b*/
      v7 = *(_DWORD *)(a1 + 52); /*0x1bfd9f*/
      v6 = *(_DWORD *)(a1 + 44); /*0x1bfda3*/
      v5 = *(_DWORD *)(a1 + 32); /*0x1bfda7*/
      v4 = *(_DWORD *)(a1 + 36); /*0x1bfdab*/
      v3 = audio_port_to_stream(*(_DWORD *)(a1 + 12)); /*0x1bfdb0*/
      result = _NXAudioPlayStream(v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14); /*0x1bfdb9*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bfdbe*/
    }
    else
    {
LABEL_15:
      *(_DWORD *)(a2 + 28) = -304; /*0x1bfd74*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bfdc1*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bfdc7*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bfdcb*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bfcfc*/
  }
  return result; /*0x1bfdd2*/
}
