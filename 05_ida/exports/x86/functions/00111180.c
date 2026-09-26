/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x111180. */
_BOOL4 __cdecl ttcheckwakeup(unsigned __int8 *a1)
{
  return (*(_BYTE *)(*(_DWORD *)a1 + 60) & 0x22) == 0 || **(_DWORD **)a1 >= (int)a1[21] || a1[22]; /*0x1111a0*/
}
