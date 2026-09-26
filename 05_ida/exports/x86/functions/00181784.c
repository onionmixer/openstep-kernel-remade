/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181784. */
id __cdecl -[KernDeviceDescription _parseRangeResourceByKey:value:](
        KernDeviceDescription *self,
        SEL a2,
        const char *a3,
        const char *a4)
{
  List *v5; // eax
  const char *v6; // edi
  id v7; // eax
  id v8; // eax
  List *v9; // [esp+Ch] [ebp-18h]
  unsigned __int8 v10; // [esp+10h] [ebp-14h]
  id v11; // [esp+14h] [ebp-10h]
  unsigned int v12; // [esp+18h] [ebp-Ch] BYREF
  unsigned int v13; // [esp+1Ch] [ebp-8h] BYREF
  char *v14; // [esp+20h] [ebp-4h] BYREF

  v11 = objc_msgSend(self->_bus, sel__lookupResourceWithKey_, a3); /*0x1817a7*/
  if ( v11 )
  {
    v5 = +[Object alloc](aList, sel_alloc); /*0x1817dd*/
    v9 = -[List init](v5, sel_init); /*0x1817eb*/
    v14 = (char *)a4; /*0x1817ee*/
    if ( a4 )
    {
      v10 = -[KernDeviceDescription _isShared:](self, sel__isShared_, a3); /*0x181811*/
      while ( sub_180F48(v14, &v14, &v13) )
      {
        ++v14; /*0x18183a*/
        if ( !sub_180F48(v14, &v14, &v12) ) /*0x181841*/
          break; /*0x181841*/
        if ( v10 ) /*0x181864*/
          v6 = sel_shareRange_; /*0x181868*/
        else
          v6 = sel_reserveRange_; /*0x181872*/
        v7 = objc_msgSend(v11, v6, v13, v12 - v13 + 1); /*0x18187d*/
        if ( !-[List addObject:](v9, sel_addObject_, v7) )
        {
          printf("%s: Couldn't reserve range %08x-%08x\n", a3, v13, v12);
          v8 = -[List freeObjects](v9, sel_freeObjects); /*0x1818c9*/
          return objc_msgSend(v8, sel_free); /*0x1818d7*/
        }
      }
      return v9; /*0x1818dc*/
    }
    else
    {
      return v9; /*0x1817f8*/
    }
  }
  else
  {
    printf("%s: Couldn't locate resource object\n", a3);
    return nullptr; /*0x1817bf*/
  }
}
