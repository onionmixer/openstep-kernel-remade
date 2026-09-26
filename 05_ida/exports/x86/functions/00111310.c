/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x111310. */
void __cdecl tty_ld_remove(int a1)
{
  int v1; // ecx
  int v2; // eax

  if ( a1 >= 0 && nldisp > a1 ) /*0x111321*/
  {
    v1 = spltty(); /*0x111328*/
    v2 = 48 * a1; /*0x11132d*/
    *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v2) = (int (__cdecl *)(__int16, FILE *))nodev; /*0x111335*/
    *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v2 + 4) = (int (__cdecl *)(__int16, FILE *))nodev; /*0x11133f*/
    *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v2 + 8) = (int (__cdecl *)(__int16, FILE *))nodev; /*0x111347*/
    *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v2 + 12) = (int (__cdecl *)(__int16, FILE *))nodev; /*0x11134f*/
    *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v2 + 16) = (int (__cdecl *)(__int16, FILE *))nodev; /*0x111357*/
    *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v2 + 20) = (int (__cdecl *)(__int16, FILE *))nodev; /*0x11135f*/
    *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v2 + 24) = (int (__cdecl *)(__int16, FILE *))nodev; /*0x111367*/
    *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v2 + 32) = (int (__cdecl *)(__int16, FILE *))nodev; /*0x11136f*/
    *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v2 + 36) = (int (__cdecl *)(__int16, FILE *))nodev; /*0x111377*/
    *(int (__cdecl **)(__int16, FILE *))((char *)&linesw + v2 + 40) = (int (__cdecl *)(__int16, FILE *))nodev; /*0x11137f*/
    splx(v1); /*0x111388*/
  }
}
