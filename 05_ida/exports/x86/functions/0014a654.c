/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14a654. */
int *__cdecl ipc_mqueue_move(int a1, int a2, int a3)
{
  int *result; // eax
  int *v4; // esi
  _DWORD *v5; // eax
  _DWORD *v6; // ebx
  int *v7; // [esp+Ch] [ebp-10h]
  _DWORD *v8; // [esp+18h] [ebp-4h]

  v8 = (_DWORD *)(a2 + 4); /*0x14a669*/
  result = (int *)(a1 + 8); /*0x14a672*/
  v4 = *(int **)(a2 + 4); /*0x14a678*/
  if ( v4 ) /*0x14a67d*/
  {
    do /*0x14a716*/
    {
      result = (int *)ipc_kmsg_queue_next(v8, v4); /*0x14a689*/
      v7 = result; /*0x14a68e*/
      if ( v4[7] == a3 ) /*0x14a697*/
      {
        ipc_kmsg_rmqueue(v8, v4); /*0x14a69e*/
        while ( 1 ) /*0x14a6ac*/
        {
          v5 = (_DWORD *)ipc_thread_dequeue(a1 + 8); /*0x14a6ac*/
          v6 = v5; /*0x14a6b1*/
          if ( !v5 ) /*0x14a6b8*/
            break; /*0x14a6b8*/
          thread_go(v5); /*0x14a6bb*/
          result = (int *)v6[39]; /*0x14a6c0*/
          if ( v4[6] <= (unsigned int)result ) /*0x14a6cc*/
          {
            v6[38] = 0; /*0x14a6ce*/
            v6[39] = v4; /*0x14a6d8*/
            v6[40] = (*(_DWORD *)(a3 + 52))++; /*0x14a6e1*/
            goto LABEL_9; /*0x14a6ea*/
          }
          v6[38] = 268451844; /*0x14a6ec*/
          v6[39] = v4[6]; /*0x14a6f9*/
        }
        result = ipc_kmsg_enqueue((_DWORD *)(a1 + 4), v4); /*0x14a709*/
      }
LABEL_9:
      v4 = v7; /*0x14a711*/
    }
    while ( v7 ); /*0x14a716*/
  }
  return result; /*0x14a71f*/
}
