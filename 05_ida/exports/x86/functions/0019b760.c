/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19b760. */
_DWORD *__cdecl VGAAllocateConsole(const void *a1)
{
  _DWORD *v1; // ebx
  _DWORD *v2; // eax

  v1 = (_DWORD *)IOMalloc(0x20u); /*0x19b76d*/
  v2 = (_DWORD *)IOMalloc(0x104u); /*0x19b774*/
  if ( !v1 ) /*0x19b780*/
    return nullptr; /*0x19b782*/
  v1[7] = v2; /*0x19b78c*/
  if ( v2 ) /*0x19b791*/
  {
    *v1 = sub_19B81C; /*0x19b7a0*/
    v1[1] = sub_19AB88; /*0x19b7a6*/
    v1[2] = sub_19AE0C; /*0x19b7ad*/
    v1[3] = sub_19B340; /*0x19b7b4*/
    v1[4] = sub_19B860; /*0x19b7bb*/
    v1[5] = sub_19B9C8; /*0x19b7c2*/
    v1[6] = sub_19B9E0; /*0x19b7c9*/
    qmemcpy(v2 + 1, a1, 0x88u); /*0x19b7dc*/
    v2[64] = 0; /*0x19b7de*/
    v2[6] = 655360; /*0x19b7e8*/
    v2[3] = 640; /*0x19b7ef*/
    v2[4] = 80; /*0x19b7f6*/
    v2[49] = v2[6] + 80 * v2[2]; /*0x19b804*/
    *v2 = 0; /*0x19b80a*/
    return v1; /*0x19b810*/
  }
  else
  {
    IOFree((int)v1, 32); /*0x19b796*/
    return nullptr; /*0x19b79b*/
  }
}
