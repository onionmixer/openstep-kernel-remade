/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f8c0. */
id __cdecl -[EventSrcPCKeyboard free](EventSrcPCKeyboard *self, SEL a2)
{
  id deviceLock; // ebx
  id keyMap; // eax
  id kbdDevice; // eax
  objc_super v6; // [esp+8h] [ebp-8h] BYREF

  deviceLock = self->deviceLock; /*0x19f8cb*/
  objc_msgSend(deviceLock, sel_lock); /*0x19f8d9*/
  dword_1E488C = nullptr; /*0x19f8de*/
  self->deviceLock = nullptr; /*0x19f8e8*/
  keyMap = self->keyMap; /*0x19f8f5*/
  if ( keyMap ) /*0x19f8fd*/
    objc_msgSend(keyMap, sel_free); /*0x19f907*/
  kbdDevice = self->kbdDevice; /*0x19f90f*/
  if ( kbdDevice ) /*0x19f917*/
    objc_msgSend(kbdDevice, sel_relinquishOwnership_, self); /*0x19f922*/
  objc_msgSend(deviceLock, sel_unlock); /*0x19f932*/
  objc_msgSend(deviceLock, sel_free); /*0x19f93f*/
  v6.receiver = self; /*0x19f94b*/
  v6.super_class = (Class)stru_1FA014.ext; /*0x19f954*/
  return -[IOEventSource free](&v6, sel_free); /*0x19f963*/
}
