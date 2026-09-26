/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e6f4. */
void __cdecl sub_16E6F4(int *a1, int a2)
{
  int v2; // ebx

  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16e708*/
  {
    v2 = convert_port_to_thread(a1[2]); /*0x16e71d*/
    *(_DWORD *)(a2 + 28) = thread_assign_default(v2); /*0x16e725*/
    thread_deallocate(v2); /*0x16e729*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16e70a*/
  }
}
