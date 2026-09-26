/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1429dc. */
void __cdecl syncip(int a1)
{
  _DWORD *v1; // esi
  int i; // ebx
  unsigned int v3; // edx
  unsigned int v4; // eax
  unsigned int v5; // ebx
  _DWORD *v6; // esi
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // [esp+0h] [ebp-1Ch]
  _DWORD *v11; // [esp+4h] [ebp-18h]
  int v12; // [esp+Ch] [ebp-10h]
  int v13; // [esp+10h] [ebp-Ch]
  signed int v14; // [esp+14h] [ebp-8h]
  unsigned int v15; // [esp+18h] [ebp-4h]

  v1 = *(_DWORD **)(a1 + 80); /*0x1429e8*/
  v14 = (unsigned int)(v1[12] + *(_DWORD *)(a1 + 108) - 1) / v1[12]; /*0x1429fa*/
  if ( v14 >= nbuf / 2 ) /*0x142a0f*/
  {
    v15 = buf + 68 * nbuf; /*0x142a94*/
    v5 = buf; /*0x142a97*/
    if ( buf < v15 ) /*0x142a9b*/
    {
      v6 = (_DWORD *)(buf + 16); /*0x142a9d*/
      do /*0x142b18*/
      {
        if ( v6[12] == *(_DWORD *)(a1 + 64) && (*(_BYTE *)(v5 + 1) & 2) != 0 ) /*0x142aaf*/
        {
          v7 = splbio(); /*0x142ab6*/
          v8 = *(_DWORD *)v5; /*0x142ab8*/
          if ( (*(_DWORD *)v5 & 8) != 0 ) /*0x142abc*/
          {
            LOBYTE(v8) = v8 | 0x40; /*0x142abe*/
            *(_DWORD *)v5 = v8; /*0x142ac0*/
            v12 = v7; /*0x142ac5*/
            sleep(v5); /*0x142ac8*/
            splx(v12); /*0x142ad1*/
            v6 -= 17; /*0x142ad6*/
            v5 -= 68; /*0x142ad9*/
          }
          else
          {
            splx(v7); /*0x142ae1*/
            v9 = splbio(); /*0x142ae6*/
            *(_DWORD *)(*v6 + 12) = *(v6 - 1); /*0x142af2*/
            *(_DWORD *)(*(v6 - 1) + 16) = *v6; /*0x142afa*/
            *(_BYTE *)v5 |= 8u; /*0x142afd*/
            splx(v9); /*0x142b01*/
            bwrite((int *)v5); /*0x142b07*/
          }
        }
        v6 += 17; /*0x142b0f*/
        v5 += 68; /*0x142b12*/
      }
      while ( v15 > v5 ); /*0x142b18*/
    }
  }
  else
  {
    for ( i = 0; v14 > i; ++i ) /*0x142a16*/
    {
      v13 = bmap(a1, i, 1, v10, v11) << v1[25]; /*0x142a2f*/
      if ( i <= 11 && (v3 = *(_DWORD *)(a1 + 108), v3 < (i + 1) << v1[20]) ) /*0x142a4c*/
        v4 = v1[19] & (v1[13] + (v3 & ~v1[18]) - 1); /*0x142a5f*/
      else
        v4 = v1[12]; /*0x142a4e*/
      blkflush(*(_DWORD *)(a1 + 64), v13, v4); /*0x142a6e*/
    }
  }
  *(_BYTE *)(a1 + 68) |= 0x40u; /*0x142b1d*/
  iupdat(a1, 1); /*0x142b24*/
}
