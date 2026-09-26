/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15ad60. */
int newStack()
{
  int v1; // eax
  _DWORD *v2; // ebx
  int i; // esi
  int v4; // eax
  int v5; // [esp+8h] [ebp-4h] BYREF

  if ( kmem_alloc_wired(kernel_map, &v5, dword_1E5BA0) ) /*0x15ad7a*/
    return 0; /*0x15ad86*/
  ++stackStats; /*0x15ad90*/
  v1 = v5; /*0x15ad96*/
  *(_DWORD *)(v5 + 8) = 2; /*0x15ad99*/
  ++dword_1F63B4; /*0x15ada0*/
  stack_init(v1 + 12); /*0x15adaa*/
  if ( dword_1E5BA4 <= 1 ) /*0x15adb9*/
    return v5 + 12; /*0x15adbe*/
  lock_write((int)&stack_queue_lock); /*0x15adcd*/
  v2 = (_DWORD *)(dword_1E5BA0 + v5); /*0x15add5*/
  for ( i = 1; dword_1E5BA4 > i; ++i ) /*0x15ade9*/
  {
    stack_init(v2 + 3); /*0x15adf0*/
    v2[2] = 0; /*0x15adf8*/
    v4 = dword_1E5B9C; /*0x15adff*/
    if ( (int *)dword_1E5B9C == &dword_1E5B98 ) /*0x15ae09*/
      dword_1E5B98 = (int)v2; /*0x15ae0b*/
    else
      *(_DWORD *)dword_1E5B9C = v2; /*0x15ae14*/
    v2[1] = v4; /*0x15ae16*/
    *v2 = &dword_1E5B98; /*0x15ae19*/
    dword_1E5B9C = (int)v2; /*0x15ae1f*/
    ++dword_1DED68; /*0x15ae25*/
    ++dword_1F63B8; /*0x15ae2b*/
    v2 = (_DWORD *)((char *)v2 + dword_1E5BA0); /*0x15ae31*/
  }
  lock_done(&stack_queue_lock); /*0x15ae45*/
  return v5 + 12; /*0x15ae53*/
}
