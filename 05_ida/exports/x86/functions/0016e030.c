/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e030. */
int __cdecl mach_host_server(int a1, _DWORD *a2)
{
  int v2; // ecx
  void (__cdecl *v3)(); // eax

  *a2 = *(unsigned __int8 *)(a1 + 1); /*0x16e03f*/
  a2[1] = 32; /*0x16e041*/
  a2[2] = *(_DWORD *)(a1 + 12); /*0x16e04b*/
  a2[3] = 0; /*0x16e04e*/
  a2[4] = 0; /*0x16e055*/
  a2[5] = *(_DWORD *)(a1 + 20) + 100; /*0x16e062*/
  a2[6] = dword_1E0278; /*0x16e06b*/
  v2 = *(_DWORD *)(a1 + 20); /*0x16e06e*/
  if ( (unsigned int)(v2 - 2600) <= 0x29 && (v3 = (void (__cdecl *)())funcs_16E096[v2 - 2600]) != nullptr ) /*0x16e085*/
  {
    v3(); /*0x16e096*/
    return 1; /*0x16e098*/
  }
  else
  {
    a2[7] = -303; /*0x16e087*/
    return 0; /*0x16e08e*/
  }
}
