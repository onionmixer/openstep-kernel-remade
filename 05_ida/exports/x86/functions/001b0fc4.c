/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b0fc4. */
int __cdecl -[EventDriver setCharValues:forParameter:count:](
        EventDriver *self,
        SEL a2,
        char *a3,
        char *a4,
        unsigned int a5)
{
  int v5; // esi
  queue_entry *next; // ebx
  void *v7; // eax
  id v8; // eax
  objc_super v10; // [esp+Ch] [ebp-8h] BYREF

  v5 = -706; /*0x1b0fcd*/
  objc_msgSend(self->eventSrcListLock, sel_lock); /*0x1b0fe3*/
  next = self->eventSrcList.next; /*0x1b0feb*/
  while ( &self->eventSrcList != ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ) /*0x1b0ffd*/
  {
    v7 = *(void **)next; /*0x1b1004*/
    next = *((queue_entry **)next + 1); /*0x1b1006*/
    v8 = objc_msgSend(v7, sel_setCharValues_forParameter_count_, a3, a4, a5); /*0x1b101d*/
    if ( v8 != (id)-706 ) /*0x1b102a*/
      v5 = (int)v8; /*0x1b102c*/
  }
  objc_msgSend(self->eventSrcListLock, sel_unlock); /*0x1b1043*/
  if ( v5 == -706 ) /*0x1b1051*/
  {
    v10.receiver = self; /*0x1b1069*/
    v10.super_class = (Class)stru_1FA3D4.ext; /*0x1b1072*/
    return -[IODevice setCharValues:forParameter:count:](&v10, sel_setCharValues_forParameter_count_, a3, a4, a5); /*0x1b107e*/
  }
  return v5; /*0x1b1085*/
}
