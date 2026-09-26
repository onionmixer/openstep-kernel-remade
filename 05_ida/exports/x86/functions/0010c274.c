/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10c274. */
int _printf(int a1, int a2, int a3, ...)
{
  va_list va; // [esp+14h] [ebp+14h] BYREF

  va_start(va, a3);
  return prf(a3, va, a1, a2); /*0x10c28e*/
}
