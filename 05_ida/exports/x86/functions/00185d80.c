/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x185d80. */
void __cdecl __noreturn kdp_panic(const char *a1)
{
  safe_prf("kdp panic: %s\n", a1);
  __halt(); /*0x185d91*/
}
