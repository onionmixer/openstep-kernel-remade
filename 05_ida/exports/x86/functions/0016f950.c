/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f950. */
int __cdecl mach_server(int a1, _DWORD *a2)
{
  int v2; // ecx
  void (__stdcall *v3)(int, _DWORD *); // eax

  *a2 = *(unsigned __int8 *)(a1 + 1); /*0x16f95f*/
  a2[1] = 32; /*0x16f961*/
  a2[2] = *(_DWORD *)(a1 + 12); /*0x16f96b*/
  a2[3] = 0; /*0x16f96e*/
  a2[4] = 0; /*0x16f975*/
  a2[5] = *(_DWORD *)(a1 + 20) + 100; /*0x16f982*/
  a2[6] = dword_1E0704; /*0x16f98b*/
  v2 = *(_DWORD *)(a1 + 20); /*0x16f98e*/
  if ( (unsigned int)(v2 - 2000) <= 0x67 && (v3 = (void (__stdcall *)(int, _DWORD *))funcs_16F9B6[v2 - 2000]) != nullptr ) /*0x16f9a5*/
  {
    v3(a1, a2); /*0x16f9b6*/
    return 1; /*0x16f9b8*/
  }
  else
  {
    a2[7] = -303; /*0x16f9a7*/
    return 0; /*0x16f9ae*/
  }
}
