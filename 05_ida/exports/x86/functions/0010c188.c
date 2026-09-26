/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10c188. */
int sprintf(char *a1, const char *a2, ...)
{
  char *v3; // [esp+4h] [ebp-4h] BYREF
  va_list va; // [esp+18h] [ebp+10h] BYREF

  va_start(va, a2);
  v3 = a1; /*0x10c192*/
  prf(a2, va, 8, &v3); /*0x10c1a3*/
  *v3 = 0; /*0x10c1ab*/
  return v3 + 1 - a1; /*0x10c1b6*/
}
