/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9b90. */
id __cdecl -[List appendList:](List *self, SEL a2, id a3)
{
  unsigned int v3; // ebx
  id v4; // esi
  id v5; // eax

  v3 = 0; /*0x1c9b99*/
  v4 = objc_msgSend(a3, sel_count); /*0x1c9ba8*/
  if ( v4 ) /*0x1c9baf*/
  {
    do /*0x1c9bd9*/
    {
      v5 = objc_msgSend(a3, sel_objectAt_, v3); /*0x1c9bbd*/
      -[List addObject:](self, sel_addObject_, v5); /*0x1c9bce*/
      ++v3; /*0x1c9bd6*/
    }
    while ( v3 < (unsigned int)v4 ); /*0x1c9bd9*/
  }
  return self; /*0x1c9be1*/
}
