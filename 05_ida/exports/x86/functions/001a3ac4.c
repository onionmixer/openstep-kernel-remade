/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a3ac4. */
_BOOL4 __cdecl PCemulatePROT(int a1, int a2)
{
  int v2; // eax
  int *v3; // eax
  unsigned int v4; // edx
  int v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  int *v8; // eax
  unsigned int v9; // edx
  signed int v10; // ecx
  int v11; // eax
  int *v13; // eax
  unsigned int v14; // edx
  int v15; // eax
  int v16; // [esp+Ch] [ebp-8h]
  int v17; // [esp+Ch] [ebp-8h]
  _DWORD *v18; // [esp+10h] [ebp-4h]
  _DWORD *v19; // [esp+10h] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 48); /*0x1a3ad0*/
  if ( v2 != 13 ) /*0x1a3ad6*/
  {
    if ( v2 != 6 ) /*0x1a3b4b*/
    {
      v13 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a3c36*/
      v16 = 0; /*0x1a3c3c*/
      if ( v13 ) /*0x1a3c45*/
        v16 = *v13; /*0x1a3c49*/
      v14 = *(_DWORD *)(v16 + 132); /*0x1a3c4f*/
      if ( v14 > 7 ) /*0x1a3c58*/
        v18 = nullptr; /*0x1a3c70*/
      else
        v18 = (_DWORD *)(v16 + 132 * v14 + 136); /*0x1a3c68*/
      v5 = v16 + 4; /*0x1a3c7a*/
      v6 = *(_DWORD *)(a2 + 48); /*0x1a3c7d*/
      if ( v6 > 0x1F ) /*0x1a3c83*/
        goto LABEL_31; /*0x1a3c83*/
LABEL_30:
      v15 = ((1 << v6) & *(_DWORD *)(v16 + 4)) != 0; /*0x1a3c85*/
      goto LABEL_32; /*0x1a3c9a*/
    }
    sub_1A2B40(a1, a2); /*0x1a3b56*/
    if ( !v7 ) /*0x1a3b60*/
    {
      v8 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a3b69*/
      v17 = 0; /*0x1a3b6f*/
      if ( v8 ) /*0x1a3b78*/
        v17 = *v8; /*0x1a3b7c*/
      v9 = *(_DWORD *)(v17 + 132); /*0x1a3b82*/
      if ( v9 > 7 ) /*0x1a3b8b*/
        v19 = nullptr; /*0x1a3ba0*/
      else
        v19 = (_DWORD *)(v17 + 132 * v9 + 136); /*0x1a3b9b*/
      v10 = *(_DWORD *)(a2 + 48); /*0x1a3bad*/
      if ( (unsigned int)v10 > 0x1F ) /*0x1a3bb3*/
        v11 = ((int)*(unsigned __int8 *)(v10 / 8 + v17 + 4) >> (v10 % 8)) & 1; /*0x1a3be5*/
      else
        v11 = ((1 << v10) & *(_DWORD *)(v17 + 4)) != 0; /*0x1a3bc5*/
      if ( v11 ) /*0x1a3bea*/
      {
        v19[19] = *(_DWORD *)(a2 + 48); /*0x1a3bf2*/
        v19[20] = *(_DWORD *)(a2 + 52); /*0x1a3bf8*/
        v19[22] = 1; /*0x1a3bfb*/
        PCcallMonitor(a1, (__int16 *)a2); /*0x1a3c07*/
      }
      return sub_1A3160(a1, a2, *(_DWORD *)(a2 + 48), *(_DWORD *)(a2 + 52), 0) != 0; /*0x1a3c07*/
    }
    return 1; /*0x1a3c29*/
  }
  if ( sub_1A37C0(a1, a2) ) /*0x1a3add*/
    return 1; /*0x1a3ae7*/
  v3 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a3af0*/
  v16 = 0; /*0x1a3af6*/
  if ( v3 ) /*0x1a3aff*/
    v16 = *v3; /*0x1a3b03*/
  v4 = *(_DWORD *)(v16 + 132); /*0x1a3b09*/
  if ( v4 > 7 ) /*0x1a3b12*/
    v18 = nullptr; /*0x1a3b28*/
  else
    v18 = (_DWORD *)(v16 + 132 * v4 + 136); /*0x1a3b22*/
  v5 = v16 + 4; /*0x1a3b32*/
  v6 = *(_DWORD *)(a2 + 48); /*0x1a3b35*/
  if ( v6 <= 0x1F ) /*0x1a3b3b*/
    goto LABEL_30; /*0x1a3b3b*/
LABEL_31:
  v15 = ((int)*(unsigned __int8 *)((int)v6 / 8 + v5) >> ((int)v6 % 8)) & 1; /*0x1a3ca5*/
LABEL_32:
  if ( v15 ) /*0x1a3cba*/
  {
    v18[19] = *(_DWORD *)(a2 + 48); /*0x1a3cc2*/
    v18[20] = *(_DWORD *)(a2 + 52); /*0x1a3cc8*/
    v18[22] = 1; /*0x1a3ccb*/
    PCcallMonitor(a1, (__int16 *)a2); /*0x1a3cd7*/
  }
  return sub_1A3160(a1, a2, *(_DWORD *)(a2 + 48), *(_DWORD *)(a2 + 52), 0) != 0; /*0x1a3d03*/
}
