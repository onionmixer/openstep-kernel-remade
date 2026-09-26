/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15b43c. */
int __cdecl stack_alloc(int a1, int a2)
{
  int *v2; // eax

  v2 = allocStack(); /*0x15b440*/
  if ( !v2 ) /*0x15b449*/
    panic(aStackAlloc); /*0x15b450*/
  return stack_attach(a1, v2, a2); /*0x15b466*/
}
