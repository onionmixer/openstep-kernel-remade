/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14758c. */
int __cdecl ipc_kmsg_get(int a1, unsigned int a2, int a3, unsigned int **a4)
{
  unsigned int *v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // eax

  if ( a2 <= 0x17 || (a2 & 3) != 0 || a3 > 0 ) /*0x1475a6*/
    return 268435464; /*0x1475ad*/
  if ( a2 > 0xEC ) /*0x1475ba*/
  {
    v7 = kalloc(a2 + 20); /*0x1475f4*/
    v5 = (unsigned int *)v7; /*0x1475f9*/
    if ( v7 ) /*0x147600*/
    {
      *(_DWORD *)(v7 + 8) = a2 + 20; /*0x14760c*/
      goto LABEL_13; /*0x14760c*/
    }
    return 268435469; /*0x147607*/
  }
  v5 = (unsigned int *)ipc_kmsg_cache; /*0x1475bc*/
  if ( ipc_kmsg_cache ) /*0x1475c4*/
  {
    ipc_kmsg_cache = 0; /*0x1475c6*/
    goto LABEL_14; /*0x1475d0*/
  }
  v6 = kalloc(0x100u); /*0x1475d9*/
  v5 = (unsigned int *)v6; /*0x1475de*/
  if ( !v6 ) /*0x1475e5*/
    return 268435469; /*0x1475e5*/
  *(_DWORD *)(v6 + 8) = 256; /*0x1475e7*/
LABEL_13:
  v5[3] = 0; /*0x14760f*/
LABEL_14:
  v5[4] = 0; /*0x147616*/
  if ( copyinmsg(a1, v5 + 5, a2 + a3) ) /*0x14762b*/
  {
    v8 = v5[2]; /*0x147637*/
    if ( v8 <= 0 ) /*0x14763c*/
    {
      if ( v8 == -2 ) /*0x147641*/
      {
        KernDeviceInterruptMsgRelease(v5); /*0x14764d*/
      }
      else if ( v8 != -1 ) /*0x147643*/
      {
        if ( v8 != -3 ) /*0x147648*/
          goto LABEL_22; /*0x147648*/
        netipc_msg_release(v5); /*0x147655*/
      }
      return 268435458; /*0x147668*/
    }
LABEL_22:
    kfree((int)v5, v5[2]); /*0x14765c*/
    return 268435458; /*0x14765e*/
  }
  v5[4] = a3; /*0x14766f*/
  v5[6] = a2; /*0x147672*/
  *a4 = v5; /*0x147678*/
  return 0; /*0x14767f*/
}
