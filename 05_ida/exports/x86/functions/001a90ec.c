/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a90ec. */
thread_act_t __cdecl IOForkThread(int a1, int a2)
{
  thread_act_t v2; // ebx
  int v4; // [esp-8h] [ebp-10h]

  objc_msgSend(dword_1E86F8, sel_lock); /*0x1a9105*/
  dword_1E86EC = a1; /*0x1a910a*/
  dword_1E86F0 = a2; /*0x1a9110*/
  v2 = kernel_thread(IOTask_kern, (int)sub_1A9140, v4); /*0x1a9127*/
  thread_priority(v2, 0x12u, 0); /*0x1a912e*/
  return v2; /*0x1a9138*/
}
