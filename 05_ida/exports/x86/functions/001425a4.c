/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1425a4. */
int __cdecl sub_1425A4(int a1)
{
  int v1; // eax
  int v2; // edx
  int v4; // [esp+4h] [ebp-8h] BYREF
  int v5; // [esp+8h] [ebp-4h] BYREF

  v1 = *(_DWORD *)(a1 + 16); /*0x1425ae*/
  v2 = *(_DWORD *)(v1 + 4); /*0x1425b1*/
  v5 = v1 + 4; /*0x1425b7*/
  while ( sub_142600(v2, a1, 2, &v5, &v4) ) /*0x1425d2*/
  {
    if ( *(_WORD *)(a1 + 2) == 2 || *(_WORD *)(v4 + 2) == 2 ) /*0x1425e3*/
      return v4; /*0x1425e8*/
    v2 = *(_DWORD *)(v4 + 20); /*0x1425ec*/
  }
  return 0; /*0x1425f6*/
}
