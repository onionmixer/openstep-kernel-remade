/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x180478. */
id __cdecl -[KernDevice attachInterruptPort:](KernDevice *self, SEL a2, int a3)
{
  id v4; // eax
  id v5; // esi
  List *v6; // eax
  int v7; // ebx
  KernDeviceInterrupt *v8; // eax
  KernDeviceInterrupt *v9; // eax
  void *v10; // [esp+Ch] [ebp-4h] BYREF

  if ( self->_interruptPort || ipc_object_copyin(*(_DWORD *)(*(_DWORD *)(active_threads + 12) + 136), a3, 20, (int)&v10) ) /*0x1804a3*/
    return nullptr; /*0x1804b1*/
  v4 = objc_msgSend(self->_deviceDescription, sel_interrupts); /*0x1804c3*/
  if ( !v4 || (v5 = objc_msgSend(v4, sel_count)) == nullptr ) /*0x1804f4*/
  {
    ipc_port_release_send((int)v10); /*0x1804d3*/
    return self; /*0x18059c*/
  }
  self->_interruptPort = v10; /*0x18051f*/
  v6 = +[Object alloc](aList, sel_alloc); /*0x180538*/
  self->_interrupts = -[List initCount:](v6, sel_initCount_); /*0x180546*/
  v7 = 0; /*0x180549*/
  if ( (int)v5 <= 0 ) /*0x180550*/
    return self; /*0x180550*/
  while ( 1 ) /*0x18056d*/
  {
    v8 = +[Object alloc](aKerndeviceinte, sel_alloc); /*0x18056d*/
    v9 = -[KernDeviceInterrupt initWithInterruptPort:](v8, sel_initWithInterruptPort_); /*0x180576*/
    if ( !objc_msgSend(self->_interrupts, sel_addObject_, v9) ) /*0x180587*/
      break; /*0x180587*/
    if ( ++v7 >= (int)v5 ) /*0x18059a*/
      return self; /*0x18059a*/
  }
  -[KernDevice _detachInterruptSources](self, sel__detachInterruptSources); /*0x180500*/
  ipc_port_release_send((int)self->_interruptPort); /*0x180509*/
  self->_interruptPort = nullptr; /*0x18050e*/
  return nullptr; /*0x1805a1*/
}
