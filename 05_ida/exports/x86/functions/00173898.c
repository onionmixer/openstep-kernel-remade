/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x173898. */
int __cdecl vm_fault_wire_fast(int a1, int a2, int a3)
{
  int v4; // edi
  int v5; // esi
  volatile __int32 *v6; // edx
  int v7; // eax
  int v8; // esi
  char v9; // al
  volatile __int32 *v10; // edx
  char v11; // al
  int v12; // [esp+10h] [ebp-4h]

  ++dword_1F6514; /*0x1738a4*/
  if ( (*(_BYTE *)(a3 + 24) & 5) != 0 ) /*0x1738ae*/
    return 5; /*0x1738b5*/
  v4 = *(_DWORD *)(a3 + 16); /*0x1738bc*/
  v5 = *(_DWORD *)(a3 + 20) + a2 - *(_DWORD *)(a3 + 8); /*0x1738c7*/
  v12 = *(_DWORD *)(a3 + 28); /*0x1738cd*/
  v6 = (volatile __int32 *)(v4 + 16); /*0x1738d0*/
  do /*0x1738e6*/
  {
    while ( *v6 ) /*0x1738d4*/
      ; /*0x1738d6*/
  }
  while ( _InterlockedExchange(v6, 1) == 1 ); /*0x1738e6*/
  ++*(_WORD *)(v4 + 24); /*0x1738e8*/
  ++*(_WORD *)(v4 + 68); /*0x1738ec*/
  v7 = vm_page_lookup(v4, v5); /*0x1738f2*/
  v8 = v7; /*0x1738f7*/
  if ( !v7 || (*(_BYTE *)(v7 + 32) & 0x21) != 0 || (v12 & *(_DWORD *)(v7 + 40)) != 0 ) /*0x17390c*/
  {
    --*(_WORD *)(v4 + 68); /*0x17390e*/
    _InterlockedExchange((volatile __int32 *)(v4 + 16), 0); /*0x173914*/
    vm_object_deallocate(v4); /*0x173918*/
    return 5; /*0x173922*/
  }
  do /*0x173941*/
  {
    while ( vm_page_queue_lock ) /*0x17392f*/
      ; /*0x17392d*/
  }
  while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x173941*/
  vm_page_wire(v7); /*0x173944*/
  _InterlockedExchange(&vm_page_queue_lock, 0); /*0x17394e*/
  v9 = *(_BYTE *)(v8 + 32) | 1; /*0x173957*/
  *(_BYTE *)(v8 + 32) = *(_BYTE *)(v8 + 32) & 0xDE | 1; /*0x17395e*/
  if ( !*(_DWORD *)(v4 + 28) ) /*0x173965*/
    goto LABEL_20; /*0x173965*/
  if ( (v12 & 2) == 0 ) /*0x17396d*/
  {
    *(_BYTE *)(v8 + 33) |= 4u; /*0x17396f*/
LABEL_20:
    if ( (v12 & 2) != 0 ) /*0x1739e6*/
      *(_BYTE *)(v8 + 33) &= ~4u; /*0x1739e8*/
    _InterlockedExchange((volatile __int32 *)(v4 + 16), 0); /*0x1739f4*/
    pmap_enter(*(_DWORD *)(a1 + 36), a2, *(_DWORD *)(v8 + 36), v12, 1); /*0x173a0c*/
    v10 = (volatile __int32 *)(v4 + 16); /*0x173a11*/
    do /*0x173a2a*/
    {
      while ( *v10 ) /*0x173a18*/
        ; /*0x173a1a*/
    }
    while ( _InterlockedExchange(v10, 1) == 1 ); /*0x173a2a*/
    v11 = *(_BYTE *)(v8 + 32); /*0x173a2c*/
    *(_BYTE *)(v8 + 32) = v11 & 0xFE; /*0x173a34*/
    if ( (v11 & 2) != 0 ) /*0x173a39*/
    {
      *(_BYTE *)(v8 + 32) = v11 & 0xFC; /*0x173a3d*/
      thread_wakeup_prim(v8, 0, 0); /*0x173a45*/
    }
    --*(_WORD *)(v4 + 68); /*0x173a4d*/
    _InterlockedExchange((volatile __int32 *)(v4 + 16), 0); /*0x173a53*/
    vm_object_deallocate(v4); /*0x173a57*/
    return 0; /*0x173a5c*/
  }
  *(_BYTE *)(v8 + 32) = v9 & 0xDE; /*0x17397d*/
  if ( (v9 & 2) != 0 ) /*0x173982*/
  {
    *(_BYTE *)(v8 + 32) = v9 & 0xDC; /*0x173986*/
    thread_wakeup_prim(v8, 0, 0); /*0x17398e*/
  }
  do /*0x1739b1*/
  {
    while ( vm_page_queue_lock ) /*0x17399f*/
      ; /*0x17399d*/
  }
  while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x1739b1*/
  vm_page_unwire(v8); /*0x1739b4*/
  _InterlockedExchange(&vm_page_queue_lock, 0); /*0x1739be*/
  --*(_WORD *)(v4 + 68); /*0x1739c4*/
  _InterlockedExchange((volatile __int32 *)(v4 + 16), 0); /*0x1739ca*/
  vm_object_deallocate(v4); /*0x1739ce*/
  return 5; /*0x173a61*/
}
