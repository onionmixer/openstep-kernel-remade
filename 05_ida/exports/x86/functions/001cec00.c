/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cec00. */
id __cdecl objc_msgSendv(id self, SEL op, size_t arg_size, marg_list arg_frame)
{
  signed __int32 v4; // ecx
  bool v5; // cc
  int v7; // [esp-4h] [ebp-4h]

  v4 = (arg_size >> 2) - 2; /*0x1cec0f*/
  if ( arg_size >> 2 > 2 ) /*0x1cec12*/
  {
    do /*0x1cec1a*/
    {
      v5 = v4-- <= 1; /*0x1cec14*/
      v7 = *((_DWORD *)arg_frame + v4 + 2); /*0x1cec19*/
    }
    while ( !v5 ); /*0x1cec1a*/
  }
  return objc_msgSend(self, op, v7); /*0x1cec2b*/
}
