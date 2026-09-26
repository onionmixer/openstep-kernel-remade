/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181e74. */
int __cdecl kern_IOSetIntValues(int a1, int a2, int a3, int a4, int a5)
{
  if ( a1 ) /*0x181e7b*/
    return +[IODevice setIntValues:forParameter:objectNumber:count:]( /*0x181e9b*/
             aIodevice_0,
             sel_setIntValues_forParameter_objectNumber_count_,
             a4,
             a3,
             a2,
             a5);
  else
    return -705; /*0x181ea4*/
}
