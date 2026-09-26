/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120cd8. */
int __cdecl if_getbuf(int a1)
{
  int (__stdcall *v1)(int); // eax

  v1 = *(int (__stdcall **)(int))(a1 + 64); /*0x120cde*/
  if ( v1 ) /*0x120ce3*/
    return v1(a1); /*0x120ce6*/
  else
    return 0; /*0x120cec*/
}
