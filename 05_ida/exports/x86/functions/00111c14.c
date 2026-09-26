/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x111c14. */
__int16 *__cdecl pty_alloc(unsigned __int8 a1)
{
  int v1; // eax
  __int16 *v2; // ebx
  void *v4; // eax
  void *v5; // eax

  v1 = 8 * a1; /*0x111c1c*/
  v2 = &word_1E56C8[v1]; /*0x111c1f*/
  if ( *(_DWORD *)&word_1E56C8[v1 + 4] ) /*0x111c25*/
    return &word_1E56C8[v1]; /*0x111c2b*/
  lock_write((int)&pty_alloc_lock); /*0x111c35*/
  if ( !*((_DWORD *)v2 + 2) ) /*0x111c3d*/
  {
    v4 = (void *)kalloc(0x88u); /*0x111c48*/
    *((_DWORD *)v2 + 2) = v4; /*0x111c4d*/
    bzero(v4, 0x88u); /*0x111c56*/
    v5 = (void *)kalloc(0x10u); /*0x111c5d*/
    *((_DWORD *)v2 + 3) = v5; /*0x111c62*/
    bzero(v5, 0x10u); /*0x111c68*/
  }
  lock_done(&pty_alloc_lock); /*0x111c75*/
  return v2; /*0x111c7c*/
}
