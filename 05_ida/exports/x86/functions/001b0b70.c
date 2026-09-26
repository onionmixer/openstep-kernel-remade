/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b0b70. */
id __cdecl -[EventDriver free](EventDriver *self, SEL a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int evs_port; // [esp-1Ch] [ebp-28h]
  int ev_port; // [esp-14h] [ebp-20h]
  int ev_port_set; // [esp-Ch] [ebp-18h]
  int notify_port; // [esp-4h] [ebp-10h]
  objc_super v11; // [esp+4h] [ebp-8h] BYREF

  -[EventDriver evClose:token:](self, sel_evClose_token_, self->ev_port, self->eventPort); /*0x1b0b90*/
  ev_port = self->ev_port; /*0x1b0b9b*/
  v2 = task_self(); /*0x1b0b9c*/
  port_deallocate_EXTERNAL(v2, ev_port); /*0x1b0ba2*/
  evs_port = self->evs_port; /*0x1b0bad*/
  v3 = task_self(); /*0x1b0bae*/
  port_deallocate_EXTERNAL(v3, evs_port); /*0x1b0bb4*/
  notify_port = self->notify_port; /*0x1b0bc2*/
  v4 = task_self(); /*0x1b0bc3*/
  port_deallocate_EXTERNAL(v4, notify_port); /*0x1b0bc9*/
  ev_port_set = self->ev_port_set; /*0x1b0bd4*/
  v5 = task_self(); /*0x1b0bd5*/
  port_set_deallocate_EXTERNAL(v5, ev_port_set); /*0x1b0bdb*/
  objc_msgSend(self->eventSrcListLock, sel_free); /*0x1b0bee*/
  objc_msgSend(self->driverLock, sel_free); /*0x1b0c01*/
  v11.receiver = self; /*0x1b0c10*/
  v11.super_class = (Class)stru_1FA3D4.ext; /*0x1b0c19*/
  return -[IODevice free](&v11, sel_free); /*0x1b0c25*/
}
