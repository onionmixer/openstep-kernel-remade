/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13cc20. */
int __cdecl ialloccg(int a1, int a2, int a3, __int16 a4)
{
  int v4; // ebx
  int *v5; // eax
  _DWORD *v6; // edi
  int v7; // eax
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // ecx
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // [esp+10h] [ebp-14h]
  int v23; // [esp+14h] [ebp-10h]
  int v24; // [esp+18h] [ebp-Ch]
  int v25; // [esp+1Ch] [ebp-8h] BYREF

  v4 = *(_DWORD *)(a1 + 80); /*0x13cc2f*/
  if ( !*(_DWORD *)(*(_DWORD *)(v4 + 4 * (a2 >> *(_DWORD *)(v4 + 112)) + 728) + 16 * (a2 & ~*(_DWORD *)(v4 + 108)) + 8) ) /*0x13cc4c*/
    return 0; /*0x13cc4c*/
  v5 = bread( /*0x13cc85*/
         *(_DWORD *)(a1 + 64),
         (*(_DWORD *)(v4 + 12) + *(_DWORD *)(v4 + 188) * a2 + *(_DWORD *)(v4 + 24) * (a2 & ~*(_DWORD *)(v4 + 28))) << *(_DWORD *)(v4 + 100),
         *(_DWORD *)(v4 + 160));
  v24 = (int)v5; /*0x13cc8a*/
  v6 = (_DWORD *)v5[8]; /*0x13cc8d*/
  if ( (*(_BYTE *)v5 & 4) != 0 ) /*0x13cc96*/
  {
    brelse((int)v5); /*0x13cc99*/
    v7 = 0; /*0x13cc9e*/
  }
  else
  {
    byte_swap_cylgroup(v5[8]); /*0x13cca9*/
    if ( v6[245] == 590421 ) /*0x13ccbb*/
    {
      v7 = 1; /*0x13ccd4*/
    }
    else
    {
      byte_swap_cylgroup(v6); /*0x13ccbe*/
      brelse(v24); /*0x13ccc7*/
      v7 = 0; /*0x13cccc*/
    }
  }
  if ( !v7 ) /*0x13ccdb*/
    return 0; /*0x13ccdd*/
  if ( v6[8] ) /*0x13cce4*/
  {
    getthetime(&v25); /*0x13cd0c*/
    v6[2] = v25; /*0x13cd14*/
    if ( !a3 || (v9 = a3 % *(_DWORD *)(v4 + 184), v10 = *((char *)v6 + v9 / 8 + 724), _bittest(&v10, v9 % 8)) ) /*0x13cd4c*/
    {
      v11 = v6[12]; /*0x13cd55*/
      v23 = v11 / 8; /*0x13cd64*/
      v12 = *(_DWORD *)(v4 + 184) - v11; /*0x13cd6f*/
      v13 = v12 + 7; /*0x13cd71*/
      if ( v12 + 7 < 0 ) /*0x13cd76*/
        v13 = v12 + 14; /*0x13cd78*/
      v22 = v13 >> 3; /*0x13cd7e*/
      v14 = skpc(255, v13 >> 3, (char *)v6 + v23 + 724); /*0x13cd9a*/
      if ( !v14 ) /*0x13cda1*/
      {
        v22 = v23 + 1; /*0x13cda7*/
        v23 = 0; /*0x13cdaa*/
        v14 = skpc(255, v22, v6 + 181); /*0x13cdc3*/
        if ( !v14 ) /*0x13cdca*/
        {
          printf("cg = %s, irotor = %d, fs = %s\n", (const char *)a2, v6[12], (const char *)(v4 + 212)); /*0x13cde0*/
          panic(aIalloccgMapCor); /*0x13cdea*/
        }
      }
      v15 = v22 + v23 - v14; /*0x13cdf8*/
      v16 = *((char *)v6 + v15 + 724); /*0x13cdfa*/
      v9 = 8 * v15; /*0x13ce02*/
      v17 = 1; /*0x13ce09*/
      while ( (v16 & v17) != 0 ) /*0x13ce12*/
      {
        v17 *= 2; /*0x13ce18*/
        ++v9; /*0x13ce1a*/
        if ( v17 > 255 ) /*0x13ce20*/
        {
          printf("fs = %s\n", (const char *)(v4 + 212)); /*0x13ce2e*/
          panic(aIalloccgBlockN); /*0x13ce38*/
        }
      }
      v6[12] = v9; /*0x13cd00*/
    }
    *((_BYTE *)v6 + v9 / 8 + 724) |= 1 << (v9 % 8); /*0x13ce5e*/
    --v6[8]; /*0x13ce65*/
    --*(_DWORD *)(v4 + 200); /*0x13ce68*/
    v18 = *(_DWORD *)(v4 + 4 * (a2 >> *(_DWORD *)(v4 + 112)) + 728); /*0x13ce7e*/
    v19 = 16 * (a2 & ~*(_DWORD *)(v4 + 108)); /*0x13ce85*/
    --*(_DWORD *)(v18 + v19 + 8); /*0x13ce88*/
    ++*(_BYTE *)(v4 + 208); /*0x13ce8c*/
    if ( (a4 & 0xF000) == 0x4000 ) /*0x13ce9f*/
    {
      ++v6[6]; /*0x13cea1*/
      ++*(_DWORD *)(v4 + 192); /*0x13cea4*/
      v20 = *(_DWORD *)(v4 + 4 * (a2 >> *(_DWORD *)(v4 + 112)) + 728); /*0x13ceba*/
      v21 = 16 * (a2 & ~*(_DWORD *)(v4 + 108)); /*0x13cec1*/
      ++*(_DWORD *)(v20 + v21); /*0x13cec4*/
    }
    byte_swap_cylgroup(v6); /*0x13cec8*/
    bdwrite(v24); /*0x13ced1*/
    return v9 + *(_DWORD *)(v4 + 184) * a2; /*0x13cee0*/
  }
  else
  {
    byte_swap_cylgroup(v6); /*0x13cceb*/
    brelse(v24); /*0x13ccf4*/
    return 0; /*0x13ccf9*/
  }
}
