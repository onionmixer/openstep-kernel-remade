/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a44a8. */
char __cdecl +[IODevice addToCdevswFromDescription:open:close:read:write:ioctl:stop:reset:select:mmap:getc:putc:](
        id a1,
        SEL a2,
        id a3,
        void *a4,
        void *a5,
        void *a6,
        void *a7,
        void *a8,
        void *a9,
        void *a10,
        void *a11,
        void *a12,
        void *a13,
        void *a14)
{
  id v14; // eax
  _BYTE *v15; // eax
  _BYTE *v16; // ebx
  int i; // ecx
  int v18; // ebx
  int v19; // eax

  v14 = objc_msgSend(a3, sel_configTable); /*0x1a44c8*/
  v15 = objc_msgSend(v14, sel_valueForStringKey_); /*0x1a44d1*/
  if ( v15 ) /*0x1a44db*/
  {
    v16 = v15; /*0x1a44dd*/
    for ( i = 0; *v16; i = (char)*v16++ + 10 * i - 48 ) /*0x1a44e1*/
    {
      if ( (unsigned __int8)(*v16 - 48) > 9u ) /*0x1a44f0*/
        break; /*0x1a44f0*/
    }
    v18 = i; /*0x1a4505*/
  }
  else
  {
    v18 = -1; /*0x1a450c*/
  }
  v19 = IOAddToCdevswAt(v18, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14); /*0x1a453e*/
  if ( v19 >= 0 )
  {
    objc_msgSend(a1, sel_setCharacterMajor_, v19); /*0x1a4591*/
    return 1; /*0x1a4596*/
  }
  else
  {
    if ( v18 >= 0 )
    {
      objc_msgSend(a1, sel_name); /*0x1a4571*/
      IOLog("%s: could not add to cdevsw table at major %d\n");
    }
    else
    {
      objc_msgSend(a1, sel_name); /*0x1a4556*/
      IOLog("%s: could not add to cdevsw table at any major\n");
    }
    return 0; /*0x1a4584*/
  }
}
