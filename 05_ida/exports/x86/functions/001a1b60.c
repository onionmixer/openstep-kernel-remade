/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a1b60. */
void __cdecl sub_1A1B60(int a1, __int16 *a2)
{
  int *v2; // eax
  int v3; // ebx
  unsigned int v4; // edx
  int v5; // eax
  int v6; // ebx
  unsigned __int16 v7; // dx
  int v8; // eax
  unsigned __int16 v9; // bx
  int v10; // edx
  unsigned __int16 v11; // bx
  int v12; // edx
  unsigned __int16 v13; // bx
  int v14; // edx
  __int16 *v15; // [esp-8h] [ebp-38h]
  int v16; // [esp+Ch] [ebp-24h]
  int v17; // [esp+Ch] [ebp-24h]
  int v18; // [esp+Ch] [ebp-24h]
  unsigned __int16 *v19; // [esp+10h] [ebp-20h]
  unsigned __int16 *v20; // [esp+10h] [ebp-20h]
  unsigned __int16 *v21; // [esp+10h] [ebp-20h]
  unsigned __int16 v22[6]; // [esp+14h] [ebp-1Ch] BYREF
  unsigned __int16 v23; // [esp+20h] [ebp-10h]
  unsigned __int16 v24; // [esp+28h] [ebp-8h]
  unsigned int v25; // [esp+2Ch] [ebp-4h]

  v2 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a1b6f*/
  v3 = 0; /*0x1a1b75*/
  if ( v2 ) /*0x1a1b79*/
    v3 = *v2; /*0x1a1b7b*/
  if ( v3 ) /*0x1a1b7f*/
  {
    v4 = *(_DWORD *)(v3 + 132); /*0x1a1b81*/
    if ( v4 > 7 ) /*0x1a1b8a*/
      v5 = 0; /*0x1a1b9c*/
    else
      v5 = v3 + 132 * v4 + 136; /*0x1a1b93*/
    v6 = v5; /*0x1a1b9e*/
  }
  else
  {
    v6 = 0; /*0x1a1ba4*/
  }
  v7 = a2[28]; /*0x1a1ba9*/
  v24 = a2[30]; /*0x1a1bb1*/
  v8 = 16 * v24; /*0x1a1bba*/
  *(_DWORD *)(a1 + 116) = &loc_1A1BDC; /*0x1a1bc5*/
  v25 = __readfsdword(v7 + v8); /*0x1a1bcf*/
  *(_DWORD *)(a1 + 116) = 0; /*0x1a1bd2*/
  if ( (_WORD)v25 == 0xC4C4 ) /*0x1a1bea*/
  {
    switch ( BYTE2(v25) ) /*0x1a1bf9*/
    {
      case 0xFE: /*0x1a1bf9*/
        PCcancelTimers(v6); /*0x1a1bfc*/
        *(_DWORD *)(v6 + 88) = 4; /*0x1a1c01*/
        PCcallMonitor(a1, a2); /*0x1a1c0c*/
        break;
      case 0xFA: /*0x1a1bf9*/
        v9 = a2[34]; /*0x1a1c1f*/
        v19 = v22; /*0x1a1c26*/
        v10 = 20; /*0x1a1c29*/
        v24 = a2[36]; /*0x1a1c2e*/
        v16 = 16 * v24; /*0x1a1c3a*/
        *(_DWORD *)(a1 + 116) = &loc_1A1C70; /*0x1a1c3d*/
        do /*0x1a1c62*/
        {
          *v19++ = __readfsword(v9 + v16); /*0x1a1c52*/
          v9 += 2; /*0x1a1c5b*/
          v10 -= 2; /*0x1a1c5f*/
        }
        while ( v10 ); /*0x1a1c62*/
        *(_DWORD *)(a1 + 116) = 0; /*0x1a1c64*/
        PCbopFA(a1, (int)a2, (int)v22); /*0x1a1c81*/
        break;
      case 0xFC: /*0x1a1bf9*/
        v11 = a2[34]; /*0x1a1c97*/
        v20 = v22; /*0x1a1c9e*/
        v12 = 10; /*0x1a1ca1*/
        v23 = a2[36]; /*0x1a1ca6*/
        v17 = 16 * v23; /*0x1a1cb2*/
        *(_DWORD *)(a1 + 116) = &loc_1A1CE8; /*0x1a1cb5*/
        do /*0x1a1cda*/
        {
          *v20++ = __readfsword(v11 + v17); /*0x1a1cca*/
          v11 += 2; /*0x1a1cd3*/
          v12 -= 2; /*0x1a1cd7*/
        }
        while ( v12 ); /*0x1a1cda*/
        *(_DWORD *)(a1 + 116) = 0; /*0x1a1cdc*/
        PCbopFC(a1, (int)a2, v22); /*0x1a1cf5*/
        break;
      case 0xFD: /*0x1a1bf9*/
        v13 = a2[34]; /*0x1a1d0b*/
        v21 = v22; /*0x1a1d12*/
        v14 = 20; /*0x1a1d15*/
        v24 = a2[36]; /*0x1a1d1a*/
        v18 = 16 * v24; /*0x1a1d26*/
        *(_DWORD *)(a1 + 116) = &loc_1A1D5C; /*0x1a1d29*/
        do /*0x1a1d4e*/
        {
          *v21++ = __readfsword(v13 + v18); /*0x1a1d3e*/
          v13 += 2; /*0x1a1d47*/
          v14 -= 2; /*0x1a1d4b*/
        }
        while ( v14 ); /*0x1a1d4e*/
        *(_DWORD *)(a1 + 116) = 0; /*0x1a1d50*/
        PCbopFD(a1, (int)a2, (int)v22); /*0x1a1d71*/
        break;
      default:
        *(_DWORD *)(v6 + 76) = BYTE2(v25); /*0x1a1d7d*/
        *(_DWORD *)(v6 + 88) = 3; /*0x1a1d80*/
        PCcallMonitor(a1, v15); /*0x1a1d8c*/
        break;
    }
  }
}
