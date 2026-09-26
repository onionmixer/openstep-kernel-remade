/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18e85c. */
int __cdecl get_thread_fpstate(unsigned __int32 a1, int a2, _DWORD *a3)
{
  int v3; // ebx

  if ( *a3 <= 0x1Au ) /*0x18e86b*/
    return 4; /*0x18e8a8*/
  v3 = *(_DWORD *)(a1 + 40); /*0x18e86d*/
  fp_synch(a1); /*0x18e874*/
  qmemcpy((void *)a2, (const void *)(v3 + 124), 0x1Cu); /*0x18e882*/
  qmemcpy((void *)(a2 + 28), (const void *)(v3 + 152), 0x50u); /*0x18e896*/
  *a3 = 27; /*0x18e89b*/
  return 0; /*0x18e8b0*/
}
