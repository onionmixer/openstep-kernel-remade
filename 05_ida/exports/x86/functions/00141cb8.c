/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x141cb8. */
int __cdecl indirtrunc(_DWORD *a1, int a2, int a3, int a4)
{
  int i; // ebx
  int v5; // edi
  int v6; // ebx
  int j; // ebx
  int v9; // esi
  unsigned __int32 v10; // esi
  int v11; // [esp+18h] [ebp-18h]
  int v12; // [esp+1Ch] [ebp-14h]
  int v13; // [esp+20h] [ebp-10h]
  int *v14; // [esp+24h] [ebp-Ch]
  char *v15; // [esp+28h] [ebp-8h]
  _DWORD *v16; // [esp+28h] [ebp-8h]
  int *v17; // [esp+2Ch] [ebp-4h]
  int v18; // [esp+2Ch] [ebp-4h]

  v14 = (int *)a1[20]; /*0x141cc7*/
  v12 = 0; /*0x141cca*/
  v13 = 1; /*0x141cd1*/
  for ( i = 0; a4 > i; ++i ) /*0x141ce0*/
    v13 *= *(_DWORD *)(a1[20] + 116); /*0x141cee*/
  v5 = a3; /*0x141cf7*/
  if ( a3 > 0 ) /*0x141cfc*/
    v5 = a3 / v13; /*0x141d04*/
  v11 = v14[12] / (*(int (__cdecl **)(_DWORD *))(a1[10] + 128))(a1 + 3); /*0x141d28*/
  v6 = geteblk(v14[12]); /*0x141d31*/
  v17 = bread(a1[16], a2 << v14[25], v14[12]); /*0x141d52*/
  if ( (*(_BYTE *)v17 & 4) != 0 ) /*0x141d5b*/
  {
    brelse(v6); /*0x141d5e*/
    brelse((int)v17); /*0x141d67*/
    return 0; /*0x141d6c*/
  }
  else
  {
    v15 = (char *)v17[8]; /*0x141d7a*/
    bcopy(v15, *(void **)(v6 + 32), v14[12]); /*0x141d8c*/
    bzero(&v15[4 * v5 + 4], 4 * (v14[29] - 1 - v5)); /*0x141daa*/
    bwrite(v17); /*0x141db3*/
    v18 = v6; /*0x141db8*/
    v16 = *(_DWORD **)(v6 + 32); /*0x141dbe*/
    for ( j = v14[29] - 1; j > v5; --j ) /*0x141dcd*/
    {
      v9 = _byteswap_ulong(v16[j]); /*0x141dd8*/
      if ( v9 ) /*0x141ddc*/
      {
        if ( a4 > 0 ) /*0x141de2*/
          v12 += indirtrunc(a1, v9, -1, a4 - 1); /*0x141df7*/
        free_block((int)a1, v9, v14[12]); /*0x141e09*/
        v12 += v11; /*0x141e11*/
      }
    }
    if ( a4 > 0 && a3 >= 0 ) /*0x141e26*/
    {
      v10 = _byteswap_ulong(v16[j]); /*0x141e39*/
      if ( v10 ) /*0x141e3d*/
        v12 += indirtrunc(a1, v10, a3 % v13, a4 - 1); /*0x141e51*/
    }
    brelse(v18); /*0x141e5b*/
    return v12; /*0x141e60*/
  }
}
