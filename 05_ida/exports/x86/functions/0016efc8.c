/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16efc8. */
int __cdecl mach_port_server(int a1, _DWORD *a2)
{
  int v2; // ecx
  int (__cdecl *v3)(int, int); // eax

  *a2 = *(unsigned __int8 *)(a1 + 1); /*0x16efd7*/
  a2[1] = 32; /*0x16efd9*/
  a2[2] = *(_DWORD *)(a1 + 12); /*0x16efe3*/
  a2[3] = 0; /*0x16efe6*/
  a2[4] = 0; /*0x16efed*/
  a2[5] = *(_DWORD *)(a1 + 20) + 100; /*0x16effa*/
  a2[6] = dword_1E0380; /*0x16f003*/
  v2 = *(_DWORD *)(a1 + 20); /*0x16f006*/
  if ( (unsigned int)(v2 - 3200) <= 0x12 && (v3 = funcs_16F02E[v2 - 3200]) != nullptr ) /*0x16f01d*/
  {
    v3(a1, (int)a2); /*0x16f02e*/
    return 1; /*0x16f030*/
  }
  else
  {
    a2[7] = -303; /*0x16f01f*/
    return 0; /*0x16f026*/
  }
}
