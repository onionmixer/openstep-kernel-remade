/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b77d0. */
id __cdecl +[AudioChannel addStream:](id a1, SEL a2, id a3)
{
  List *v3; // eax

  if ( !dword_1E5398 ) /*0x1b77da*/
  {
    v3 = +[Object alloc](aList, sel_alloc); /*0x1b77f1*/
    dword_1E5398 = -[List init](v3, sel_init); /*0x1b77ff*/
  }
  objc_msgSend(dword_1E5398, sel_addObject_, a3); /*0x1b7819*/
  return a1; /*0x1b7823*/
}
