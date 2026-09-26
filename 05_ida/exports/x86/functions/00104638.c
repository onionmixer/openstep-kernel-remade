/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x104638. */
int __cdecl fstat(int a1, stat *a2)
{
  _DWORD *v2; // ebx
  int v3; // edx
  int result; // eax
  __int16 v5; // ax
  char v6; // al
  char v7; // dl
  _BYTE v8[64]; // [esp+4h] [ebp-40h] BYREF

  v2 = *(_DWORD **)(dword_1E875C + 36); /*0x104644*/
  if ( *(_DWORD *)(active_u + 348) > *v2 /*0x104669*/
    && (v3 = *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * *v2)) != 0
    && v3 != -65536 )
  {
    v5 = *(_WORD *)(v3 + 12); /*0x104678*/
    if ( v5 == 1 ) /*0x104680*/
    {
      v6 = vno_stat(*(_DWORD **)(v3 + 24), (int)v8); /*0x104694*/
    }
    else
    {
      if ( v5 != 2 ) /*0x104686*/
        panic(aFstat); /*0x1046bd*/
      v6 = soo_stat(*(_DWORD *)(v3 + 24), v8); /*0x1046a4*/
    }
    *(_BYTE *)(dword_1E875C + 104) = v6; /*0x1046b0*/
    result = dword_1E875C; /*0x1046c5*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x1046ca*/
    {
      v7 = copyout(v8, v2[1], 64); /*0x1046df*/
      result = dword_1E875C; /*0x1046e1*/
      *(_BYTE *)(dword_1E875C + 104) = v7; /*0x1046e6*/
    }
  }
  else
  {
    result = dword_1E875C; /*0x10466b*/
    *(_BYTE *)(dword_1E875C + 104) = 9; /*0x104670*/
  }
  return result; /*0x1046e9*/
}
