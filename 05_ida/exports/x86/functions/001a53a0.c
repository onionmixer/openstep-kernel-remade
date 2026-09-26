/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a53a0. */
void __cdecl +[IOConfigTable freeString:](id a1, SEL a2, const char *a3)
{
  IOFree(a3, strlen(a3) + 1); /*0x1a53b9*/
}
