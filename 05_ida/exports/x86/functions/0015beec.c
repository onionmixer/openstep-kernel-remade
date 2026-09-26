/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15beec. */
int __cdecl host_set_time(int a1, int a2, int a3)
{
  int v4; // ebx
  _DWORD *v5; // edx

  if ( !a1 ) /*0x15bef4*/
    return 22; /*0x15bef6*/
  v4 = splhigh(); /*0x15bf05*/
  *(_DWORD *)time = a2; /*0x15bf0d*/
  dword_1DEE3C = a3; /*0x15bf13*/
  v5 = mtime; /*0x15bf19*/
  if ( mtime ) /*0x15bf21*/
  {
    *((_DWORD *)mtime + 2) = *(_DWORD *)time; /*0x15bf29*/
    v5[1] = dword_1DEE3C; /*0x15bf32*/
    *v5 = *(_DWORD *)time; /*0x15bf3b*/
  }
  set_calendar_time_value(time); /*0x15bf42*/
  splx(v4); /*0x15bf48*/
  return 0; /*0x15bf4f*/
}
