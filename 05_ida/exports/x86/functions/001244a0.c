/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1244a0. */
char *__cdecl sub_1244A0(int a1, int a2, void *a3)
{
  char *v3; // eax
  void *v4; // esi
  __int16 v5; // ax
  __int16 v6; // ax
  char *v8; // [esp+Ch] [ebp-4h]

  v3 = (char *)kalloc(0x148u); /*0x1244b4*/
  v4 = v3 + 264; /*0x1244bb*/
  v8 = v3; /*0x1244c7*/
  bzero(v3, 0x148u); /*0x1244ca*/
  *v8 = 69; /*0x1244d2*/
  v5 = ip_id++; /*0x1244d5*/
  *((_WORD *)v8 + 2) = __ROR2__(v5, 8); /*0x1244e9*/
  v8[8] = -1; /*0x1244ed*/
  v8[9] = 17; /*0x1244f1*/
  *((_DWORD *)v8 + 3) = *(_DWORD *)(a2 + 4); /*0x1244f8*/
  *((_DWORD *)v8 + 4) = -1; /*0x1244fb*/
  *((_WORD *)v8 + 10) = __ROR2__(68, 8); /*0x12450b*/
  *((_WORD *)v8 + 11) = __ROR2__(67, 8); /*0x124518*/
  *((_WORD *)v8 + 13) = 0; /*0x12451c*/
  v8[28] = 1; /*0x124522*/
  v8[29] = 1; /*0x124526*/
  v8[30] = 6; /*0x12452a*/
  *((_DWORD *)v8 + 10) = 0; /*0x12452e*/
  bcopy(a3, v8 + 56, 6u); /*0x12453c*/
  bcopy(aNext_0, v4, 4u); /*0x124549*/
  v8[268] = 1; /*0x124551*/
  v8[270] = 0; /*0x124558*/
  v6 = __ROR2__(308, 8); /*0x124564*/
  *((_WORD *)v8 + 12) = v6; /*0x124568*/
  *((_WORD *)v8 + 1) = __ROR2__(__ROR2__(v6, 8) + 20, 8); /*0x124578*/
  *((_WORD *)v8 + 5) = 0; /*0x12457c*/
  return v8; /*0x124587*/
}
