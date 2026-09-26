/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18cdf0. */
int nmi_prf(char *a1, ...)
{
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, a1);
  return prf(a1, (int)va, 1, 0); /*0x18ce06*/
}
