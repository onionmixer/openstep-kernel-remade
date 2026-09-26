/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13f454. */
int *__cdecl blkatoff(int *a1, unsigned int a2, _DWORD *a3)
{
  _DWORD *v3; // esi
  int v4; // ecx
  int v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  int *v10; // eax
  int *v11; // ebx
  int v12; // [esp+0h] [ebp-10h]
  _DWORD *v13; // [esp+4h] [ebp-Ch]
  int v14; // [esp+Ch] [ebp-4h]

  v3 = (_DWORD *)a1[20]; /*0x13f460*/
  v4 = v3[20]; /*0x13f463*/
  v5 = a2 >> v4; /*0x13f469*/
  if ( (int)(a2 >> v4) <= 11 && (v6 = (v5 + 1) << v4, v7 = a1[27], v7 < v6) ) /*0x13f47a*/
    v14 = v3[19] & (v3[13] + (v7 & ~v3[18]) - 1); /*0x13f492*/
  else
    v14 = v3[12]; /*0x13f47f*/
  v8 = bmap((int)a1, v5, 1, v12, v13) << v3[25]; /*0x13f4a3*/
  if ( v8 < 0 ) /*0x13f4aa*/
  {
    sub_13F5AC(a1, aNonexixtentDir, a2); /*0x13f4b6*/
    *(_BYTE *)(dword_1E875C + 104) = 2; /*0x13f4c0*/
  }
  if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x13f4cc*/
    return nullptr; /*0x13f4d2*/
  v10 = bread(a1[16], v8, v14); /*0x13f4e1*/
  v11 = v10; /*0x13f4e6*/
  if ( (*(_BYTE *)v10 & 4) != 0 ) /*0x13f4ee*/
  {
    brelse((int)v10); /*0x13f4f1*/
    return nullptr; /*0x13f4f6*/
  }
  else
  {
    byte_swap_dir_block_in(v10[8], v10[5]); /*0x13f504*/
    if ( a3 ) /*0x13f50d*/
      *a3 = v11[8] + (a2 & ~v3[18]); /*0x13f51d*/
    return v11; /*0x13f51f*/
  }
}
