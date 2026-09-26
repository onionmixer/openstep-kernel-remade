/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10c134. */
void tprintf(tpr_t a1, const char *fmt, ...)
{
  tpr_t v2; // ebx
  int v3; // esi
  va_list va; // [esp+18h] [ebp+10h] BYREF

  va_start(va, fmt);
  v2 = a1; /*0x10c139*/
  v3 = 6; /*0x10c13c*/
  sub_10C248(6); /*0x10c143*/
  if ( !a1 ) /*0x10c14d*/
    v2 = (tpr_t)&cons; /*0x10c14f*/
  if ( !ttycheckoutq(v2, 0) ) /*0x10c157*/
    v3 = 4; /*0x10c163*/
  prf(fmt, va, v3, v2); /*0x10c172*/
  logwakeup(); /*0x10c177*/
}
