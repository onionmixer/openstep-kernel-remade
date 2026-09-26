/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x143b64. */
int __cdecl sub_143B64(int a1, int a2)
{
  int v2; // edx
  int v4; // [esp+4h] [ebp-4h] BYREF

  v2 = lookupname(a1, 0, 1, 0, (int)&v4); /*0x143b81*/
  if ( v2 ) /*0x143b88*/
  {
    if ( *(_BYTE *)(dword_1E875C + 104) == 2 ) /*0x143b93*/
      return 19; /*0x143b95*/
    else
      return v2; /*0x143b9c*/
  }
  else if ( *(_DWORD *)(v4 + 40) == 3 ) /*0x143ba7*/
  {
    *(_WORD *)a2 = *(_WORD *)(v4 + 44); /*0x143bbc*/
    vn_rele(v4); /*0x143bc3*/
    if ( nblkdev <= *(unsigned __int8 *)(a2 + 1) ) /*0x143bd2*/
      return 6; /*0x143bd8*/
    else
      return 0; /*0x143bd4*/
  }
  else
  {
    vn_rele(v4); /*0x143baa*/
    return 15; /*0x143baf*/
  }
}
