/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f3fc. */
id __cdecl +[KernBus registerBusInstance:name:busId:](id a1, SEL a2, id a3, char *a4, int a5)
{
  id v5; // ebx
  HashTable *v6; // eax

  v5 = objc_msgSend(dword_1E7320, sel_valueForKey_, a4); /*0x17f41c*/
  if ( !v5 ) /*0x17f423*/
  {
    v6 = +[Object alloc](aHashtable, sel_alloc); /*0x17f43f*/
    v5 = -[HashTable initKeyDesc:](v6, sel_initKeyDesc_); /*0x17f44d*/
    objc_msgSend(dword_1E7320, sel_insertKey_value_, a4, v5); /*0x17f45f*/
  }
  objc_msgSend(v5, sel_insertKey_value_, a5, a3); /*0x17f474*/
  return a3; /*0x17f47e*/
}
