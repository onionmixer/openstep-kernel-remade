/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16cc64. */
int __cdecl kern_serv_call_proc(int a1, void (__stdcall *a2)(int), int a3)
{
  if ( !a2 ) /*0x16cc6c*/
    return 100; /*0x16cc7c*/
  a2(a3); /*0x16cc72*/
  return 0; /*0x16cc78*/
}
