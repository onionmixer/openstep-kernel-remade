/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a45a8. */
char __cdecl +[IODevice addToBdevswFromDescription:open:close:strategy:dump:psize:isTape:](
        id a1,
        SEL a2,
        id a3,
        void *a4,
        void *a5,
        void *a6,
        void *a7,
        void *a8,
        char a9)
{
  id v9; // eax
  _BYTE *v10; // eax
  _BYTE *v11; // ebx
  int i; // ecx
  int v13; // ebx
  int v14; // eax

  v9 = objc_msgSend(a3, sel_configTable); /*0x1a45d0*/
  v10 = objc_msgSend(v9, sel_valueForStringKey_); /*0x1a45d9*/
  if ( v10 ) /*0x1a45e3*/
  {
    v11 = v10; /*0x1a45e5*/
    for ( i = 0; *v11; i = (char)*v11++ + 10 * i - 48 ) /*0x1a45e9*/
    {
      if ( (unsigned __int8)(*v11 - 48) > 9u ) /*0x1a45fb*/
        break; /*0x1a45fb*/
    }
    v13 = i; /*0x1a4610*/
  }
  else
  {
    v13 = -1; /*0x1a4614*/
  }
  v14 = IOAddToBdevswAt(v13, a4, a5, a6, a7, a8, a9); /*0x1a4633*/
  if ( v14 >= 0 )
  {
    objc_msgSend(a1, sel_setBlockMajor_, v14); /*0x1a4689*/
    return 1; /*0x1a468e*/
  }
  else
  {
    if ( v13 >= 0 )
    {
      objc_msgSend(a1, sel_name); /*0x1a4669*/
      IOLog("%s: could not add to bdevsw table at major %d\n");
    }
    else
    {
      objc_msgSend(a1, sel_name); /*0x1a464b*/
      IOLog("%s: could not add to bdevsw table at any major\n");
    }
    return 0; /*0x1a467c*/
  }
}
