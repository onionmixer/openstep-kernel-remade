/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10d740. */
int __cdecl selthreadcache(thread_act_t *a1)
{
  int v1; // eax
  thread_act_t v2; // ebx
  thread_act_t v4; // ebx

  v1 = splhigh(); /*0x10d748*/
  v2 = *a1; /*0x10d74d*/
  if ( *a1 ) /*0x10d74d*/
  {
    if ( *(_DWORD *)(v2 + 376) && *(_UNKNOWN **)(v2 + 60) == &selwait ) /*0x10d763*/
    {
      splx(v1); /*0x10d766*/
      return 1; /*0x10d770*/
    }
    *a1 = 0; /*0x10d774*/
    splx(v1); /*0x10d77b*/
    thread_deallocate(v2); /*0x10d781*/
  }
  else
  {
    splx(v1); /*0x10d78d*/
  }
  v4 = active_threads; /*0x10d795*/
  thread_reference(active_threads); /*0x10d79c*/
  *a1 = v4; /*0x10d7a1*/
  return 0; /*0x10d7a8*/
}
