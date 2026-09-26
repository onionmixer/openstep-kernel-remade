/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17369c. */
int __cdecl vm_fault_copy_entry(int a1, int a2, _DWORD *a3, int a4)
{
  int result; // eax
  int v5; // edi
  int v6; // esi
  volatile __int32 *v7; // edx
  volatile __int32 *v8; // edx
  int v9; // eax
  volatile __int32 *v10; // edx
  char v11; // al
  volatile __int32 *v12; // [esp+10h] [ebp-18h]
  unsigned int v13; // [esp+14h] [ebp-14h]
  int v14; // [esp+18h] [ebp-10h]
  int v15; // [esp+1Ch] [ebp-Ch]
  int v16; // [esp+20h] [ebp-8h]
  int v17; // [esp+24h] [ebp-4h]

  v17 = *(_DWORD *)(a4 + 16); /*0x1736ab*/
  v15 = *(_DWORD *)(a4 + 20); /*0x1736b1*/
  result = vm_object_allocate(a3[3] - a3[2]); /*0x1736be*/
  v5 = result; /*0x1736c3*/
  a3[4] = result; /*0x1736c8*/
  a3[5] = 0; /*0x1736cb*/
  v14 = a3[8]; /*0x1736d5*/
  v13 = a3[2]; /*0x1736db*/
  v16 = 0; /*0x1736de*/
  if ( a3[3] > v13 ) /*0x1736ee*/
  {
    v12 = (volatile __int32 *)(result + 16); /*0x1736f7*/
    do /*0x173886*/
    {
      do /*0x173714*/
      {
        while ( *v12 ) /*0x1736ff*/
          ; /*0x173701*/
      }
      while ( _InterlockedExchange(v12, 1) == 1 ); /*0x173714*/
      while ( 1 ) /*0x173724*/
      {
        v6 = vm_page_alloc_sequential(v5, v16, 1); /*0x173724*/
        if ( v6 ) /*0x17372b*/
          break; /*0x17372b*/
        _InterlockedExchange((volatile __int32 *)(v5 + 16), 0); /*0x17372f*/
        do /*0x17374d*/
        {
          while ( vm_pages_needed_lock ) /*0x17373b*/
            ; /*0x173739*/
        }
        while ( _InterlockedExchange(&vm_pages_needed_lock, 1) == 1 ); /*0x17374d*/
        thread_wakeup_prim((int)&vm_pages_needed, 0, 0); /*0x173758*/
        thread_sleep((int)&vm_page_free_count, &vm_pages_needed_lock, 0); /*0x173769*/
        v7 = (volatile __int32 *)(v5 + 16); /*0x17376e*/
        do /*0x173786*/
        {
          while ( *v7 ) /*0x173774*/
            ; /*0x173776*/
        }
        while ( _InterlockedExchange(v7, 1) == 1 ); /*0x173786*/
      }
      v8 = (volatile __int32 *)(v17 + 16); /*0x17378f*/
      do /*0x1737a6*/
      {
        while ( *v8 ) /*0x173794*/
          ; /*0x173796*/
      }
      while ( _InterlockedExchange(v8, 1) == 1 ); /*0x1737a6*/
      v9 = vm_page_lookup(v17, v15 + v16); /*0x1737b3*/
      if ( !v9 ) /*0x1737bf*/
        panic(aVmFaultCopyWir); /*0x1737c9*/
      vm_page_copy(v9, v6); /*0x1737d6*/
      _InterlockedExchange((volatile __int32 *)(v17 + 16), 0); /*0x1737e3*/
      _InterlockedExchange((volatile __int32 *)(v5 + 16), 0); /*0x1737e8*/
      pmap_enter(*(_DWORD *)(a1 + 36), v13, *(_DWORD *)(v6 + 36), v14, 0); /*0x173800*/
      v10 = (volatile __int32 *)(v5 + 16); /*0x173805*/
      do /*0x17381e*/
      {
        while ( *v10 ) /*0x17380c*/
          ; /*0x17380e*/
      }
      while ( _InterlockedExchange(v10, 1) == 1 ); /*0x17381e*/
      do /*0x173839*/
      {
        while ( vm_page_queue_lock ) /*0x173827*/
          ; /*0x173825*/
      }
      while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x173839*/
      vm_page_activate(v6); /*0x17383c*/
      _InterlockedExchange(&vm_page_queue_lock, 0); /*0x173846*/
      v11 = *(_BYTE *)(v6 + 32); /*0x17384c*/
      *(_BYTE *)(v6 + 32) = v11 & 0xFE; /*0x173854*/
      if ( (v11 & 2) != 0 ) /*0x173859*/
      {
        *(_BYTE *)(v6 + 32) = v11 & 0xFC; /*0x17385d*/
        thread_wakeup_prim(v6, 0, 0); /*0x173865*/
      }
      _InterlockedExchange((volatile __int32 *)(v5 + 16), 0); /*0x17386f*/
      result = page_size; /*0x173872*/
      v13 += page_size; /*0x173877*/
      v16 += page_size; /*0x17387a*/
    }
    while ( a3[3] > v13 ); /*0x173886*/
  }
  return result; /*0x17388f*/
}
