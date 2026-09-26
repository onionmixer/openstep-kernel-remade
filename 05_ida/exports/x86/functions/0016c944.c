/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16c944. */
int __cdecl kern_serv_version(int a1, int a2)
{
  if ( a2 <= 1 ) /*0x16c952*/
    return 103; /*0x16c960*/
  *(_DWORD *)(*(_DWORD *)a1 + 1224) = a2; /*0x16c954*/
  return 0; /*0x16c95e*/
}
