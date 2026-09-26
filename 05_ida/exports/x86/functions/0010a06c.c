/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10a06c. */
int __cdecl stop(int a1)
{
  task_suspend_nowait(*(_DWORD *)(a1 + 104)); /*0x10a077*/
  *(_BYTE *)(a1 + 19) = 6; /*0x10a07c*/
  *(_DWORD *)(a1 + 40) &= ~0x20u; /*0x10a080*/
  return wakeup(*(_DWORD *)(a1 + 68)); /*0x10a08d*/
}
