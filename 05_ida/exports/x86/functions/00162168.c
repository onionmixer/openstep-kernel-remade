/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x162168. */
int __cdecl sub_162168(int a1, _DWORD *a2, _WORD *a3)
{
  if ( *a2 <= 7u ) /*0x16217a*/
    return 0; /*0x1621a8*/
  *(_BYTE *)a1 |= 0x80u; /*0x16217c*/
  *(_WORD *)(a1 + 2) = 20; /*0x16217f*/
  kdp_machine_hostinfo(a1 + 8); /*0x162189*/
  *a3 = kdp; /*0x162195*/
  *a2 = *(unsigned __int16 *)(a1 + 2); /*0x16219c*/
  return 1; /*0x1621ad*/
}
