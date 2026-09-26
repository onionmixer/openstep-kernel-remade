/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16cc88. */
void __cdecl __noreturn kern_serv_shutdown(int a1)
{
  _DWORD *v1; // esi
  mach_header *v2; // eax
  int v3; // edi
  int i; // ebx

  v1 = *(_DWORD **)a1; /*0x16cc91*/
  v2 = *(mach_header **)(*(_DWORD *)a1 + 1232); /*0x16cc93*/
  if ( v2 ) /*0x16cc9b*/
    objc_unregisterModule(v2, 0); /*0x16cca0*/
  if ( v1[12] ) /*0x16cca8*/
  {
    sub_16D054(v1 + 9); /*0x16ccb2*/
    v1[12] = 0; /*0x16ccb7*/
  }
  v3 = 0; /*0x16ccc1*/
  for ( i = 0; ; i += 4 ) /*0x16ccc3*/
  {
    if ( v1[i + 99] ) /*0x16ccc8*/
    {
      port_deallocate_EXTERNAL(v1[2], v1[i + 99]); /*0x16ccd8*/
      v1[i + 99] = 0; /*0x16ccdd*/
      v1[i + 100] = 0; /*0x16cce8*/
    }
    if ( ++v3 > 49 ) /*0x16ccfd*/
    {
      port_deallocate_EXTERNAL(v1[2], v1[5]); /*0x16cd07*/
      port_deallocate_EXTERNAL(v1[2], v1[7]); /*0x16cd14*/
      port_set_deallocate_EXTERNAL(v1[2], v1[8]); /*0x16cd21*/
      kfree(v1[17], v1[18]); /*0x16cd2e*/
      kfree((int)v1, 0x4D4u); /*0x16cd3c*/
      thread_terminate(active_threads); /*0x16cd48*/
      while ( 1 ) /*0x16cd50*/
        thread_halt_self(); /*0x16cd50*/
    }
  }
}
