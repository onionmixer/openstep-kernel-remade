/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1823c8. */
int __cdecl kern_IOProbeDriver(int a1, void *a2, size_t a3)
{
  int result; // eax
  void *v4; // eax
  int v5; // esi
  NXConditionLock *v6; // ebx
  _DWORD v7[2]; // [esp+Ch] [ebp-Ch] BYREF
  char v8; // [esp+14h] [ebp-4h]

  if ( !a1 ) /*0x1823d8*/
    return -705; /*0x1823da*/
  v4 = (void *)IOMalloc(a3 + 1); /*0x1823e8*/
  v5 = (int)v4; /*0x1823ed*/
  if ( !v4 ) /*0x1823f4*/
    return -731; /*0x1823f6*/
  bcopy(a2, v4, a3); /*0x182406*/
  *(_BYTE *)(a3 + v5) = 0; /*0x18240b*/
  v6 = +[Object alloc](aNxconditionloc, sel_alloc); /*0x182422*/
  -[NXConditionLock initWith:](v6, sel_initWith_, 0); /*0x18242e*/
  v7[0] = v6; /*0x182433*/
  v7[1] = v5; /*0x182436*/
  IOForkThread(configureThread, v7); /*0x182445*/
  -[NXConditionLock lockWhen:](v6, sel_lockWhen_, 1); /*0x182454*/
  -[NXConditionLock free](v6, sel_free); /*0x182461*/
  IOFree(v5, a3 + 1); /*0x182468*/
  result = 0; /*0x18246d*/
  if ( !v8 ) /*0x182473*/
    return -704; /*0x182475*/
  return result; /*0x18247d*/
}
