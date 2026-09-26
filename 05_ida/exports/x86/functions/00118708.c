/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x118708. */
int __cdecl unp_bind(_DWORD *a1, int a2)
{
  int v2; // edi
  __int16 v3; // ax
  int result; // eax
  int v5; // eax
  int v6; // [esp+Ch] [ebp-44h] BYREF
  int v7; // [esp+10h] [ebp-40h] BYREF
  __int16 v8; // [esp+14h] [ebp-3Ch]

  v2 = *(_DWORD *)(a2 + 4) + a2; /*0x118716*/
  if ( a1[1] ) /*0x11871c*/
    return 22; /*0x11871c*/
  v3 = *(_WORD *)(a2 + 8); /*0x118722*/
  if ( v3 == 112 ) /*0x11872a*/
    return 22; /*0x11872c*/
  *(_BYTE *)(v3 + v2) = 0; /*0x118735*/
  vattr_null(&v7); /*0x11873d*/
  v7 = 6; /*0x118742*/
  v8 = 511; /*0x118749*/
  result = vn_create(v2 + 2, 1, &v7, 1, 0, &v6); /*0x11875e*/
  if ( result ) /*0x118768*/
  {
    if ( result == 17 ) /*0x11876d*/
      return 48; /*0x11876f*/
  }
  else
  {
    v5 = v6; /*0x118778*/
    *(_DWORD *)(v6 + 32) = *a1; /*0x118780*/
    a1[1] = v5; /*0x118786*/
    a1[6] = m_copy((int *)a2, 0, 1000000000); /*0x118799*/
    return 0; /*0x11879c*/
  }
  return result; /*0x1187a1*/
}
