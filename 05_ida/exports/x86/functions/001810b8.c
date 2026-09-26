/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1810b8. */
id __cdecl -[KernDeviceDescription initFromConfigTable:](KernDeviceDescription *self, SEL a2, id a3)
{
  HashTable *v3; // eax
  HashTable *v4; // eax
  List *v5; // eax
  id v6; // edi
  _BYTE *v7; // ebx
  int v9; // [esp+Ch] [ebp-Ch] BYREF
  objc_super v10; // [esp+10h] [ebp-8h] BYREF

  v10.receiver = self; /*0x1810ce*/
  v10.super_class = (Class)stru_1F9FC4.super_class; /*0x1810d7*/
  -[Object init](&v10, sel_init); /*0x1810de*/
  self->_configTable = a3; /*0x1810e3*/
  self->_device = nullptr; /*0x1810e6*/
  v3 = +[Object alloc](aHashtable, sel_alloc); /*0x18110c*/
  self->_stringTable = -[HashTable initKeyDesc:valueDesc:](v3, sel_initKeyDesc_valueDesc_); /*0x18111a*/
  v4 = +[Object alloc](aHashtable, sel_alloc); /*0x18113c*/
  self->_resourceTable = -[HashTable initKeyDesc:valueDesc:](v4, sel_initKeyDesc_valueDesc_); /*0x18114a*/
  v5 = +[Object alloc](aList, sel_alloc); /*0x181165*/
  self->_interruptList = -[List init](v5, sel_init); /*0x181173*/
  v6 = objc_msgSend(self->_configTable, sel_valueForStringKey_, aBusType); /*0x18118b*/
  self->_busClass = +[KernBus lookupBusClassWithName:](aKernbus, sel_lookupBusClassWithName_, v6); /*0x1811a1*/
  v7 = objc_msgSend(self->_configTable, sel_valueForStringKey_, aBusId); /*0x1811bc*/
  if ( v7 && sub_180F48(v7, nullptr, (unsigned int *)&v9) ) /*0x1811cc*/
    self->_busId = v9; /*0x1811db*/
  self->_bus = +[KernBus lookupBusInstanceWithName:busId:]( /*0x1811f6*/
                 aKernbus,
                 sel_lookupBusInstanceWithName_busId_,
                 v6,
                 self->_busId);
  if ( v7 ) /*0x1811fe*/
    objc_msgSend(self->_configTable, sel_freeString_, v7); /*0x18120c*/
  if ( v6 ) /*0x181216*/
    objc_msgSend(self->_configTable, sel_freeString_, v6); /*0x181224*/
  return self; /*0x18122e*/
}
