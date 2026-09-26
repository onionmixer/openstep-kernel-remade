/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a2fc8. */
int __cdecl sub_1A2FC8(int a1, int a2, int a3, unsigned __int16 a4)
{
  unsigned __int16 v4; // ax
  int v5; // ecx
  int *v6; // eax
  int v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // edx
  int v10; // ecx
  int v11; // ebx
  int v12; // edx
  int v13; // eax
  int v14; // ebx
  unsigned __int16 *v16; // [esp+Ch] [ebp-18h]
  int v17; // [esp+10h] [ebp-14h]
  int v18; // [esp+14h] [ebp-10h] BYREF
  unsigned int v19; // [esp+18h] [ebp-Ch]
  unsigned int v20; // [esp+1Ch] [ebp-8h]
  unsigned int v21; // [esp+20h] [ebp-4h]

  v4 = *(_WORD *)(a2 + 72); /*0x1a2fd4*/
  if ( (v4 & 4) == 0 ) /*0x1a2fda*/
    return 0; /*0x1a2fda*/
  v5 = v4 >> 3; /*0x1a2fe4*/
  v6 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a2fed*/
  v7 = 0; /*0x1a2ff3*/
  if ( v6 ) /*0x1a2ff7*/
    v7 = *v6; /*0x1a2ff9*/
  if ( *(_DWORD *)(v7 + 60) <= (unsigned int)(8 * v5) ) /*0x1a3005*/
    return 0; /*0x1a3126*/
  v8 = *(_DWORD *)(v7 + 56) + 8 * v5; /*0x1a3010*/
  *(_DWORD *)(a1 + 116) = &loc_1A303C; /*0x1a3016*/
  v20 = __readfsdword(v8); /*0x1a3020*/
  v21 = __readfsdword(v8 + 4); /*0x1a3027*/
  *(_DWORD *)(a1 + 116) = 0; /*0x1a302d*/
  LOWORD(v18) = a4; /*0x1a3054*/
  LOWORD(v7) = *(_WORD *)(a2 + 56); /*0x1a305b*/
  v9 = v7 << 16; /*0x1a305f*/
  HIWORD(v8) = HIWORD(v9); /*0x1a3067*/
  v18 = v9 | a4; /*0x1a3069*/
  LOWORD(v19) = *(_WORD *)(a2 + 60); /*0x1a3070*/
  LOWORD(v8) = *(_WORD *)(a2 + 64); /*0x1a3074*/
  v10 = (v8 << 16) | (unsigned __int16)v19; /*0x1a307e*/
  v19 = v10; /*0x1a3080*/
  if ( a3 ) /*0x1a3087*/
  {
    v9 = v10 & 0xFDFF0000 | 0x2000000; /*0x1a3091*/
    v19 = v9 | (unsigned __int16)v10; /*0x1a309c*/
  }
  else
  {
    v19 = v10 & 0xFDFFFFFF; /*0x1a30aa*/
  }
  v11 = *(_DWORD *)(a2 + 68) - 8; /*0x1a30b3*/
  v16 = (unsigned __int16 *)&v18; /*0x1a30b9*/
  v17 = 8; /*0x1a30bc*/
  LOBYTE(v9) = HIBYTE(v21); /*0x1a30ce*/
  v12 = ((unsigned __int8)v21 << 16) | HIWORD(v20) | (v9 << 24); /*0x1a30d6*/
  v13 = 0xFFFF; /*0x1a30d8*/
  if ( (v21 & 0x400000) != 0 ) /*0x1a30e1*/
    v13 = -1; /*0x1a30e3*/
  *(_DWORD *)(a1 + 116) = &loc_1A311C; /*0x1a30eb*/
  do /*0x1a310c*/
  {
    v14 = v13 & v11; /*0x1a30f4*/
    __writefsword(v14 + v12, *v16++); /*0x1a30fc*/
    v11 = v14 + 2; /*0x1a3105*/
    v17 -= 2; /*0x1a3108*/
  }
  while ( v17 ); /*0x1a310c*/
  *(_DWORD *)(a1 + 116) = 0; /*0x1a3111*/
  if ( (v21 & 0x400000) != 0 ) /*0x1a3130*/
    *(_DWORD *)(a2 + 68) -= 8; /*0x1a3135*/
  else
    *(_DWORD *)(a2 + 68) = (unsigned __int16)(*(_WORD *)(a2 + 68) - 8); /*0x1a314c*/
  return 1; /*0x1a3157*/
}
