/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120b98. */
int __cdecl if_output(int a1, int a2, int a3)
{
  int (__stdcall *v3)(int, int, int); // eax

  v3 = *(int (__stdcall **)(int, int, int))(a1 + 52); /*0x120b9e*/
  if ( v3 ) /*0x120ba3*/
    return v3(a1, a2, a3); /*0x120bae*/
  else
    return 6; /*0x120bb4*/
}
