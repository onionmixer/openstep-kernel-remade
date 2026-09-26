/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18d930. */
int __cdecl task_locate_ldt(int a1, unsigned int a2, unsigned int a3)
{
  int v3; // edx
  int v5; // ebx
  int i; // esi
  int v7; // eax
  _BYTE *v8; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // ebx
  int *v12; // [esp+Ch] [ebp-Ch]
  _DWORD *v13; // [esp+10h] [ebp-8h]
  unsigned int *v14; // [esp+14h] [ebp-4h]

  v14 = *(unsigned int **)(a1 + 64); /*0x18d945*/
  v3 = *(_DWORD *)(a1 + 12); /*0x18d94b*/
  if ( *(_DWORD *)(v3 + 20) > a2 || *(_DWORD *)(v3 + 24) <= a3 + a2 ) /*0x18d959*/
    return 1; /*0x18d95b*/
  if ( task_hold(a1) ) /*0x18d96c*/
    return 4; /*0x18d978*/
  lock_write((int)(v14 + 4)); /*0x18d98b*/
  *v14 = a2; /*0x18d993*/
  v14[1] = a3; /*0x18d995*/
  task_dowait(a1, 1); /*0x18d99e*/
  v13 = *(_DWORD **)(a1 + 64); /*0x18d9ac*/
  v12 = (int *)(a1 + 28); /*0x18d9b5*/
  v5 = 0; /*0x18d9b8*/
  do /*0x18d9d4*/
  {
    while ( *(_DWORD *)a1 ) /*0x18d9bf*/
      ; /*0x18d9c1*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x18d9d4*/
  for ( i = *v12; v12 != (int *)i; i = *(_DWORD *)(i + 16) ) /*0x18d9dd*/
  {
    thread_reference(i); /*0x18d9e5*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x18d9f2*/
    if ( v5 ) /*0x18d9f6*/
      thread_deallocate(v5); /*0x18d9f9*/
    v7 = v13[1]; /*0x18da04*/
    *(_DWORD *)(*(_DWORD *)(i + 40) + 116) = *v13; /*0x18da0c*/
    *(_DWORD *)(*(_DWORD *)(i + 40) + 120) = v7; /*0x18da12*/
    if ( active_threads == i ) /*0x18da1b*/
    {
      v8 = gdt; /*0x18da1d*/
      v9 = *(_DWORD *)(i + 40); /*0x18da23*/
      v10 = *(_DWORD *)(v9 + 116); /*0x18da26*/
      v11 = *(_DWORD *)(v9 + 120) - 1; /*0x18da2c*/
      *((_WORD *)gdt + 17) = v10; /*0x18da2d*/
      v8[36] = BYTE2(v10); /*0x18da36*/
      v8[39] = HIBYTE(v10); /*0x18da3c*/
      v8[37] = v8[37] & 0x60 | 0x82; /*0x18da46*/
      v8[38] &= ~0x80u; /*0x18da49*/
      *((_WORD *)v8 + 16) = v11; /*0x18da4d*/
      v8[38] = BYTE2(v11) & 0xF | v8[38] & 0xF0; /*0x18da60*/
      __asm { lldt ds:word_1D14EA } /*0x18da63*/
    }
    v5 = i; /*0x18da6a*/
    do /*0x18da84*/
    {
      while ( *(_DWORD *)a1 ) /*0x18da6f*/
        ; /*0x18da71*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x18da84*/
  }
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x18da97*/
  if ( v5 ) /*0x18da9b*/
    thread_deallocate(v5); /*0x18da9e*/
  task_release(a1); /*0x18daaa*/
  lock_done((int)(v14 + 4)); /*0x18dab6*/
  return 0; /*0x18dac0*/
}
