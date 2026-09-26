/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x180f48. */
_BOOL4 __cdecl sub_180F48(_BYTE *a1, _DWORD *a2, unsigned int *a3)
{
  _BYTE *v3; // edi
  int v4; // ecx
  int v5; // ebx
  unsigned int v6; // esi
  signed int v7; // ecx
  int v8; // ebx
  signed int v9; // eax
  _BYTE *v10; // eax
  unsigned int v12; // [esp+10h] [ebp-14h]
  int v13; // [esp+18h] [ebp-Ch]
  int v14; // [esp+1Ch] [ebp-8h]
  unsigned int v15; // [esp+20h] [ebp-4h]

  v3 = a1; /*0x180f51*/
  v14 = 0; /*0x180f54*/
  v12 = 0; /*0x180f5b*/
  do /*0x180f86*/
  {
    v4 = (char)*v3++; /*0x180f64*/
    v5 = 0; /*0x180f6b*/
    if ( (_BYTE)v4 == 32 || (unsigned __int8)(v4 - 9) <= 1u ) /*0x180f78*/
      v5 = 1; /*0x180f7f*/
  }
  while ( v5 ); /*0x180f86*/
  if ( v4 == 45 ) /*0x180f8b*/
  {
    v14 = 1; /*0x180f8d*/
  }
  else if ( v4 != 43 ) /*0x180f9b*/
  {
    goto LABEL_10; /*0x180f9b*/
  }
  v4 = (char)*v3++; /*0x180f9d*/
LABEL_10:
  if ( v4 == 48 && (*v3 == 120 || *v3 == 88) ) /*0x180fae*/
  {
    v4 = (char)v3[1]; /*0x180fb0*/
    v3 += 2; /*0x180fb4*/
    v12 = 16; /*0x180fb7*/
  }
  if ( !v12 ) /*0x180fc2*/
  {
    v12 = 10; /*0x180fc4*/
    if ( v4 == 48 ) /*0x180fce*/
      v12 = 8; /*0x180fd0*/
  }
  v15 = 0xFFFFFFFF / v12; /*0x180fe4*/
  v6 = 0; /*0x180fe7*/
  v13 = 0; /*0x180fe9*/
  while ( 1 ) /*0x180ff0*/
  {
    if ( (unsigned __int8)(v4 - 48) <= 9u ) /*0x180ff9*/
    {
      v7 = v4 - 48; /*0x180ffb*/
      goto LABEL_28; /*0x180ffe*/
    }
    v8 = 0; /*0x181000*/
    if ( (unsigned __int8)(v4 - 65) <= 0x19u || (unsigned __int8)(v4 - 97) <= 0x19u ) /*0x181012*/
      v8 = 1; /*0x181014*/
    if ( !v8 ) /*0x18101b*/
      break; /*0x18101b*/
    if ( (unsigned __int8)(v4 - 65) > 0x19u ) /*0x181023*/
      v9 = v4 - 87; /*0x18102c*/
    else
      v9 = v4 - 55; /*0x181025*/
    v7 = v9; /*0x18102f*/
LABEL_28:
    if ( (int)v12 <= v7 ) /*0x181034*/
      break; /*0x181034*/
    if ( v13 < 0 || v15 < v6 || v15 == v6 && (int)(0xFFFFFFFF % v12) < v7 ) /*0x181046*/
    {
      v13 = -1; /*0x181048*/
    }
    else
    {
      v13 = 1; /*0x181054*/
      v6 = v7 + v12 * v6; /*0x18105f*/
    }
    v4 = (char)*v3++; /*0x181061*/
  }
  if ( v13 >= 0 ) /*0x18106c*/
  {
    if ( v14 ) /*0x18107c*/
      v6 = -v6; /*0x18107e*/
  }
  else
  {
    v6 = -1; /*0x18106e*/
  }
  if ( a2 ) /*0x181084*/
  {
    v10 = a1; /*0x181086*/
    if ( v13 ) /*0x18108d*/
      v10 = v3 - 1; /*0x18108f*/
    *a2 = v10; /*0x181095*/
  }
  if ( a3 ) /*0x18109b*/
    *a3 = v6; /*0x1810a0*/
  return v13 > 0; /*0x1810b1*/
}
