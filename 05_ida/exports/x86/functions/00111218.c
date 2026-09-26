/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x111218. */
int __cdecl tty_ld_install(
        int a1,
        int (__cdecl *a2)(__int16, FILE *),
        int (__cdecl *a3)(__int16, FILE *),
        int (__cdecl *a4)(__int16, FILE *),
        int (__cdecl *a5)(__int16, FILE *),
        int (__cdecl *a6)(__int16, FILE *),
        int (__cdecl *a7)(__int16, FILE *),
        int (__cdecl *a8)(__int16, FILE *),
        int (__cdecl *a9)(__int16, FILE *),
        int (__cdecl *a10)(__int16, FILE *),
        int (__cdecl *a11)(__int16, FILE *),
        int (__cdecl *a12)(__int16, FILE *))
{
  int v12; // ebx
  int v14; // eax

  if ( a1 < 0 ) /*0x111222*/
    return -1; /*0x111222*/
  if ( nldisp <= a1 ) /*0x11122a*/
    return -1; /*0x11122a*/
  v12 = 48 * a1; /*0x111231*/
  if ( (char *)*(&linesw + 12 * a1) != (char *)nodev /*0x11129d*/
    || (char *)*(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 4) != (char *)nodev
    || (char *)*(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 8) != (char *)nodev
    || (char *)*(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 12) != (char *)nodev
    || (char *)*(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 16) != (char *)nodev
    || (char *)*(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 20) != (char *)nodev
    || (char *)*(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 24) != (char *)nodev
    || (char *)*(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 32) != (char *)nodev
    || (char *)*(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 36) != (char *)nodev
    || (char *)*(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 40) != (char *)nodev )
  {
    return -1; /*0x11129f*/
  }
  v14 = spltty(); /*0x1112a8*/
  *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 44) = a2; /*0x1112b0*/
  *(&linesw + 12 * a1) = a3; /*0x1112b7*/
  *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 4) = a4; /*0x1112c0*/
  *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 8) = a5; /*0x1112c7*/
  *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 12) = a6; /*0x1112ce*/
  *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 16) = a7; /*0x1112d5*/
  *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 20) = a8; /*0x1112dc*/
  *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 24) = a9; /*0x1112e3*/
  *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 32) = a10; /*0x1112ea*/
  *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 36) = a11; /*0x1112f1*/
  *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v12 + 40) = a12; /*0x1112f8*/
  splx(v14); /*0x1112fd*/
  return 0; /*0x111307*/
}
