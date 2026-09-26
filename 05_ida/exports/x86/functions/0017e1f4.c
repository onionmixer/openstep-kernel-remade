/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e1f4. */
int NXPrintf(int a1, int a2, ...)
{
  int v2; // esi
  va_list va; // [esp+18h] [ebp+10h] BYREF

  va_start(va, a2);
  v2 = splhigh(); /*0x17e201*/
  vlog(3, a2, (int)va); /*0x17e20a*/
  return splx(v2); /*0x17e218*/
}
