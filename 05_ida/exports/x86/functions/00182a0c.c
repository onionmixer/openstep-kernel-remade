/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x182a0c. */
int __cdecl driverServer_server(int a1, _DWORD *a2)
{
  int v2; // ecx
  void (__stdcall *v3)(int, _DWORD *); // eax

  *a2 = *(unsigned __int8 *)(a1 + 1); /*0x182a1b*/
  a2[1] = 32; /*0x182a1d*/
  a2[2] = *(_DWORD *)(a1 + 12); /*0x182a27*/
  a2[3] = 0; /*0x182a2a*/
  a2[4] = 0; /*0x182a31*/
  a2[5] = *(_DWORD *)(a1 + 20) + 100; /*0x182a3e*/
  a2[6] = dword_1E1264; /*0x182a47*/
  v2 = *(_DWORD *)(a1 + 20); /*0x182a4a*/
  if ( (unsigned int)(v2 - 2700) <= 0x26 && (v3 = (void (__stdcall *)(int, _DWORD *))funcs_182A72[v2 - 2700]) != nullptr ) /*0x182a61*/
  {
    v3(a1, a2); /*0x182a72*/
    return 1; /*0x182a74*/
  }
  else
  {
    a2[7] = -303; /*0x182a63*/
    return 0; /*0x182a6a*/
  }
}
