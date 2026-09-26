/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5514. */
int IOLog(int a1, ...)
{
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, a1);
  return vlog(3, a1, (int)va); /*0x1a5528*/
}
