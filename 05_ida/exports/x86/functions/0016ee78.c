/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16ee78. */
void __cdecl sub_16EE78(int *a1, int a2)
{
  int v2; // ebx

  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16ee8c*/
  {
    v2 = convert_port_to_thread(a1[2]); /*0x16eea1*/
    *(_DWORD *)(a2 + 28) = thread_depress_abort(v2); /*0x16eea9*/
    thread_deallocate(v2); /*0x16eead*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16ee8e*/
  }
}
