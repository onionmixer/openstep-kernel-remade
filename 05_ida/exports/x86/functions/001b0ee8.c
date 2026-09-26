/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b0ee8. */
int __cdecl -[EventDriver getCharValues:forParameter:count:](
        EventDriver *self,
        SEL a2,
        char *a3,
        char *a4,
        unsigned int *a5)
{
  int v5; // esi
  queue_entry *next; // ebx
  id v7; // eax
  id v9; // [esp+Ch] [ebp-10h]
  objc_super v10; // [esp+10h] [ebp-Ch] BYREF
  unsigned int v11; // [esp+18h] [ebp-4h] BYREF

  v5 = -706; /*0x1b0ef4*/
  v11 = 0; /*0x1b0ef9*/
  v11 = *a5; /*0x1b0f05*/
  objc_msgSend(self->eventSrcListLock, sel_lock); /*0x1b0f16*/
  next = self->eventSrcList.next; /*0x1b0f1b*/
  while ( &self->eventSrcList != ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ) /*0x1b0f64*/
  {
    v9 = *(id *)next; /*0x1b0f2a*/
    next = *((queue_entry **)next + 1); /*0x1b0f2d*/
    v7 = objc_msgSend(v9, sel_getCharValues_forParameter_count_, a3, a4, &v11); /*0x1b0f47*/
    if ( v7 != (id)-706 ) /*0x1b0f54*/
    {
      v5 = (int)v7; /*0x1b0f56*/
      break; /*0x1b0f58*/
    }
  }
  objc_msgSend(self->eventSrcListLock, sel_unlock); /*0x1b0f66*/
  if ( v5 == -706 ) /*0x1b0f82*/
  {
    v10.receiver = self; /*0x1b0f97*/
    v10.super_class = (Class)stru_1FA3D4.ext; /*0x1b0fa0*/
    v5 = -[IODevice getCharValues:forParameter:count:](&v10, sel_getCharValues_forParameter_count_, a3, a4, &v11); /*0x1b0fac*/
  }
  *a5 = v11; /*0x1b0fb4*/
  return v5; /*0x1b0fbb*/
}
