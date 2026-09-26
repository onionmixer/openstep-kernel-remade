/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9140. */
int sub_1A9140()
{
  void (__cdecl *v0)(int); // esi
  int v1; // ebx
  thread_act_t v2; // eax

  v0 = (void (__cdecl *)(int))dword_1E86EC; /*0x1a9145*/
  v1 = dword_1E86F0; /*0x1a914b*/
  objc_msgSend(dword_1E86F8, sel_unlock); /*0x1a915f*/
  v2 = current_thread_EXTERNAL(); /*0x1a9166*/
  thread_wire(1u, v2, 1); /*0x1a916e*/
  v0(v1); /*0x1a9174*/
  return IOExitThread(); /*0x1a917e*/
}
