/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b11bc. */
id __cdecl -[EventDriver _resetKeyboardParameters](EventDriver *self, SEL a2)
{
  queue_entry *next; // ebx
  void *v3; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-4h] BYREF

  objc_msgSend(self->eventSrcListLock, sel_lock); /*0x1b11d6*/
  next = self->eventSrcList.next; /*0x1b11de*/
  while ( &self->eventSrcList != ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ) /*0x1b11f0*/
  {
    v3 = *(void **)next; /*0x1b11f8*/
    next = *((queue_entry **)next + 1); /*0x1b11fa*/
    objc_msgSend(v3, sel_setIntValues_forParameter_count_, v5, "Evs_ResetKeyboard", 1); /*0x1b120d*/
  }
  objc_msgSend(self->eventSrcListLock, sel_unlock); /*0x1b122a*/
  return self; /*0x1b1235*/
}
