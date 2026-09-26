/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cdd80. */
void __cdecl __noreturn _objc_error(id a1, const char *a2, int a3)
{
  long double v3; // [esp-10h] [ebp-1Ch]
  long double v4; // [esp-8h] [ebp-14h]

  DWORD2(v3) = object_getClassName(a1); /*0x1cdd95*/
  DWORD1(v3) = "objc error: %s ";
  LODWORD(v3) = 3; /*0x1cdd9b*/
  log(v3); /*0x1cdd9d*/
  vlog(3, (int)a2, a3); /*0x1cdda6*/
  if ( a2[strlen(a2) - 1] != 10 ) /*0x1cddc3*/
  {
    DWORD1(v4) = "\n"; /*0x1cddc5*/
    LODWORD(v4) = 3; /*0x1cddca*/
    log(v4); /*0x1cddcc*/
  }
  abort(); /*0x1cddd4*/
}
