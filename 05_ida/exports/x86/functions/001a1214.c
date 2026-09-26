/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a1214. */
int __cdecl PCcopyBIOSExtData(unsigned int a1)
{
  unsigned __int16 *v1; // edx

  v1 = (unsigned __int16 *)bios_extdata_addr(); /*0x1a1220*/
  if ( !a1 || copyout(v1, a1, 655360 - (_DWORD)v1) ) /*0x1a1230*/
    return 4; /*0x1a1240*/
  else
    return 0; /*0x1a1239*/
}
