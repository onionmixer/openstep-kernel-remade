/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5178. */
id __cdecl +[IODevice objectsForClass:](id a1, SEL a2, Class *a3)
{
  id *v3; // ebx
  List *v4; // eax
  List *v5; // esi

  v3 = (id *)dword_1E866C; /*0x1a5181*/
  v4 = +[Object alloc](aList, sel_alloc); /*0x1a519c*/
  v5 = -[List init](v4, sel_init); /*0x1a51aa*/
  objc_msgSend(dword_1E8674, sel_lock); /*0x1a51ba*/
  for ( ; v3 != (id *)&dword_1E866C; v3 = (id *)v3[2] ) /*0x1a51c8*/
  {
    if ( objc_msgSend(*v3, sel_class) == a3 ) /*0x1a51e0*/
      -[List addObject:](v5, sel_addObject_, *v3); /*0x1a51ed*/
  }
  objc_msgSend(dword_1E8674, sel_unlock); /*0x1a520e*/
  return v5; /*0x1a5218*/
}
