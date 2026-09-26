/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1073ac. */
int __cdecl pidhash_enter(int a1)
{
  int v2; // edx

  v2 = *(_WORD *)(a1 + 48) & 0x3F; /*0x1073b6*/
  *(_DWORD *)(a1 + 64) = pidhash[v2]; /*0x1073c0*/
  pidhash[v2] = a1; /*0x1073c3*/
  return a1; /*0x1073cc*/
}
