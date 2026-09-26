/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1639ec. */
int __cdecl thread_continue(int a1)
{
  int (*v1)(void); // ebx

  v1 = *(int (**)(void))(active_threads + 52); /*0x1639f8*/
  if ( a1 ) /*0x1639fd*/
    thread_dispatch(a1); /*0x163a00*/
  spl0(); /*0x163a08*/
  return v1(); /*0x163a0f*/
}
