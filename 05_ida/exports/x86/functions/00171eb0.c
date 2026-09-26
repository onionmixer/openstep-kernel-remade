/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x171eb0. */
int __cdecl catch_exception_raise(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // edx
  int v7; // esi
  int v8; // ebx
  unsigned int v10; // [esp+Ch] [ebp-8h] BYREF
  int v11; // [esp+10h] [ebp-4h] BYREF

  v6 = *(_DWORD *)(active_threads + 12); /*0x171ec1*/
  v7 = 0; /*0x171ec4*/
  v10 = 0; /*0x171ec6*/
  if ( object_copyin(v6, a2, 6, 0, (int)&v11) && (v8 = convert_port_to_thread(v11), port_release(v11), v8) ) /*0x171efc*/
  {
    sub_171F6C(a4, a5, a6, &v10, *(_DWORD *)(v8 + 132) + 116); /*0x171f18*/
    if ( v10 ) /*0x171f25*/
      thread_psignal(v8, v10); /*0x171f29*/
    thread_deallocate(v8); /*0x171f32*/
  }
  else
  {
    v7 = 4; /*0x171f3c*/
  }
  port_deallocate_EXTERNAL(dword_1E7284, a3); /*0x171f4c*/
  port_deallocate_EXTERNAL(dword_1E7284, a2); /*0x171f59*/
  return v7; /*0x171f63*/
}
