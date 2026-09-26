/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18d610. */
void __cdecl sub_18D610(int a1)
{
  int v1; // ebx
  int i; // esi
  size_t v3; // esi
  int v4; // edi
  void *v5; // eax
  int v6; // edx
  unsigned int v7; // ecx
  _BYTE *v8; // eax
  _DWORD *v9; // edx
  int v10; // ecx
  int v11; // ebx
  size_t v12; // [esp+10h] [ebp-1Ch]
  void *__src; // [esp+1Ch] [ebp-10h]
  int v14; // [esp+20h] [ebp-Ch]
  int v15; // [esp+24h] [ebp-8h]
  int *v16; // [esp+28h] [ebp-4h]

  v14 = *(_DWORD *)(a1 + 64); /*0x18d61f*/
  v16 = (int *)(a1 + 28); /*0x18d628*/
  v1 = 0; /*0x18d62b*/
  do /*0x18d648*/
  {
    while ( *(_DWORD *)a1 ) /*0x18d633*/
      ; /*0x18d635*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x18d648*/
  for ( i = *v16; ; i = *(_DWORD *)(v15 + 16) ) /*0x18d64d*/
  {
    v15 = i; /*0x18d7ac*/
    if ( v16 == (int *)i ) /*0x18d7b2*/
      break; /*0x18d7b2*/
    thread_reference(i); /*0x18d658*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x18d665*/
    if ( v1 ) /*0x18d669*/
      thread_deallocate(v1); /*0x18d66c*/
    __src = *(void **)(v14 + 8); /*0x18d67a*/
    v3 = *(_DWORD *)(v14 + 12); /*0x18d680*/
    v4 = *(_DWORD *)(v15 + 40); /*0x18d689*/
    if ( *(_DWORD *)(v4 + 4) < v3 + 105 ) /*0x18d697*/
    {
      v12 = v3 + 105; /*0x18d69d*/
      v5 = (void *)kalloc(v3 + 105); /*0x18d6a1*/
      qmemcpy(v5, *(const void **)v4, 0x68u); /*0x18d6b7*/
      if ( (*(_BYTE *)(v4 + 240) & 4) != 0 ) /*0x18d6c6*/
      {
        v6 = *(_DWORD *)(v4 + 8); /*0x18d6c8*/
        v7 = *(_DWORD *)(v4 + 12); /*0x18d6cb*/
        *(_DWORD *)(v4 + 8) = v5; /*0x18d6d1*/
        *(_DWORD *)(v4 + 12) = v12; /*0x18d6d7*/
        *(_DWORD *)v4 = v5; /*0x18d6da*/
        *(_DWORD *)(v4 + 4) = v12; /*0x18d6df*/
        *(_BYTE *)(v4 + 240) |= 4u; /*0x18d6e2*/
        kfree(v6, v7); /*0x18d6eb*/
      }
      else
      {
        *(_DWORD *)(v4 + 8) = v5; /*0x18d6fe*/
        *(_DWORD *)(v4 + 12) = v12; /*0x18d704*/
        *(_DWORD *)v4 = v5; /*0x18d707*/
        *(_DWORD *)(v4 + 4) = v12; /*0x18d70c*/
        *(_BYTE *)(v4 + 240) |= 4u; /*0x18d70f*/
      }
      if ( active_threads == v15 ) /*0x18d71f*/
      {
        v8 = gdt; /*0x18d721*/
        v9 = *(_DWORD **)(v15 + 40); /*0x18d726*/
        v10 = *v9 - 0x40000000; /*0x18d72b*/
        v11 = v9[1] - 1; /*0x18d734*/
        *((_WORD *)gdt + 13) = *(_WORD *)v9; /*0x18d735*/
        v8[28] = BYTE2(v10); /*0x18d73e*/
        v8[31] = HIBYTE(v10); /*0x18d744*/
        v8[29] = -119; /*0x18d747*/
        v8[30] &= ~0x80u; /*0x18d74b*/
        *((_WORD *)v8 + 12) = v11; /*0x18d74f*/
        v8[30] = BYTE2(v11) & 0xF | v8[30] & 0xF0; /*0x18d763*/
        __asm { ltr word ptr ds:unk_1D14E8 } /*0x18d766*/
      }
    }
    memcpy((void *)(*(unsigned __int16 *)(*(_DWORD *)v4 + 102) + *(_DWORD *)v4), __src, v3); /*0x18d781*/
    v1 = v15; /*0x18d789*/
    do /*0x18d7a4*/
    {
      while ( *(_DWORD *)a1 ) /*0x18d78f*/
        ; /*0x18d791*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x18d7a4*/
  }
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x18d7bd*/
  if ( v1 ) /*0x18d7c1*/
    thread_deallocate(v1); /*0x18d7c4*/
}
