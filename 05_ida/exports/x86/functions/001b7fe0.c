/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b7fe0. */
id __cdecl -[AudioChannel removeSndStreams](AudioChannel *self, SEL a2)
{
  List *v2; // eax
  List *v3; // edi
  unsigned int i; // ebx
  id v5; // esi
  unsigned int j; // ebx
  id v7; // eax

  v2 = +[Object alloc](aList, sel_alloc); /*0x1b7ffb*/
  v3 = -[List init](v2, sel_init); /*0x1b8009*/
  objc_msgSend(self->streamListLock, sel_lock); /*0x1b8019*/
  for ( i = 0; i < (unsigned int)objc_msgSend(self->streamList, sel_count); ++i ) /*0x1b801e*/
  {
    v5 = objc_msgSend(self->streamList, sel_objectAt_, i); /*0x1b8052*/
    if ( objc_msgSend(v5, sel_type) ) /*0x1b805c*/
      -[List addObject:](v3, sel_addObject_, v5); /*0x1b8071*/
  }
  objc_msgSend(self->streamListLock, sel_unlock); /*0x1b808a*/
  for ( j = 0; j < -[List count](v3, sel_count); ++j ) /*0x1b808f*/
  {
    v7 = -[List objectAt:](v3, sel_objectAt_, j); /*0x1b80b1*/
    -[AudioChannel removeStream:](self, sel_removeStream_, v7); /*0x1b80c2*/
  }
  -[List free](v3, sel_free); /*0x1b80d8*/
  return self; /*0x1b80e3*/
}
