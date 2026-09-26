/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120bc0. */
int __cdecl if_control(int a1, int a2, int a3)
{
  int (__stdcall *v3)(int, int, int); // eax

  v3 = *(int (__stdcall **)(int, int, int))(a1 + 56); /*0x120bc6*/
  if ( v3 ) /*0x120bcb*/
    return v3(a1, a2, a3); /*0x120bd6*/
  else
    return 6; /*0x120bdc*/
}
