/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x180a60. */
id __cdecl -[KernDeviceDescription allocateItems:numItems:forKey:](
        KernDeviceDescription *self,
        SEL a2,
        unsigned int *a3,
        unsigned int a4,
        const char *a5)
{
  List *v5; // eax
  List *v6; // eax
  unsigned int i; // edi
  unsigned int j; // esi
  id v9; // ebx
  id v10; // eax
  id v11; // eax
  id v12; // ebx
  unsigned int k; // edi
  id v14; // ebx
  id v16; // eax
  id v18; // [esp+10h] [ebp-14h]
  unsigned __int8 v19; // [esp+14h] [ebp-10h]
  List *v20; // [esp+18h] [ebp-Ch]
  List *v21; // [esp+1Ch] [ebp-8h]
  id v22; // [esp+20h] [ebp-4h]

  v19 = -[KernDeviceDescription _isShared:](self, sel__isShared_, a5); /*0x180a7d*/
  v22 = -[KernDeviceDescription resourcesForKey:](self, sel_resourcesForKey_, a5); /*0x180a94*/
  v5 = +[Object alloc](aList, sel_alloc); /*0x180aac*/
  v21 = -[List init](v5, sel_init); /*0x180aba*/
  v6 = +[Object alloc](aList, sel_alloc); /*0x180ad5*/
  v20 = -[List init](v6, sel_init); /*0x180ae3*/
  for ( i = 0; a4 > i; ++i )
  {
    v18 = (id)*a3; /*0x180b01*/
    for ( j = 0; j < (unsigned int)objc_msgSend(v22, sel_count); ++j ) /*0x180b04*/
    {
      v9 = objc_msgSend(v22, sel_objectAt_, j); /*0x180b3a*/
      if ( v18 == objc_msgSend(v9, sel_item) ) /*0x180b48*/
        goto LABEL_7; /*0x180b48*/
    }
    v9 = nullptr; /*0x180b50*/
LABEL_7:
    if ( v9 )
    {
      -[List addObject:](v21, sel_addObject_, v9); /*0x180b62*/
    }
    else
    {
      v10 = objc_msgSend(self->_bus, sel__lookupResourceWithKey_, a5); /*0x180b7e*/
      if ( !v10
        || (!v19 ? (v11 = objc_msgSend(v10, sel_reserveItem_, *a3)) : (v11 = objc_msgSend(v10, sel_shareItem_, *a3)),
            (v12 = v11) == nullptr) )
      {
        v16 = -[List freeObjects](v20, sel_freeObjects); /*0x180ca6*/
        objc_msgSend(v16, sel_free); /*0x180caf*/
        -[List free](v21, sel_free); /*0x180cbf*/
        return nullptr; /*0x180cc4*/
      }
      -[List addObject:](v20, sel_addObject_, v11); /*0x180bd0*/
      -[List addObject:](v21, sel_addObject_, v12); /*0x180be1*/
    }
    ++a3; /*0x180be9*/
  }
  for ( k = 0; k < (unsigned int)objc_msgSend(v22, sel_count); ++k ) /*0x180bf7*/
  {
    v14 = objc_msgSend(v22, sel_objectAt_, k); /*0x180c24*/
    if ( -[List indexOf:](v21, sel_indexOf_, v14) == -1 ) /*0x180c3d*/
      objc_msgSend(v14, sel_free); /*0x180c47*/
  }
  objc_msgSend(v22, sel_empty); /*0x180c5f*/
  -[KernDeviceDescription setResources:forKey:](self, sel_setResources_forKey_, v21, a5); /*0x180c77*/
  -[List free](v20, sel_free); /*0x180c87*/
  return self; /*0x180cc9*/
}
