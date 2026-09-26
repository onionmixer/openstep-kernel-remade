/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x111f90. */
int __cdecl ptswrite(unsigned __int8 a1, int a2)
{
  int v2; // edx

  v2 = dword_1E56D0[4 * a1]; /*0x111f9a*/
  if ( *(_DWORD *)(v2 + 36) ) /*0x111fa0*/
    return ((int (__stdcall *)(int, int))*(&off_1DAFF4 + 12 * *(char *)(v2 + 71)))(v2, a2); /*0x111fbb*/
  else
    return 5; /*0x111fc4*/
}
