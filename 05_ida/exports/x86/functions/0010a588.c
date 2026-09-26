/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10a588. */
unsigned int __cdecl sleep(unsigned int a1)
{
  int v1; // ebx
  int v2; // edi
  int v3; // edx
  int v4; // edx
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+18h] [ebp+Ch]

  v1 = *(_DWORD *)active_u; /*0x10a596*/
  v2 = splhigh(); /*0x10a59d*/
  if ( v1 ) /*0x10a5a1*/
    *(_BYTE *)(v1 + 17) = v7 & 0x7F; /*0x10a5a8*/
  assert_wait(a1, v7 > 25); /*0x10a5bb*/
  if ( v7 <= 25 )
  {
    spl0(); /*0x10a6a0*/
    ++*(_DWORD *)(active_u + 432); /*0x10a6aa*/
    if ( master_cpu )
      printf("unix sleep: on slave?\n");
    thread_block_with_continuation(0); /*0x10a6c8*/
    goto LABEL_23; /*0x10a6c8*/
  }
  if ( !v1
    || (*(_BYTE *)(active_threads + 380) & 3) == 0
    && ((v3 = *(_DWORD *)(*(_DWORD *)(active_threads + 132) + 124) | *(_DWORD *)(v1 + 24)) == 0
     || (*(_BYTE *)(v1 + 40) & 0x10) == 0 && (v3 & ~(*(_DWORD *)(v1 + 28) | *(_DWORD *)(v1 + 32))) == 0
     || !issig(1)) )
  {
    spl0(); /*0x10a62c*/
    ++*(_DWORD *)(active_u + 432); /*0x10a636*/
    if ( master_cpu )
      printf("unix sleep: on slave?\n");
    thread_block_with_continuation(0); /*0x10a654*/
    if ( v1 ) /*0x10a65e*/
    {
      if ( (*(_BYTE *)(active_threads + 380) & 3) != 0 ) /*0x10a66c*/
        goto LABEL_24; /*0x10a66c*/
      v4 = *(_DWORD *)(*(_DWORD *)(active_threads + 132) + 124) | *(_DWORD *)(v1 + 24); /*0x10a677*/
      if ( v4 && ((*(_BYTE *)(v1 + 40) & 0x10) != 0 || (v4 & ~(*(_DWORD *)(v1 + 28) | *(_DWORD *)(v1 + 32))) != 0) ) /*0x10a68c*/
      {
        if ( issig(1) ) /*0x10a690*/
          goto LABEL_24; /*0x10a69a*/
      }
    }
LABEL_23:
    spln(v2); /*0x10a6d0*/
    return 0; /*0x10a6d8*/
  }
  clear_wait(active_threads, 2, 1); /*0x10a617*/
  spl0(); /*0x10a61c*/
LABEL_24:
  if ( (v7 & 0x100) == 0 ) /*0x10a6e2*/
    longjmp((int *)(dword_1E875C + 40), v6); /*0x10a6f5*/
  return 1; /*0x10a6ff*/
}
