/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x162324. */
int __cdecl sub_162324(int a1, _DWORD *a2, _WORD *a3)
{
  if ( *a2 <= 7u ) /*0x162334*/
    return 0; /*0x162360*/
  *(_BYTE *)a1 |= 0x80u; /*0x162336*/
  *(_WORD *)(a1 + 2) = 12; /*0x162339*/
  *(_DWORD *)(a1 + 8) = 1024; /*0x16233f*/
  *a3 = kdp; /*0x16234d*/
  *a2 = *(unsigned __int16 *)(a1 + 2); /*0x162354*/
  return 1; /*0x162362*/
}
