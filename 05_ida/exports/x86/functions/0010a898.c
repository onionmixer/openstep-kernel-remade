/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10a898. */
int __cdecl sleep_with_continuation_and_deadline(int a1, int a2, int a3, _DWORD *a4)
{
  int v4; // ebx
  int v5; // edx
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int v10; // [esp+0h] [ebp-10h]
  int v11; // [esp+Ch] [ebp-4h]

  v4 = *(_DWORD *)active_u; /*0x10a8ac*/
  v11 = splhigh(); /*0x10a8b3*/
  if ( v4 ) /*0x10a8b8*/
    *(_BYTE *)(v4 + 17) = a2 & 0x7F; /*0x10a8bf*/
  assert_wait(a1, a2 > 25); /*0x10a8d2*/
  if ( a2 <= 25 )
  {
    if ( a4 ) /*0x10a9d2*/
    {
      v8 = hzto(a4); /*0x10a9d5*/
      thread_set_timeout(v8); /*0x10a9db*/
    }
    spl0(); /*0x10a9e3*/
    ++*(_DWORD *)(active_u + 432); /*0x10a9ed*/
    if ( master_cpu )
      printf("unix sleep: on slave?\n");
    thread_block_with_continuation(a3); /*0x10aa0d*/
    goto LABEL_27; /*0x10aa0d*/
  }
  if ( !v4
    || (*(_BYTE *)(active_threads + 380) & 3) == 0
    && ((v5 = *(_DWORD *)(*(_DWORD *)(active_threads + 132) + 124) | *(_DWORD *)(v4 + 24)) == 0
     || (*(_BYTE *)(v4 + 40) & 0x10) == 0 && (v5 & ~(*(_DWORD *)(v4 + 28) | *(_DWORD *)(v4 + 32))) == 0
     || !issig(1)) )
  {
    if ( a4 ) /*0x10a942*/
    {
      v6 = hzto(a4); /*0x10a945*/
      thread_set_timeout(v6); /*0x10a94b*/
    }
    spl0(); /*0x10a953*/
    ++*(_DWORD *)(active_u + 432); /*0x10a95d*/
    if ( master_cpu )
      printf("unix sleep: on slave?\n");
    thread_block_with_continuation(a3); /*0x10a97d*/
    if ( v4 ) /*0x10a987*/
    {
      if ( (*(_BYTE *)(active_threads + 380) & 3) != 0 ) /*0x10a999*/
        goto LABEL_28; /*0x10a999*/
      v7 = *(_DWORD *)(*(_DWORD *)(active_threads + 132) + 124) | *(_DWORD *)(v4 + 24); /*0x10a9a8*/
      if ( v7 && ((*(_BYTE *)(v4 + 40) & 0x10) != 0 || (v7 & ~(*(_DWORD *)(v4 + 28) | *(_DWORD *)(v4 + 32))) != 0) ) /*0x10a9bd*/
      {
        if ( issig(1) ) /*0x10a9c1*/
          goto LABEL_28; /*0x10a9cb*/
      }
    }
LABEL_27:
    spln(v11); /*0x10aa15*/
    return 0; /*0x10aa20*/
  }
  clear_wait(active_threads, 2, 1); /*0x10a92e*/
  spl0(); /*0x10a933*/
LABEL_28:
  if ( a3 ) /*0x10aa28*/
    call_continuation(a3); /*0x10aa2e*/
  if ( (a2 & 0x100) == 0 ) /*0x10aa3c*/
    longjmp((int *)(dword_1E875C + 40), v10); /*0x10aa51*/
  return 1; /*0x10aa5b*/
}
