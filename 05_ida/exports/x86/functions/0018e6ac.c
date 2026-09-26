/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18e6ac. */
int __cdecl thread_getstatus(int a1, int a2, int a3, int a4)
{
  int result; // eax

  switch ( a2 ) /*0x18e6c4*/
  {
    case -4: /*0x18e6c4*/
      result = get_thread_cthreadstate(a1, a3, a4); /*0x18e707*/
      break; /*0x18e70c*/
    case -3: /*0x18e6c4*/
      result = get_thread_exceptstate(a1, a3, a4); /*0x18e6fb*/
      break; /*0x18e700*/
    case -2: /*0x18e6c4*/
      result = get_thread_fpstate(a1, a3, a4); /*0x18e6ef*/
      break; /*0x18e6f4*/
    case -1: /*0x18e6c4*/
      result = get_thread_state(a1, a3, a4); /*0x18e6e3*/
      break; /*0x18e6e8*/
    case 0: /*0x18e6c4*/
      result = get_thread_state_flavor_list(a3, a4); /*0x18e712*/
      break; /*0x18e717*/
    default:
      result = 4; /*0x18e71c*/
      break; /*0x18e71c*/
  }
  return result; /*0x18e721*/
}
