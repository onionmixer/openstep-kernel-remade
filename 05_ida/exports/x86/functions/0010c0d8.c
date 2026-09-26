/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10c0d8. */
int printf(const char *a1, ...)
{
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, a1);
  if ( prf(a1, va, 5, 0) ) /*0x10c0e7*/
    logwakeup(); /*0x10c0f3*/
  return 0; /*0x10c0fc*/
}
