/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1af240. */
EventDriver *__cdecl -[EventDriver init](EventDriver *self, SEL a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  thread_act_t v10; // ebx
  objc_super v11; // [esp+8h] [ebp-8h] BYREF

  self->driverLock = +[Object new](aNxlock, sel_new); /*0x1af25e*/
  self->eventSrcListLock = +[Object new](aNxlock, sel_new); /*0x1af277*/
  self->kickConsumerLock = +[Object new](aNxlock, sel_new); /*0x1af290*/
  v2 = task_self(); /*0x1af29d*/
  if ( port_allocate_EXTERNAL(v2) ) /*0x1af2a3*/
    return nullptr; /*0x1af2a3*/
  v3 = task_self(); /*0x1af2ba*/
  if ( port_allocate_EXTERNAL(v3) ) /*0x1af2c0*/
    return nullptr; /*0x1af2c0*/
  v4 = task_self(); /*0x1af2d7*/
  if ( port_allocate_EXTERNAL(v4) ) /*0x1af2dd*/
    return nullptr; /*0x1af2dd*/
  ev_port_list[0] = IOGetKernPort(self->ev_port); /*0x1af2f9*/
  dword_1DED04 = IOGetKernPort(self->evs_port); /*0x1af30a*/
  self->notify_kern_port = IOGetKernPort(self->notify_port); /*0x1af31b*/
  v5 = task_self(); /*0x1af328*/
  if ( port_set_allocate_EXTERNAL(v5) ) /*0x1af32e*/
    return nullptr; /*0x1af32e*/
  v6 = task_self(); /*0x1af348*/
  if ( port_set_add_EXTERNAL(v6) ) /*0x1af34e*/
    return nullptr; /*0x1af34e*/
  v7 = task_self(); /*0x1af368*/
  if ( port_set_add_EXTERNAL(v7) ) /*0x1af36e*/
    return nullptr; /*0x1af36e*/
  v8 = task_self(); /*0x1af388*/
  if ( port_set_add_EXTERNAL(v8) ) /*0x1af38e*/
    return nullptr; /*0x1af39a*/
  self->eventSrcList.prev = (queue_entry *)&self->eventSrcList; /*0x1af3aa*/
  self->eventSrcList.next = (queue_entry *)&self->eventSrcList; /*0x1af3b0*/
  v11.receiver = self; /*0x1af3bd*/
  v11.super_class = (Class)stru_1FA3D4.ext; /*0x1af3c6*/
  -[IODevice init](&v11, sel_init); /*0x1af3cd*/
  self->pointerLoc.x = 100; /*0x1af3d2*/
  self->pointerLoc.y = 100; /*0x1af3db*/
  v10 = IOForkThread((int)sub_1B0858, (int)self); /*0x1af3ef*/
  IOSetThreadPolicy(v10, 2); /*0x1af3f4*/
  IOSetThreadPriority(v10, 0x1Cu); /*0x1af3fc*/
  if ( !self->hasRegistered ) /*0x1af404*/
  {
    -[IODevice registerDevice](self, sel_registerDevice); /*0x1af415*/
    self->hasRegistered = 1; /*0x1af41a*/
  }
  return self; /*0x1af426*/
}
