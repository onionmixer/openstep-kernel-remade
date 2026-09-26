/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19ec24. */
_DWORD *__cdecl FBAllocateConsole(const void *a1)
{
  _DWORD *v1; // ebx
  int v3; // eax

  v1 = (_DWORD *)IOMalloc(0x20u); /*0x19ec31*/
  if ( !v1 ) /*0x19ec38*/
    return nullptr; /*0x19ec3a*/
  v3 = IOMalloc(0xE4u); /*0x19ec45*/
  v1[7] = v3; /*0x19ec4a*/
  if ( v3 ) /*0x19ec52*/
  {
    *v1 = sub_19EFA8; /*0x19ec60*/
    v1[1] = sub_19DF7C; /*0x19ec66*/
    v1[2] = sub_19EFCC; /*0x19ec6d*/
    v1[3] = sub_19E23C; /*0x19ec74*/
    v1[4] = sub_19E7CC; /*0x19ec7b*/
    v1[5] = sub_19F050; /*0x19ec82*/
    v1[6] = sub_19F068; /*0x19ec89*/
    qmemcpy((void *)(v1[7] + 4), a1, 0x88u); /*0x19ec9f*/
    *(_DWORD *)v1[7] = 0; /*0x19eca4*/
    return v1; /*0x19ecaa*/
  }
  else
  {
    IOFree((int)v1, 32); /*0x19ec57*/
    return nullptr; /*0x19ec5c*/
  }
}
