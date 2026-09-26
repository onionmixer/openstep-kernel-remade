/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11932c. */
int __cdecl fstatfs(int a1, statfs *a2)
{
  _DWORD *v2; // ebx
  int result; // eax
  int v4; // [esp+4h] [ebp-4h] BYREF

  v2 = *(_DWORD **)(dword_1E875C + 36); /*0x119338*/
  *(_BYTE *)(dword_1E875C + 104) = getvnodefp(*v2, &v4); /*0x11934e*/
  result = dword_1E875C; /*0x119351*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x119359*/
    return cstatfs(*(_DWORD *)(*(_DWORD *)(v4 + 24) + 36), v2[1]); /*0x11936d*/
  return result; /*0x119372*/
}
