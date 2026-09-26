/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1553fc. */
int __cdecl old_mach_port_get_receive_status(int a1, int a2, _DWORD *a3)
{
  int result; // eax
  _DWORD v4[9]; // [esp+4h] [ebp-24h] BYREF

  result = mach_port_get_receive_status(a1, a2, v4); /*0x155412*/
  if ( !result ) /*0x155419*/
  {
    *a3 = v4[0]; /*0x15541e*/
    a3[1] = v4[2]; /*0x155423*/
    a3[2] = v4[3]; /*0x155429*/
    a3[3] = v4[4]; /*0x15542f*/
    a3[4] = v4[5]; /*0x155435*/
    a3[5] = v4[6]; /*0x15543b*/
    a3[6] = v4[7]; /*0x155441*/
    a3[7] = v4[8]; /*0x155447*/
    return 0; /*0x15544a*/
  }
  return result; /*0x15544c*/
}
