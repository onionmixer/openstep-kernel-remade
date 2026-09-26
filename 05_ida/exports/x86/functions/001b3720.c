/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b3720. */
id EvMapEventShmem()
{
  id v0; // eax

  v0 = +[EventDriver instance](aEventdriver_0, sel_instance); /*0x1b3748*/
  return objc_msgSend(v0, sel_mapEventShmem_task_size_at_); /*0x1b3758*/
}
