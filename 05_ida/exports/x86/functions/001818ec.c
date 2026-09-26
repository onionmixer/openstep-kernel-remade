/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1818ec. */
id __cdecl -[KernDeviceDescription _parseItemResourceByKey:value:](
        KernDeviceDescription *self,
        SEL a2,
        const char *a3,
        const char *a4)
{
  id v4; // esi
  id result; // eax
  List *v6; // eax
  id v7; // ebx
  id v8; // eax
  id v9; // eax
  unsigned __int8 v10; // [esp+Ch] [ebp-Ch]
  unsigned int v11; // [esp+10h] [ebp-8h] BYREF
  char *v12; // [esp+14h] [ebp-4h] BYREF

  v4 = objc_msgSend(self->_bus, sel__lookupResourceWithKey_, a3); /*0x18190c*/
  if ( v4 )
  {
    v6 = +[Object alloc](aList, sel_alloc); /*0x18193d*/
    result = -[List init](v6, sel_init); /*0x181946*/
    v7 = result; /*0x18194b*/
    v12 = (char *)a4; /*0x181950*/
    if ( a4 )
    {
      v10 = -[KernDeviceDescription _isShared:](self, sel__isShared_, a3); /*0x18196f*/
      while ( sub_180F48(v12, &v12, &v11) )
      {
        if ( v10 ) /*0x181994*/
          v8 = objc_msgSend(v4, sel_shareItem_, v11); /*0x1819a0*/
        else
          v8 = objc_msgSend(v4, sel_reserveItem_, v11); /*0x1819b0*/
        if ( !objc_msgSend(v7, sel_addObject_, v8) )
        {
          printf("%s: Couldn't reserve %d\n", a3, v11);
          v9 = objc_msgSend(v7, sel_freeObjects); /*0x1819eb*/
          return objc_msgSend(v9, sel_free); /*0x1819f9*/
        }
      }
      return v7; /*0x1819fc*/
    }
  }
  else
  {
    printf("%s: Couldn't locate resource object\n", a3);
    return nullptr; /*0x181920*/
  }
  return result; /*0x181a01*/
}
