/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10d7b0. */
int __cdecl selthreadclear(_DWORD *a1)
{
  int result; // eax

  if ( !a1 ) /*0x10d7b9*/
    panic(aSelthreadclear); /*0x10d7c0*/
  result = *a1; /*0x10d7c8*/
  if ( *a1 ) /*0x10d7c8*/
    result = thread_deallocate_interrupt(*a1); /*0x10d7cf*/
  *a1 = 0; /*0x10d7d4*/
  return result; /*0x10d7da*/
}
