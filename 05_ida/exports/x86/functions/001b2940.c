/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2940. */
id __cdecl -[EventDriver attachEventSource:](EventDriver *self, SEL a2, const char *a3)
{
  Class Class; // eax
  Class v4; // ebx
  const char *v5; // eax
  const char *v7; // eax
  id v8; // eax
  void *v9; // ebx
  const char *v10; // eax
  const char *v11; // eax

  Class = objc_getClass(a3); /*0x1b294d*/
  v4 = Class; /*0x1b2952*/
  if ( Class )
  {
    if ( (unsigned __int8)-[objc_class respondsTo:](Class, sel_respondsTo_, sel_probe) )
    {
      v8 = -[objc_class probe](v4, sel_probe); /*0x1b29c4*/
      v9 = v8; /*0x1b29c9*/
      if ( v8 )
      {
        if ( -[EventDriver registerEventSource:](self, sel_registerEventSource_, v8) )
        {
          return v9; /*0x1b2a2c*/
        }
        else
        {
          v11 = -[IODevice name](self, sel_name); /*0x1b2a12*/
          IOLog((int)"%s: becomeOwner of %s failed\n", v11, a3);
          return nullptr; /*0x1b2a25*/
        }
      }
      else
      {
        v10 = -[IODevice name](self, sel_name); /*0x1b29db*/
        IOLog((int)"%s: probe of %s failed\n", v10, a3);
        return nullptr; /*0x1b29ee*/
      }
    }
    else
    {
      v7 = -[IODevice name](self, sel_name); /*0x1b29a4*/
      IOLog((int)"%s: %s does not respond to probe.\n", v7, a3);
      return nullptr; /*0x1b29b7*/
    }
  }
  else
  {
    v5 = -[IODevice name](self, sel_name); /*0x1b2964*/
    IOLog((int)"%s: %s: no such class.\n", v5, a3);
    return nullptr; /*0x1b2977*/
  }
}
