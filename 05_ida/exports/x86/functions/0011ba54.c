/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11ba54. */
int __cdecl vno_ioctl(_DWORD *a1, int a2, int *a3)
{
  int v3; // eax
  int v5; // [esp+4h] [ebp-4Ch]
  int v6; // [esp+8h] [ebp-48h]
  int v7; // [esp+Ch] [ebp-44h]
  _BYTE v8[24]; // [esp+10h] [ebp-40h] BYREF
  int v9; // [esp+28h] [ebp-28h]

  v7 = 0; /*0x11ba5b*/
  v5 = a1[6]; /*0x11ba68*/
  switch ( *(_DWORD *)(v5 + 40) ) /*0x11ba7b*/
  {
    case 1: /*0x11ba7b*/
      if ( a2 != -1073453462 ) /*0x11baaf*/
        goto LABEL_16; /*0x11baaf*/
      v6 = a1[2] & 0x1000; /*0x11babd*/
      v3 = *a3; /*0x11bac3*/
      if ( *a3 == 1 ) /*0x11bac8*/
      {
        a1[2] |= 0x1000u; /*0x11badc*/
      }
      else if ( *a3 > 1 ) /*0x11baca*/
      {
        if ( v3 != 2 ) /*0x11bad7*/
          return 22; /*0x11bad7*/
        a1[2] &= ~0x1000u; /*0x11bae8*/
      }
      else if ( v3 ) /*0x11bace*/
      {
        return 22; /*0x11baf9*/
      }
      if ( v6 ) /*0x11bb04*/
        *a3 = 1; /*0x11bb09*/
      else
        *a3 = 2; /*0x11bb17*/
      return 0;
    case 2: /*0x11ba7b*/
    case 8: /*0x11ba7b*/
LABEL_16:
      if ( a2 < -2147195267 ) /*0x11bb2c*/
        return 25; /*0x11bb2c*/
      if ( a2 <= -2147195266 ) /*0x11bb37*/
        return v7; /*0x11bb37*/
      if ( a2 != 1074030207 ) /*0x11bb42*/
        return 25; /*0x11bb42*/
      v7 = (*(int (__stdcall **)(int, _BYTE *, _DWORD))(*(_DWORD *)(v5 + 28) + 20))(v5, v8, *(_DWORD *)(active_u + 28)); /*0x11bb61*/
      if ( !v7 ) /*0x11bb66*/
        *a3 = v9 - a1[7]; /*0x11bb78*/
      return v7; /*0x11bb7a*/
    case 4: /*0x11ba7b*/
    case 9: /*0x11ba7b*/
      *(_DWORD *)(dword_1E875C + 96) = 0; /*0x11bb85*/
      if ( !setjmp((int *)(dword_1E875C + 40)) ) /*0x11bb95*/
        return (*(int (__stdcall **)(int, int, int *, _DWORD, _DWORD))(*(_DWORD *)(v5 + 28) + 12))( /*0x11bbf6*/
                 v5,
                 a2,
                 a3,
                 a1[2],
                 a1[8]);
      if ( ((*(int *)(active_u + 320) >> (*(_BYTE *)(*(_DWORD *)active_u + 23) - 1)) & 1) != 0 ) /*0x11bbba*/
        return 4; /*0x11bbbc*/
      *(_BYTE *)(dword_1E875C + 105) = 2; /*0x11bbcd*/
      return v7; /*0x11bbc3*/
    default:
      return 25; /*0x11bc03*/
  }
}
