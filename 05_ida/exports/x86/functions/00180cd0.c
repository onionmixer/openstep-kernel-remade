/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x180cd0. */
id __cdecl -[KernDeviceDescription allocateRanges:numRanges:forKey:](
        KernDeviceDescription *self,
        SEL a2,
        $85CD2974BE96D4886BB301820D1C36C2 *a3,
        unsigned int a4,
        const char *a5)
{
  List *v5; // eax
  List *v6; // eax
  unsigned int i; // edi
  id v8; // ebx
  int v9; // edx
  id v10; // eax
  id v11; // eax
  id v12; // ebx
  unsigned int k; // edi
  id v14; // ebx
  id v16; // eax
  unsigned int j; // [esp+Ch] [ebp-1Ch]
  unsigned __int8 v19; // [esp+18h] [ebp-10h]
  List *v20; // [esp+1Ch] [ebp-Ch]
  List *v21; // [esp+20h] [ebp-8h]
  id v22; // [esp+24h] [ebp-4h]
  $85CD2974BE96D4886BB301820D1C36C2 v23; // 0:^34.8

  v19 = -[KernDeviceDescription _isShared:](self, sel__isShared_, a5); /*0x180ced*/
  v22 = -[KernDeviceDescription resourcesForKey:](self, sel_resourcesForKey_, a5); /*0x180d04*/
  v5 = +[Object alloc](aList, sel_alloc); /*0x180d1c*/
  v21 = -[List init](v5, sel_init); /*0x180d2a*/
  v6 = +[Object alloc](aList, sel_alloc); /*0x180d45*/
  v20 = -[List init](v6, sel_init); /*0x180d53*/
  for ( i = 0; a4 > i; ++i )
  {
    v23 = a3[i]; /*0x180d6a*/
    for ( j = 0; j < (unsigned int)objc_msgSend(v22, sel_count); ++j ) /*0x180d74*/
    {
      v8 = objc_msgSend(v22, sel_objectAt_, j); /*0x180da8*/
      if ( (id)v23.var0 == objc_msgSend(v8, sel_range) && v23.var1 == v9 ) /*0x180dc2*/
        goto LABEL_8; /*0x180dc2*/
    }
    v8 = nullptr; /*0x180dcc*/
LABEL_8:
    if ( v8 )
    {
      -[List addObject:](v21, sel_addObject_, v8); /*0x180dde*/
    }
    else
    {
      v10 = objc_msgSend(self->_bus, sel__lookupResourceWithKey_, a5); /*0x180dfa*/
      if ( !v10
        || (!v19
          ? (v11 = objc_msgSend(v10, sel_reserveRange_, v23.var0, v23.var1))
          : (v11 = objc_msgSend(v10, sel_shareRange_, v23.var0, v23.var1)),
            (v12 = v11) == nullptr) )
      {
        v16 = -[List freeObjects](v20, sel_freeObjects); /*0x180f1e*/
        objc_msgSend(v16, sel_free); /*0x180f27*/
        -[List free](v21, sel_free); /*0x180f37*/
        return nullptr; /*0x180f3c*/
      }
      -[List addObject:](v20, sel_addObject_, v11); /*0x180e4c*/
      -[List addObject:](v21, sel_addObject_, v12); /*0x180e5d*/
    }
  }
  for ( k = 0; k < (unsigned int)objc_msgSend(v22, sel_count); ++k ) /*0x180e6f*/
  {
    v14 = objc_msgSend(v22, sel_objectAt_, k); /*0x180e9c*/
    if ( -[List indexOf:](v21, sel_indexOf_, v14) == -1 ) /*0x180eb5*/
      objc_msgSend(v14, sel_free); /*0x180ebf*/
  }
  objc_msgSend(v22, sel_empty); /*0x180ed7*/
  -[KernDeviceDescription setResources:forKey:](self, sel_setResources_forKey_, v21, a5); /*0x180eef*/
  -[List free](v20, sel_free); /*0x180eff*/
  return self; /*0x180f41*/
}
