/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16c96c. */
int __cdecl kern_serv_load_objc(int a1, mach_header *mhp)
{
  *(_DWORD *)(*(_DWORD *)a1 + 1232) = mhp; /*0x16c977*/
  objc_registerModule(mhp, 0); /*0x16c980*/
  return 0; /*0x16c989*/
}
