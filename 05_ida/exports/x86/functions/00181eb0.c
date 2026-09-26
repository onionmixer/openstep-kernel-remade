/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181eb0. */
int __cdecl kern_IOSetCharValues(int a1, int a2, int a3, int a4, int a5)
{
  if ( a1 ) /*0x181eb7*/
    return +[IODevice setCharValues:forParameter:objectNumber:count:]( /*0x181ed7*/
             aIodevice_0,
             sel_setCharValues_forParameter_objectNumber_count_,
             a4,
             a3,
             a2,
             a5);
  else
    return -705; /*0x181ee0*/
}
