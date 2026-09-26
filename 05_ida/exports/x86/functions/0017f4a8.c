/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f4a8. */
id __cdecl +[KernBus lookupBusInstanceWithName:busId:](id a1, SEL a2, char *a3, int a4)
{
  void *v4; // ebx
  id v5; // eax

  v4 = nullptr; /*0x17f4ac*/
  v5 = objc_msgSend(dword_1E7320, sel_valueForKey_, a3); /*0x17f4c0*/
  if ( v5 ) /*0x17f4ca*/
    return objc_msgSend(v5, sel_valueForKey_, a4); /*0x17f4dd*/
  return v4; /*0x17f4e1*/
}
