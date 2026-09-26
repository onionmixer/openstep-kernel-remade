/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e914. */
void __cdecl sub_16E914(int *a1, int a2)
{
  host_t v2; // eax
  kern_return_t v3; // eax

  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16e927*/
  {
    v2 = convert_port_to_host(a1[2]); /*0x16e93c*/
    v3 = host_kernel_version(v2, (char *)(a2 + 44)); /*0x16e945*/
    *(_DWORD *)(a2 + 28) = v3; /*0x16e94a*/
    if ( !v3 ) /*0x16e94f*/
    {
      *(_DWORD *)(a2 + 4) = 556; /*0x16e951*/
      *(_DWORD *)(a2 + 32) = dword_1E015C; /*0x16e95e*/
      *(_DWORD *)(a2 + 36) = dword_1E0160; /*0x16e967*/
      *(_DWORD *)(a2 + 40) = dword_1E0164; /*0x16e970*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16e929*/
  }
}
