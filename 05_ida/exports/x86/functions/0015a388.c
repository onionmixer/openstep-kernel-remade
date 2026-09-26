/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a388. */
int __cdecl space_deallocate(int a1)
{
  int result; // eax

  result = a1; /*0x15a38b*/
  if ( a1 ) /*0x15a390*/
    return ipc_space_release(a1); /*0x15a393*/
  return result; /*0x15a39a*/
}
