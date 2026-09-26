/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x102f14. */
int binit()
{
  int *v0; // ecx
  int *v1; // ebx
  int result; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // esi
  int v6; // ecx
  int v7; // eax
  int v8; // [esp+Ch] [ebp-4h]

  v0 = &bfreelist; /*0x102f1d*/
  if ( &bfreelist < (int *)&buf ) /*0x102f28*/
  {
    v1 = &dword_1E8764; /*0x102f2a*/
    do /*0x102f4d*/
    {
      v1[3] = (int)v0; /*0x102f30*/
      v1[2] = (int)v0; /*0x102f33*/
      v1[1] = (int)v0; /*0x102f36*/
      *v1 = (int)v0; /*0x102f39*/
      *v0 = 0x40000; /*0x102f3b*/
      v1 += 17; /*0x102f41*/
      v0 += 17; /*0x102f44*/
    }
    while ( v0 < (int *)&buf ); /*0x102f4d*/
  }
  result = bufpages / nbuf; /*0x102f58*/
  v8 = bufpages % nbuf; /*0x102f5e*/
  v3 = bufpages / nbuf; /*0x102f61*/
  v4 = 0; /*0x102f63*/
  if ( nbuf > 0 ) /*0x102f6b*/
  {
    v5 = 0; /*0x102f71*/
    do /*0x10301e*/
    {
      v6 = v5 + buf; /*0x102f7a*/
      *(_WORD *)(v6 + 30) = -1; /*0x102f7c*/
      *(_DWORD *)(v6 + 20) = 0; /*0x102f82*/
      *(_DWORD *)(v6 + 32) = buffers + (v4 << 13); /*0x102f94*/
      if ( v8 <= v4 ) /*0x102f9a*/
        v7 = v3; /*0x102fa4*/
      else
        v7 = v3 + 1; /*0x102f9c*/
      *(_DWORD *)(v6 + 24) = page_size * v7; /*0x102fad*/
      *(_DWORD *)(v6 + 60) = 0; /*0x102fb0*/
      if ( *(_DWORD *)(v6 + 24) ) /*0x102fb7*/
      {
        *(_DWORD *)(v6 + 4) = dword_1E87EC; /*0x102fc3*/
        *(_DWORD *)(v6 + 8) = &unk_1E87E8; /*0x102fc6*/
        *(_DWORD *)(dword_1E87EC + 8) = v6; /*0x102fd2*/
        dword_1E87EC = v6; /*0x102fd5*/
      }
      else
      {
        *(_DWORD *)(v6 + 4) = dword_1E8830; /*0x102fe6*/
        *(_DWORD *)(v6 + 8) = &unk_1E882C; /*0x102fe9*/
        *(_DWORD *)(dword_1E8830 + 8) = v6; /*0x102ff5*/
        dword_1E8830 = v6; /*0x102ff8*/
      }
      *(_DWORD *)(v6 + 64) = 0; /*0x102ffe*/
      *(_DWORD *)v6 = 65544; /*0x103005*/
      result = brelse(v6); /*0x10300c*/
      v5 += 68; /*0x103014*/
      ++v4; /*0x103017*/
    }
    while ( nbuf > v4 ); /*0x10301e*/
  }
  return result; /*0x103027*/
}
