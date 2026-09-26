/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17a0a4. */
void __noreturn vm_pageout()
{
  int v0; // ebx

  v0 = 1; /*0x17a0a9*/
  *(_DWORD *)(active_threads + 120) = 1; /*0x17a0b3*/
  spl0(); /*0x17a0ba*/
  if ( !vm_page_free_min ) /*0x17a0c6*/
  {
    vm_page_free_min = vm_page_free_count / 50; /*0x17a0d5*/
    if ( vm_page_free_count / 50 <= 2 ) /*0x17a0dd*/
      vm_page_free_min = 3; /*0x17a0df*/
    if ( page_size * vm_page_free_min > vm_page_free_min_sanity ) /*0x17a0ff*/
      vm_page_free_min = vm_page_free_min_sanity / page_size; /*0x17a107*/
  }
  if ( !vm_page_free_reserved ) /*0x17a113*/
    vm_page_free_reserved = 3; /*0x17a115*/
  if ( !vm_pageout_free_min ) /*0x17a126*/
  {
    vm_pageout_free_min = vm_page_free_reserved / 2; /*0x17a138*/
    if ( vm_page_free_reserved / 2 > 10 ) /*0x17a140*/
      vm_pageout_free_min = 10; /*0x17a142*/
  }
  if ( !vm_page_free_target ) /*0x17a153*/
    vm_page_free_target = 4 * vm_page_free_min; /*0x17a15e*/
  if ( !vm_page_inactive_target ) /*0x17a16b*/
    vm_page_inactive_target = vm_page_free_count / 3; /*0x17a17a*/
  if ( vm_page_free_target <= vm_page_free_min ) /*0x17a18a*/
    vm_page_free_target = vm_page_free_min + 1; /*0x17a18d*/
  if ( vm_page_inactive_target <= vm_page_free_target ) /*0x17a19d*/
    vm_page_inactive_target = vm_page_free_target + 1; /*0x17a1a0*/
  do /*0x17a1c1*/
  {
    while ( vm_pages_needed_lock ) /*0x17a1af*/
      ; /*0x17a1ad*/
  }
  while ( _InterlockedExchange(&vm_pages_needed_lock, 1) == 1 ); /*0x17a1c1*/
  while ( 1 ) /*0x17a1c4*/
  {
    if ( v0 /*0x17a1e8*/
      && (vm_page_free_min >= vm_page_free_count
       || vm_page_free_target > vm_page_free_count && vm_page_inactive_count <= vm_page_inactive_target) )
    {
      _InterlockedExchange(&vm_pages_needed_lock, 0); /*0x17a202*/
    }
    else
    {
      thread_sleep((int)&vm_pages_needed, &vm_pages_needed_lock, 0); /*0x17a1f6*/
    }
    v0 = vm_pageout_scan(); /*0x17a20d*/
    do /*0x17a229*/
    {
      while ( vm_pages_needed_lock ) /*0x17a217*/
        ; /*0x17a215*/
    }
    while ( _InterlockedExchange(&vm_pages_needed_lock, 1) == 1 ); /*0x17a229*/
    thread_wakeup_prim((int)&vm_page_free_count, 0, 0); /*0x17a234*/
  }
}
