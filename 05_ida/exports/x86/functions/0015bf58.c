/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15bf58. */
int __cdecl host_adjust_time(int a1, int a2, int a3, int *a4)
{
  unsigned int v5; // ebx
  int v6; // esi
  int v7; // [esp+14h] [ebp-8h]
  int v8; // [esp+18h] [ebp-4h]

  if ( !a1 ) /*0x15bf6b*/
    return 22; /*0x15bf6d*/
  v5 = a3 + 1000000 * a2; /*0x15bf94*/
  v6 = splhigh(); /*0x15bf9b*/
  v7 = timedelta / 1000000; /*0x15bfad*/
  v8 = timedelta % 1000000; /*0x15bfb0*/
  if ( !timedelta ) /*0x15bfb5*/
  {
    if ( bigadj >= v5 ) /*0x15bfbd*/
      tickdelta = tickadj; /*0x15bfd9*/
    else
      tickdelta = 10 * tickadj; /*0x15bfca*/
  }
  if ( v5 % tickdelta ) /*0x15bfee*/
    v5 = tickdelta * (v5 / tickdelta); /*0x15bff9*/
  timedelta = v5; /*0x15bffd*/
  splx(v6); /*0x15c004*/
  *a4 = v7; /*0x15c00f*/
  a4[1] = v8; /*0x15c014*/
  return 0; /*0x15c01c*/
}
