/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x106e0c. */
int __cdecl switch_unix_context(int a1)
{
  int result; // eax

  dword_1E875C = *(_DWORD *)(a1 + 132); /*0x106e18*/
  result = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 56); /*0x106e21*/
  active_u = result; /*0x106e24*/
  return result; /*0x106e2b*/
}
