/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10d614. */
int __cdecl selscan(int a1, int a2, int a3)
{
  int v3; // esi
  unsigned int v4; // ebx
  int v5; // edx
  int v7; // [esp+Ch] [ebp-1Ch]
  int v8; // [esp+10h] [ebp-18h]
  int v9; // [esp+18h] [ebp-10h]
  int v10; // [esp+1Ch] [ebp-Ch]
  int v11; // [esp+20h] [ebp-8h]
  int v12; // [esp+24h] [ebp-4h]

  v9 = 0; /*0x10d61d*/
  v12 = 0; /*0x10d624*/
  v8 = 0; /*0x10d62b*/
  do /*0x10d720*/
  {
    v10 = dword_1DACA8[v12]; /*0x10d63e*/
    v11 = 0; /*0x10d641*/
    if ( a3 <= 0 ) /*0x10d64e*/
      goto LABEL_16; /*0x10d64e*/
    do /*0x10d70f*/
    {
      v3 = *(_DWORD *)(a1 + v8 + 4 * ((unsigned int)v11 >> 5)); /*0x10d66b*/
      if ( !v3 ) /*0x10d670*/
        goto LABEL_15; /*0x10d670*/
      v7 = 0; /*0x10d676*/
      while ( 1 ) /*0x10d680*/
      {
        if ( (v3 & 1) == 0 ) /*0x10d686*/
        {
          v3 >>= 1; /*0x10d688*/
          goto LABEL_14; /*0x10d68a*/
        }
        v4 = v7 + v11; /*0x10d68f*/
        if ( a3 <= v7 + v11 || *(_DWORD *)(active_u + 348) <= (signed int)v4 ) /*0x10d6a2*/
          goto LABEL_15; /*0x10d6a2*/
        v5 = *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * v4); /*0x10d6aa*/
        if ( !v5 ) /*0x10d6af*/
          break; /*0x10d6af*/
        if ( (*(int (__cdecl **)(int, int))(*(_DWORD *)(v5 + 20) + 8))(v5, v10) ) /*0x10d6c7*/
        {
          *(_DWORD *)(a2 + v8 + 4 * (v4 >> 5)) |= 1 << (v4 & 0x1F); /*0x10d6ee*/
          ++v9; /*0x10d6f1*/
        }
        v3 >>= 1; /*0x10d6f4*/
        if ( !v3 ) /*0x10d6f6*/
          goto LABEL_15; /*0x10d6f6*/
LABEL_14:
        if ( (unsigned int)++v7 > 0x1F ) /*0x10d6ff*/
          goto LABEL_15; /*0x10d6ff*/
      }
      *(_BYTE *)(dword_1E875C + 104) = 9; /*0x10d6b6*/
LABEL_15:
      v11 += 32; /*0x10d705*/
    }
    while ( v11 < a3 ); /*0x10d70f*/
LABEL_16:
    v8 += 32; /*0x10d715*/
    ++v12; /*0x10d719*/
  }
  while ( v12 <= 2 ); /*0x10d720*/
  return v9; /*0x10d72c*/
}
