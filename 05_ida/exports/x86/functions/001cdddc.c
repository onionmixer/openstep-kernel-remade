/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cdddc. */
void __cdecl __noreturn _objc_fatal(const char *a1)
{
  printf("objc fatal: %s\n", a1);
  panic("Objective-C fatal"); /*0x1cddf2*/
}
