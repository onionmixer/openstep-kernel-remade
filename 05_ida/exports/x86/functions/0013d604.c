/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13d604. */
int __cdecl mapsearch(int a1, int a2, int a3, int a4)
{
  int v4; // edx
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // edi
  int v9; // edx
  int v10; // ebx
  int v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+1Ch] [ebp-4h]

  if ( a3 ) /*0x13d612*/
    v12 = a3 % *(_DWORD *)(a1 + 188) / 8; /*0x13d628*/
  else
    v12 = *(_DWORD *)(a2 + 44) / 8; /*0x13d640*/
  v4 = *(_DWORD *)(a1 + 188); /*0x13d646*/
  v5 = v4 + 7; /*0x13d64c*/
  if ( v4 + 7 < 0 ) /*0x13d651*/
    v5 = v4 + 14; /*0x13d653*/
  v6 = (v5 >> 3) - v12; /*0x13d65b*/
  v7 = scanc(v6, a2 + v12 + 984, fragtbl[*(_DWORD *)(a1 + 56)], 1 << (a4 + *(_DWORD *)(a1 + 56) % 8 - 1)); /*0x13d6a4*/
  if ( !v7 ) /*0x13d6ab*/
  {
    v6 = v12 + 1; /*0x13d6b0*/
    v12 = 0; /*0x13d6b1*/
    v7 = scanc(v6, a2 + 984, fragtbl[*(_DWORD *)(a1 + 56)], 1 << (a4 + *(_DWORD *)(a1 + 56) % 8 - 1)); /*0x13d6f9*/
    if ( !v7 ) /*0x13d700*/
    {
      printf("start = %d, len = %d, fs = %s\n", 0, v6, (const char *)(a1 + 212)); /*0x13d713*/
      panic(aAlloccgMapCorr); /*0x13d71d*/
    }
  }
  v8 = 8 * (v6 + v12 - v7); /*0x13d72c*/
  *(_DWORD *)(a2 + 44) = v8; /*0x13d736*/
  v15 = v8 + 8; /*0x13d73c*/
  if ( v8 >= v8 + 8 ) /*0x13d741*/
  {
LABEL_14:
    printf("bno = %d, fs = %s\n", v8, (const char *)(a1 + 212)); /*0x13d7d8*/
    panic(aAlloccgBlockNo); /*0x13d7f1*/
  }
  while ( 1 ) /*0x13d772*/
  {
    v14 = *(_DWORD *)(a1 + 56); /*0x13d772*/
    v13 = around[a4]; /*0x13d797*/
    v9 = inside[a4]; /*0x13d79d*/
    v10 = 0; /*0x13d7a4*/
    if ( v14 - a4 >= 0 ) /*0x13d7ad*/
      break; /*0x13d7ad*/
LABEL_13:
    v8 += *(_DWORD *)(a1 + 56); /*0x13d7c9*/
    if ( v15 <= v8 ) /*0x13d7d2*/
      goto LABEL_14; /*0x13d7d2*/
  }
  while ( (v13 & (2 * ((255 >> (8 - v14)) & ((int)*(unsigned __int8 *)(v8 / 8 + a2 + 984) >> (v8 % 8))))) != v9 ) /*0x13d7bc*/
  {
    v13 *= 2; /*0x13d7be*/
    v9 *= 2; /*0x13d7c1*/
    if ( v14 - a4 < ++v10 ) /*0x13d7c7*/
      goto LABEL_13; /*0x13d7c7*/
  }
  return v10 + v8; /*0x13d806*/
}
