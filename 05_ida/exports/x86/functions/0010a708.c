/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10a708. */
int __cdecl sleep_with_continuation(int a1, int a2, int a3)
{
  int v3; // ebx
  int v4; // edx
  int v5; // edx
  int v7; // [esp+0h] [ebp-10h]
  int v8; // [esp+Ch] [ebp-4h]

  v3 = *(_DWORD *)active_u; /*0x10a71c*/
  v8 = splhigh(); /*0x10a723*/
  if ( v3 ) /*0x10a728*/
    *(_BYTE *)(v3 + 17) = a2 & 0x7F; /*0x10a72f*/
  assert_wait(a1, a2 > 25); /*0x10a742*/
  if ( a2 <= 25 )
  {
    spl0(); /*0x10a824*/
    ++*(_DWORD *)(active_u + 432); /*0x10a82e*/
    if ( master_cpu )
      printf("unix sleep: on slave?\n");
    thread_block_with_continuation(a3); /*0x10a84b*/
    goto LABEL_23; /*0x10a84b*/
  }
  if ( !v3
    || (*(_BYTE *)(active_threads + 380) & 3) == 0
    && ((v4 = *(_DWORD *)(*(_DWORD *)(active_threads + 132) + 124) | *(_DWORD *)(v3 + 24)) == 0
     || (*(_BYTE *)(v3 + 40) & 0x10) == 0 && (v4 & ~(*(_DWORD *)(v3 + 28) | *(_DWORD *)(v3 + 32))) == 0
     || !issig(1)) )
  {
    spl0(); /*0x10a7b0*/
    ++*(_DWORD *)(active_u + 432); /*0x10a7ba*/
    if ( master_cpu )
      printf("unix sleep: on slave?\n");
    thread_block_with_continuation(a3); /*0x10a7d7*/
    if ( v3 ) /*0x10a7e1*/
    {
      if ( (*(_BYTE *)(active_threads + 380) & 3) != 0 ) /*0x10a7ef*/
        goto LABEL_24; /*0x10a7ef*/
      v5 = *(_DWORD *)(*(_DWORD *)(active_threads + 132) + 124) | *(_DWORD *)(v3 + 24); /*0x10a7fa*/
      if ( v5 && ((*(_BYTE *)(v3 + 40) & 0x10) != 0 || (v5 & ~(*(_DWORD *)(v3 + 28) | *(_DWORD *)(v3 + 32))) != 0) ) /*0x10a80f*/
      {
        if ( issig(1) ) /*0x10a813*/
          goto LABEL_24; /*0x10a81d*/
      }
    }
LABEL_23:
    spln(v8); /*0x10a853*/
    return 0; /*0x10a85e*/
  }
  clear_wait(active_threads, 2, 1); /*0x10a79e*/
  spl0(); /*0x10a7a3*/
LABEL_24:
  if ( a3 ) /*0x10a862*/
    call_continuation(a3); /*0x10a865*/
  if ( (a2 & 0x100) == 0 ) /*0x10a873*/
    longjmp((int *)(dword_1E875C + 40), v7); /*0x10a885*/
  return 1; /*0x10a88f*/
}
