/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c1cb8. */
int __cdecl -[IODirectDevice mapAttributeMemoryTo:findSpace:](IODirectDevice *self, SEL a2, unsigned int *a3, char a4)
{
  id v4; // ebx
  id v6; // eax
  id v7; // eax
  id v8; // eax
  int v9; // eax
  id v10; // ebx
  List *v11; // eax
  id v12; // esi
  id v13; // ebx
  int v14; // edx
  id v15; // eax
  id v16; // [esp+Ch] [ebp-18h]
  int v17; // [esp+10h] [ebp-14h]
  id v18; // [esp+14h] [ebp-10h]
  id v19; // [esp+18h] [ebp-Ch]
  id v20; // [esp+1Ch] [ebp-8h]

  v4 = +[KernBus lookupBusInstanceWithName:busId:](aKernbus, sel_lookupBusInstanceWithName_busId_, "PCMCIA", 0); /*0x1c1ce4*/
  if ( objc_msgSend(self->_deviceDescriptionDelegate, sel_resourcesForKey_, "PCMCIA_DEVICE_ATTR_MAPPING") ) /*0x1c1cfc*/
    return -725; /*0x1c1d08*/
  v6 = objc_msgSend(self->_deviceDescriptionDelegate, sel_resourcesForKey_, "PCMCIA_SOCKET_LIST"); /*0x1c1d33*/
  v7 = objc_msgSend(v6, sel_objectAt_); /*0x1c1d3c*/
  if ( !v7 ) /*0x1c1d46*/
    return -702; /*0x1c1d46*/
  v8 = objc_msgSend(v7, aObject_1); /*0x1c1d50*/
  v20 = objc_msgSend(v4, aAllocmemorywin, v8); /*0x1c1d63*/
  if ( !v20 ) /*0x1c1d6b*/
    return -702; /*0x1c1d6d*/
  v19 = objc_msgSend(self->_deviceDescriptionDelegate, sel_resourcesForKey_, "PCMCIA_WINDOW_LIST"); /*0x1c1d93*/
  v18 = objc_msgSend(v4, aMemoryrangeres); /*0x1c1da3*/
  v9 = current_task_EXTERNAL(); /*0x1c1db1*/
  if ( a4 ) /*0x1c1dad*/
    v10 = objc_msgSend(v18, sel_mapInTarget_cache_, v9, 0); /*0x1c1dc7*/
  else
    v10 = objc_msgSend(v18, sel_mapToAddress_inTarget_cache_, *a3, v9, 0); /*0x1c1deb*/
  if ( v10 ) /*0x1c1df2*/
  {
    *a3 = (unsigned int)objc_msgSend(v10, sel_address); /*0x1c1e1d*/
    v11 = +[Object alloc](aList, sel_alloc); /*0x1c1e36*/
    v12 = -[List initCount:](v11, sel_initCount_); /*0x1c1e44*/
    objc_msgSend(v12, sel_addObject_, v10); /*0x1c1e4f*/
    objc_msgSend(self->_deviceDescriptionDelegate, sel_setResources_forKey_, v12, "PCMCIA_DEVICE_ATTR_MAPPING"); /*0x1c1e6e*/
    v13 = objc_msgSend(v20, aObject_1); /*0x1c1e83*/
    v16 = objc_msgSend(v18, sel_range); /*0x1c1e95*/
    v17 = v14; /*0x1c1e98*/
    objc_msgSend(v13, aSetenabled, 0); /*0x1c1ea8*/
    objc_msgSend(v13, aSetmemoryinter, 1); /*0x1c1eb7*/
    objc_msgSend(v13, aSetattributeme, 1); /*0x1c1ec6*/
    objc_msgSend(v13, aSetmapwithsize, v17, v16, 0); /*0x1c1ee0*/
    objc_msgSend(v13, aSetenabled, 1); /*0x1c1eef*/
    v15 = objc_msgSend(v13, aSocket); /*0x1c1f08*/
    objc_msgSend(v15, aSetmemoryinter); /*0x1c1f11*/
    objc_msgSend(v19, sel_addObject_, v20); /*0x1c1f25*/
    return 0; /*0x1c1f2a*/
  }
  else
  {
    objc_msgSend(v20, sel_free); /*0x1c1dff*/
    return -701; /*0x1c1e04*/
  }
}
