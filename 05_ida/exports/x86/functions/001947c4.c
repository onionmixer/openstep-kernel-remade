/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1947c4. */
int __cdecl configureThread(int a1)
{
  *(_BYTE *)(a1 + 8) = sub_194140(*(_DWORD *)(a1 + 4)); /*0x1947d4*/
  objc_msgSend(*(id *)a1, sel_lock); /*0x1947e1*/
  objc_msgSend(*(id *)a1, sel_unlockWith_, 1); /*0x1947f2*/
  return IOExitThread(); /*0x1947fc*/
}
