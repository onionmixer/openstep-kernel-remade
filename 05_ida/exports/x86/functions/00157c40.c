/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157c40. */
int ipc_host_init()
{
  _DWORD *v0; // eax
  int v1; // ebx
  _DWORD *v2; // eax
  int v3; // ebx

  v0 = ipc_port_alloc_special(ipc_space_kernel); /*0x157c4b*/
  v1 = (int)v0; /*0x157c50*/
  if ( !v0 ) /*0x157c57*/
    panic(aIpcHostInit); /*0x157c5e*/
  ipc_kobject_set(v0, &realhost, 3); /*0x157c6e*/
  realhost = v1; /*0x157c73*/
  v2 = ipc_port_alloc_special(ipc_space_kernel); /*0x157c80*/
  v3 = (int)v2; /*0x157c85*/
  if ( !v2 ) /*0x157c8c*/
    panic(aIpcHostInit_0); /*0x157c93*/
  ipc_kobject_set(v2, &realhost, 4); /*0x157ca3*/
  dword_1E97B4 = v3; /*0x157ca8*/
  ipc_pset_init(&default_pset); /*0x157cb3*/
  ipc_pset_enable(&default_pset); /*0x157cbd*/
  return ipc_processor_init(master_processor); /*0x157cce*/
}
