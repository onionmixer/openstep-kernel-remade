/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c024. */
int mach_clock_bootstrap()
{
  int v0; // ebx
  _DWORD *v1; // eax

  if ( kmem_alloc_wired(kernel_map, &mtime, page_size) ) /*0x15c03b*/
    panic(aMappableTimeIn); /*0x15c04c*/
  bzero(mtime, page_size); /*0x15c062*/
  v0 = splhigh(); /*0x15c06c*/
  get_calendar_time_value(time); /*0x15c073*/
  v1 = mtime; /*0x15c07b*/
  if ( mtime ) /*0x15c082*/
  {
    *((_DWORD *)mtime + 2) = *(_DWORD *)time; /*0x15c08a*/
    v1[1] = dword_1DEE3C; /*0x15c093*/
    *v1 = *(_DWORD *)time; /*0x15c09c*/
  }
  return splx(v0); /*0x15c0a4*/
}
