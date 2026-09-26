/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10c100. */
int uprintf(const char *a1, ...)
{
  int result; // eax
  int v2; // ebx
  va_list va; // [esp+10h] [ebp+Ch] BYREF

  va_start(va, a1);
  result = active_u; /*0x10c104*/
  v2 = *(_DWORD *)(active_u + 360); /*0x10c109*/
  if ( v2 ) /*0x10c111*/
  {
    ttycheckoutq(v2, 1); /*0x10c116*/
    prf(a1, va, 2, v2); /*0x10c126*/
    return 0; /*0x10c12b*/
  }
  return result; /*0x10c12d*/
}
