/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18d7d4. */
int __cdecl task_map_io_ports(int a1, int a2, int a3, int a4)
{
  int v4; // esi
  void *v6; // ebx
  signed int i; // ebx
  size_t __len; // [esp+Ch] [ebp-8h]
  unsigned int v9; // [esp+10h] [ebp-4h]

  v4 = *(_DWORD *)(a1 + 64); /*0x18d7e0*/
  v9 = a3 + a2; /*0x18d7e9*/
  if ( (unsigned int)(a3 + a2) > 0x10000 ) /*0x18d7f2*/
    return 1; /*0x18d7f4*/
  if ( *(_DWORD *)(a1 + 80) ) /*0x18d803*/
    return 0; /*0x18d809*/
  if ( task_hold(a1) ) /*0x18d814*/
    return 4; /*0x18d820*/
  __len = (v9 + 7) >> 3; /*0x18d835*/
  lock_write(v4 + 16); /*0x18d83c*/
  if ( *(_DWORD *)(v4 + 12) < __len ) /*0x18d84a*/
  {
    v6 = (void *)kalloc(__len); /*0x18d852*/
    memset(v6, 255, __len); /*0x18d85e*/
    memcpy(v6, *(const void **)(v4 + 8), *(_DWORD *)(v4 + 12)); /*0x18d86c*/
    kfree(*(_DWORD *)(v4 + 8), *(_DWORD *)(v4 + 12)); /*0x18d87c*/
    *(_DWORD *)(v4 + 8) = v6; /*0x18d881*/
    *(_DWORD *)(v4 + 12) = __len; /*0x18d887*/
  }
  for ( i = a2; v9 > i; ++i ) /*0x18d893*/
  {
    if ( a4 ) /*0x18d8a0*/
      *(_BYTE *)(i / 8 + *(_DWORD *)(v4 + 8)) |= 1 << (i % 8); /*0x18d8c9*/
    else
      *(_BYTE *)(i / 8 + *(_DWORD *)(v4 + 8)) &= __ROL4__(-2, i % 8); /*0x18d8f9*/
  }
  task_dowait(a1, 1); /*0x18d908*/
  sub_18D610(a1); /*0x18d90e*/
  task_release(a1); /*0x18d914*/
  lock_done(v4 + 16); /*0x18d91d*/
  return 0; /*0x18d927*/
}
