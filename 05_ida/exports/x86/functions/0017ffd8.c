/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17ffd8. */
_DWORD *__cdecl sub_17FFD8(int a1)
{
  KernLock *v1; // eax
  _DWORD *v3; // [esp+Ch] [ebp-4h]

  v3 = (_DWORD *)kalloc(0x58u); /*0x17ffeb*/
  qmemcpy(v3, &unk_1D1390, 0x58u); /*0x17fffe*/
  v1 = +[Object alloc](aKernlock, sel_alloc); /*0x180017*/
  v3[12] = -[KernLock initWithLevel:](v1, sel_initWithLevel_); /*0x180028*/
  ipc_object_reference(a1); /*0x18002c*/
  v3[11] = a1; /*0x180031*/
  v3[15] = sub_1802E8; /*0x180034*/
  v3[17] = v3; /*0x18003e*/
  v3[20] = 0; /*0x180041*/
  v3[2] = -2; /*0x18004b*/
  v3[3] = 0; /*0x180052*/
  v3[4] = 0; /*0x180059*/
  ipc_object_reference(v3[11]); /*0x180064*/
  return v3; /*0x18006f*/
}
