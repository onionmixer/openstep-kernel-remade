/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cdd10. */
void __noreturn __objc_error(id a1, const char *a2, ...)
{
  va_list va; // [esp+1Ch] [ebp+10h] BYREF

  va_start(va, a2);
  _error(a1, a2, va); /*0x1cdd27*/
}
