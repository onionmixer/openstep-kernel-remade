/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x102e30. */
int init_task()
{
  unsigned int v0; // ecx
  size_t v1; // edx
  _DWORD *v2; // edi
  int v3; // eax
  int v4; // eax

  v0 = strlen(aInit) + 1; /*0x102e41*/
  v1 = 17; /*0x102e48*/
  if ( v0 - 1 <= 0x10 ) /*0x102e50*/
    v1 = v0; /*0x102e52*/
  bcopy(aInit, (void *)(active_u + 8), v1); /*0x102e63*/
  v2 = (_DWORD *)dword_1E875C; /*0x102e6b*/
  v3 = *(_DWORD *)(*(_DWORD *)(active_threads + 40) + 112); /*0x102e7a*/
  if ( v3 ) /*0x102e7f*/
    v4 = v3 + 132; /*0x102e81*/
  else
    v4 = thread_user_state(active_threads); /*0x102e89*/
  *v2 = v4; /*0x102e91*/
  load_init_program(); /*0x102e93*/
  return thread_exception_return(); /*0x102e9d*/
}
