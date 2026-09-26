/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1187a8. */
int __cdecl unp_connect(int a1, int a2)
{
  int v2; // edx
  int v3; // ebx
  int v4; // ecx
  int result; // eax
  int v6; // eax
  char *v7; // edx
  int v8; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h] BYREF

  v2 = *(_DWORD *)(a2 + 4); /*0x1187b7*/
  v3 = v2 + a2; /*0x1187ba*/
  v4 = *(__int16 *)(a2 + 8); /*0x1187bd*/
  if ( v2 + v4 == 124 ) /*0x1187c8*/
    return 40; /*0x1187cf*/
  *(_BYTE *)(v4 + v3) = 0; /*0x1187d4*/
  result = lookupname(v3 + 2, 1, 1, 0, (int)&v9); /*0x1187e6*/
  if ( !result ) /*0x1187f0*/
  {
    if ( *(_DWORD *)(v9 + 40) != 6 ) /*0x1187f9*/
    {
      v6 = 38; /*0x1187fb*/
LABEL_14:
      v8 = v6; /*0x11884e*/
      vn_rele(v9); /*0x118855*/
      return v8; /*0x11885a*/
    }
    v7 = *(char **)(v9 + 32); /*0x118804*/
    if ( v7 ) /*0x118809*/
    {
      if ( *(_WORD *)a1 != *(_WORD *)v7 ) /*0x118811*/
      {
        v6 = 41; /*0x118813*/
        goto LABEL_14; /*0x118818*/
      }
      if ( (*(_BYTE *)(*(_DWORD *)(a1 + 12) + 10) & 4) == 0 || (v7[2] & 2) != 0 && (v7 = sonewconn((int)v7)) != nullptr ) /*0x118838*/
      {
        v6 = unp_connect2(a1, v7); /*0x118846*/
        goto LABEL_14; /*0x118846*/
      }
    }
    v6 = 61; /*0x11883a*/
    goto LABEL_14; /*0x11883f*/
  }
  return result; /*0x118860*/
}
