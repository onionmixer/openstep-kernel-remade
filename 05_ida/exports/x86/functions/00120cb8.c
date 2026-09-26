/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120cb8. */
int __cdecl if_init(int a1)
{
  int (__stdcall *v1)(int); // eax

  v1 = *(int (__stdcall **)(int))(a1 + 48); /*0x120cbe*/
  if ( v1 ) /*0x120cc3*/
    return v1(a1); /*0x120cc6*/
  else
    return 6; /*0x120ccc*/
}
