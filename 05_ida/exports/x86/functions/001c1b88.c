/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c1b88. */
id __cdecl -[IOPCIDeviceDescription _initWithDelegate:](IOPCIDeviceDescription *self, SEL a2, id a3)
{
  id v3; // esi
  void *v4; // eax
  bool *v5; // ebx
  bool v7; // [esp+Ch] [ebp-Ch]
  objc_super v8; // [esp+10h] [ebp-8h] BYREF

  v3 = +[KernBus lookupBusInstanceWithName:busId:](aKernbus, sel_lookupBusInstanceWithName_busId_, "PCI", 0); /*0x1c1bae*/
  v8.receiver = self; /*0x1c1bbb*/
  v8.super_class = objc_getOrigClass("IOEISADeviceDescription"); /*0x1c1bcb*/
  -[IOPCIDeviceDescription _initWithDelegate:](&v8, sel__initWithDelegate_, a3); /*0x1c1bd2*/
  v4 = (void *)IOMalloc(4u); /*0x1c1bd9*/
  self->_pci_private = v4; /*0x1c1bde*/
  v5 = (bool *)v4; /*0x1c1be1*/
  v7 = 0; /*0x1c1be6*/
  if ( v3 && (unsigned __int8)objc_msgSend(v3, sel_isPCIPresent) == 1 ) /*0x1c1c00*/
    v7 = objc_msgSend(v3, aConfigaddressD, a3, v5 + 1, v5 + 2, v5 + 3) == nullptr; /*0x1c1c23*/
  *v5 = v7; /*0x1c1c2a*/
  return self; /*0x1c1c31*/
}
