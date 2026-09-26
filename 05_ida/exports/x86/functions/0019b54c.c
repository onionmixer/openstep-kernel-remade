/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19b54c. */
_DWORD *__cdecl _VGAAllocateConsole(const void *a1, int a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ebx
  _DWORD *v4; // edx
  int v6; // eax
  _DWORD *v7; // [esp+Ch] [ebp-4h]

  v7 = (_DWORD *)IOMalloc(0x20u); /*0x19b563*/
  v2 = (_DWORD *)IOMalloc(0x104u); /*0x19b566*/
  v3 = v2; /*0x19b56b*/
  v4 = v7; /*0x19b570*/
  if ( !v7 ) /*0x19b575*/
    return nullptr; /*0x19b579*/
  v7[7] = v2; /*0x19b580*/
  if ( !v2 ) /*0x19b585*/
  {
    IOFree((int)v7, 32); /*0x19b58a*/
    return nullptr; /*0x19b591*/
  }
  *v7 = sub_19B81C; /*0x19b598*/
  v7[1] = sub_19AB88; /*0x19b59e*/
  v7[2] = sub_19AE0C; /*0x19b5a5*/
  v7[3] = sub_19B340; /*0x19b5ac*/
  v7[4] = sub_19B860; /*0x19b5b3*/
  v7[5] = sub_19B9C8; /*0x19b5ba*/
  v7[6] = sub_19B9E0; /*0x19b5c1*/
  qmemcpy(v2 + 1, a1, 0x88u); /*0x19b5d6*/
  v2[64] = a2; /*0x19b5db*/
  if ( a2 ) /*0x19b5e3*/
  {
    v2[2] = 512; /*0x19b5e5*/
    v2[6] = 655360; /*0x19b5ec*/
    v2[3] = 1024; /*0x19b5f3*/
    v2[4] = 128; /*0x19b5fa*/
    v6 = IOMalloc(0x30000u); /*0x19b609*/
    v3[49] = v6; /*0x19b60e*/
    v4 = v7; /*0x19b617*/
    if ( !v6 ) /*0x19b61c*/
    {
      IOFree((int)v7, 32); /*0x19b621*/
      IOFree((int)v3, 260); /*0x19b62c*/
      return nullptr; /*0x19b633*/
    }
  }
  else
  {
    v2[6] = 655360; /*0x19b638*/
    v2[3] = 640; /*0x19b63f*/
    v2[4] = 80; /*0x19b646*/
    v2[49] = v2[6] + 80 * v2[2]; /*0x19b654*/
  }
  *v3 = 0; /*0x19b65a*/
  return v4; /*0x19b665*/
}
