/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18dac8. */
int __cdecl task_default_ldt(int a1)
{
  int v2; // edx
  int v3; // eax
  _BYTE *v4; // ecx
  int v5; // eax
  int v6; // edx
  int v7; // [esp+Ch] [ebp-18h]
  int v8; // [esp+10h] [ebp-14h]
  int i; // [esp+14h] [ebp-10h]
  int *v10; // [esp+18h] [ebp-Ch]
  _DWORD *v11; // [esp+1Ch] [ebp-8h]
  _DWORD *v12; // [esp+20h] [ebp-4h]

  v12 = *(_DWORD **)(a1 + 64); /*0x18dad7*/
  if ( task_hold(a1) ) /*0x18dadb*/
    return 4; /*0x18dae7*/
  lock_write((int)(v12 + 4)); /*0x18dafb*/
  *v12 = (char *)ldt - 0x40000000; /*0x18db0f*/
  v12[1] = 24; /*0x18db11*/
  task_dowait(a1, 1); /*0x18db1b*/
  v11 = *(_DWORD **)(a1 + 64); /*0x18db26*/
  v10 = (int *)(a1 + 28); /*0x18db2c*/
  v2 = 0; /*0x18db2f*/
  do /*0x18db46*/
  {
    while ( *(_DWORD *)a1 ) /*0x18db34*/
      ; /*0x18db36*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x18db46*/
  for ( i = *v10; v10 != (int *)i; i = *(_DWORD *)(i + 16) ) /*0x18db53*/
  {
    v8 = v2; /*0x18db60*/
    thread_reference(i); /*0x18db63*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x18db6d*/
    if ( v8 ) /*0x18db74*/
      thread_deallocate(v8); /*0x18db77*/
    v3 = v11[1]; /*0x18db82*/
    *(_DWORD *)(*(_DWORD *)(i + 40) + 116) = *v11; /*0x18db8d*/
    *(_DWORD *)(*(_DWORD *)(i + 40) + 120) = v3; /*0x18db93*/
    if ( active_threads == i ) /*0x18db9c*/
    {
      v4 = gdt; /*0x18db9e*/
      v5 = *(_DWORD *)(i + 40); /*0x18dba4*/
      v6 = *(_DWORD *)(v5 + 116); /*0x18dba7*/
      v7 = *(_DWORD *)(v5 + 120) - 1; /*0x18dbae*/
      *((_WORD *)gdt + 17) = v6; /*0x18dbb1*/
      v4[36] = BYTE2(v6); /*0x18dbba*/
      v4[39] = HIBYTE(v6); /*0x18dbc0*/
      v4[37] = v4[37] & 0x60 | 0x82; /*0x18dbca*/
      v4[38] &= ~0x80u; /*0x18dbcd*/
      *((_WORD *)v4 + 16) = v7; /*0x18dbd5*/
      v4[38] = BYTE2(v7) & 0xF | v4[38] & 0xF0; /*0x18dbef*/
      __asm { lldt ds:word_1D14EA } /*0x18dbf2*/
    }
    v2 = i; /*0x18dbf9*/
    do /*0x18dc0e*/
    {
      while ( *(_DWORD *)a1 ) /*0x18dbfc*/
        ; /*0x18dbfe*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x18dc0e*/
  }
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x18dc24*/
  if ( v2 ) /*0x18dc28*/
    thread_deallocate(v2); /*0x18dc2b*/
  task_release(a1); /*0x18dc34*/
  lock_done((int)(v12 + 4)); /*0x18dc40*/
  return 0; /*0x18dc4a*/
}
