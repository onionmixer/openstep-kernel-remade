/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10cd54. */
ssize_t __cdecl read(int a1, void *a2, size_t a3)
{
  int v3; // eax
  _DWORD v5[2]; // [esp+0h] [ebp-20h] BYREF
  int v6[6]; // [esp+8h] [ebp-18h] BYREF

  v3 = *(_DWORD *)(dword_1E875C + 36); /*0x10cd5f*/
  v5[0] = *(_DWORD *)(v3 + 4); /*0x10cd65*/
  v5[1] = *(_DWORD *)(v3 + 8); /*0x10cd6b*/
  v6[0] = (int)v5; /*0x10cd71*/
  v6[1] = 1; /*0x10cd74*/
  return rwuio(v6, 0); /*0x10cd86*/
}
