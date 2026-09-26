/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a10d8. */
int __cdecl PCldt(int a1, unsigned int a2, unsigned int a3)
{
  int v4; // edi
  int v5; // eax
  _WORD *v6; // ebx
  int ldt; // esi
  int v8; // [esp+Ch] [ebp-4h] BYREF

  if ( !suser() ) /*0x1a10e4*/
    return 5; /*0x1a10ed*/
  if ( !object_copyin(*(_DWORD *)(active_threads + 12), a1, 6, 0, (int)&v8) ) /*0x1a110d*/
    return 4; /*0x1a110d*/
  v4 = convert_port_to_thread(v8); /*0x1a1122*/
  port_release(v8); /*0x1a1128*/
  if ( !v4 ) /*0x1a1132*/
    return 4; /*0x1a1134*/
  v5 = *(_DWORD *)(*(_DWORD *)(v4 + 40) + 112); /*0x1a113f*/
  if ( v5 ) /*0x1a1144*/
    v6 = (_WORD *)(v5 + 132); /*0x1a1146*/
  else
    v6 = (_WORD *)thread_user_state(v4); /*0x1a1159*/
  if ( a2 == -1 && a3 == -1 ) /*0x1a1164*/
    ldt = task_default_ldt(*(_DWORD *)(v4 + 12)); /*0x1a116f*/
  else
    ldt = task_locate_ldt(*(_DWORD *)(v4 + 12), a2, a3); /*0x1a1186*/
  if ( !ldt ) /*0x1a118d*/
  {
    v6[30] = 99; /*0x1a118f*/
    v6[36] = 107; /*0x1a1195*/
    v6[6] = 107; /*0x1a119b*/
    v6[4] = 107; /*0x1a11a1*/
    v6[2] = 0; /*0x1a11a7*/
    *v6 = 0; /*0x1a11ad*/
  }
  thread_deallocate(v4); /*0x1a11b3*/
  return ldt; /*0x1a11bd*/
}
