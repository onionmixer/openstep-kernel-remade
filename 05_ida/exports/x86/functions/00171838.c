/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x171838. */
int __cdecl mach_debug_server(int a1, _DWORD *a2)
{
  int v2; // ecx
  void (__cdecl *v3)(int, int, int); // eax
  int v5; // [esp+0h] [ebp-8h]

  *a2 = *(unsigned __int8 *)(a1 + 1); /*0x171847*/
  a2[1] = 32; /*0x171849*/
  a2[2] = *(_DWORD *)(a1 + 12); /*0x171853*/
  a2[3] = 0; /*0x171856*/
  a2[4] = 0; /*0x17185d*/
  a2[5] = *(_DWORD *)(a1 + 20) + 100; /*0x17186a*/
  a2[6] = dword_1E0828; /*0x171873*/
  v2 = *(_DWORD *)(a1 + 20); /*0x171876*/
  if ( (unsigned int)(v2 - 3000) <= 0x15 && (v3 = (void (__cdecl *)(int, int, int))funcs_17189E[v2 - 3000]) != nullptr ) /*0x17188d*/
  {
    v3(a1, (int)a2, v5); /*0x17189e*/
    return 1; /*0x1718a0*/
  }
  else
  {
    a2[7] = -303; /*0x17188f*/
    return 0; /*0x171896*/
  }
}
