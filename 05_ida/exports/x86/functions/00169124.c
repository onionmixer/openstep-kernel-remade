/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x169124. */
int calloutInitialize()
{
  int *v0; // edx
  _DWORD *v1; // ecx
  int result; // eax

  if ( !dword_1DFCBC ) /*0x16912f*/
  {
    dword_1E7244 = 0; /*0x169135*/
    dword_1E7254 = (int)&dword_1E7250; /*0x16913f*/
    dword_1E7250 = (int)&dword_1E7250; /*0x169149*/
    dword_1E725C = (int)&dword_1E7258; /*0x169153*/
    dword_1E7258 = (int)&dword_1E7258; /*0x16915d*/
    dword_1E724C = (int)&dword_1E7248; /*0x169167*/
    dword_1E7248 = (int)&dword_1E7248; /*0x169171*/
    v0 = (int *)&unk_1E6A44; /*0x16917b*/
    if ( &unk_1E6A44 < (_UNKNOWN *)&dword_1E7244 ) /*0x169186*/
    {
      v1 = &unk_1E6A48; /*0x169188*/
      do /*0x1691b4*/
      {
        *v0 = (int)&dword_1E7248; /*0x169190*/
        *v1 = dword_1E724C; /*0x16919c*/
        *(_DWORD *)*v1 = v0; /*0x1691a0*/
        dword_1E724C = (int)v0; /*0x1691a2*/
        v1 += 8; /*0x1691a8*/
        v0 += 8; /*0x1691ab*/
      }
      while ( v0 < &dword_1E7244 ); /*0x1691b4*/
    }
    kernel_thread(kernel_task, (int)sub_169EA0, 0); /*0x1691c4*/
    result = set_timer_expire_func(0, sub_169F44); /*0x1691d0*/
    dword_1DFCBC = 1; /*0x1691d5*/
  }
  return result; /*0x1691df*/
}
