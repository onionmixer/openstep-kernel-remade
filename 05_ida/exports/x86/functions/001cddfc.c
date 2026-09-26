/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cddfc. */
void _objc_inform(const char *a1, ...)
{
  long double v1; // [esp-8h] [ebp-10h]
  va_list va; // [esp+14h] [ebp+Ch] BYREF

  va_start(va, a1);
  vlog(3, (int)a1, (int)va); /*0x1cde0b*/
  if ( a1[strlen(a1) - 1] != 10 ) /*0x1cde28*/
  {
    DWORD1(v1) = "\n"; /*0x1cde2a*/
    LODWORD(v1) = 3; /*0x1cde2f*/
    log(v1); /*0x1cde31*/
  }
}
