/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10b600. */
__int32 gethostid(void)
{
  __int32 result; // eax

  result = dword_1E875C; /*0x10b603*/
  *(_DWORD *)(dword_1E875C + 96) = hostid; /*0x10b60e*/
  return result; /*0x10b613*/
}
