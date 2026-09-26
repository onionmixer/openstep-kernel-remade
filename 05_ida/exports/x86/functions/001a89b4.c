/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a89b4. */
int __cdecl -[IODirectDevice _changeInterrupt:to:](IODirectDevice *self, SEL a2, unsigned int a3, char a4)
{
  void *v4; // esi
  HashTable *v6; // eax
  id v7; // ebx
  id v8; // eax
  id v9; // eax
  id v10; // esi
  int v11; // [esp+10h] [ebp-Ch] BYREF
  int v12; // [esp+14h] [ebp-8h] BYREF
  int v13; // [esp+18h] [ebp-4h] BYREF

  v4 = self->_private; /*0x1a89c9*/
  if ( a3 >= -[IODeviceDescription numInterrupts](self->_deviceDescription, sel_numInterrupts) ) /*0x1a89e7*/
    return -706; /*0x1a89e9*/
  if ( !*((_DWORD *)v4 + 1) ) /*0x1a89f4*/
  {
    v6 = +[Object alloc](aHashtable, sel_alloc); /*0x1a8a14*/
    *((_DWORD *)v4 + 1) = -[HashTable initKeyDesc:](v6, sel_initKeyDesc_); /*0x1a8a22*/
  }
  v7 = objc_msgSend(*((id *)v4 + 1), sel_valueForKey_, a3); /*0x1a8a39*/
  if ( !v7 ) /*0x1a8a40*/
  {
    v12 = 3; /*0x1a8a46*/
    v11 = 0; /*0x1a8a4d*/
    v8 = objc_msgSend(self->_deviceDescriptionDelegate, sel_device); /*0x1a8a6d*/
    v7 = objc_msgSend(v8, sel_interrupt_); /*0x1a8a7b*/
    objc_msgSend(*((id *)v4 + 1), sel_insertKey_value_, a3, v7); /*0x1a8a8a*/
    v9 = objc_msgSend(self->_deviceDescriptionDelegate, sel_resourcesForKey_, "IRQ Levels"); /*0x1a8aad*/
    v10 = objc_msgSend(v9, sel_objectAt_); /*0x1a8abb*/
    if ( -[IODirectDevice getHandler:level:argument:forInterrupt:]( /*0x1a8ad8*/
           self,
           sel_getHandler_level_argument_forInterrupt_,
           &v13,
           &v12,
           &v11,
           a3) )
    {
      objc_msgSend(v7, sel_attachToBusInterrupt_withSpecialHandler_argument_atLevel_, v10, v13, v11, v12); /*0x1a8af9*/
    }
    else
    {
      objc_msgSend(v7, sel_attachToBusInterrupt_withArgument_, v10, a3 + 2302757); /*0x1a8b14*/
    }
  }
  if ( a4 ) /*0x1a8b20*/
    objc_msgSend(v7, sel_resume); /*0x1a8b29*/
  else
    objc_msgSend(v7, sel_suspend); /*0x1a8b34*/
  return 0; /*0x1a8b3e*/
}
