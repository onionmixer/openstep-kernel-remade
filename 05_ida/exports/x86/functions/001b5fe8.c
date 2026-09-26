/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b5fe8. */
id __cdecl +[IOAudio _addChannel:](id a1, SEL a2, id a3)
{
  List *v3; // eax

  if ( !dword_1E5390 ) /*0x1b5ff2*/
  {
    v3 = +[Object alloc](aList, sel_alloc); /*0x1b6009*/
    dword_1E5390 = -[List init](v3, sel_init); /*0x1b6017*/
  }
  objc_msgSend(dword_1E5390, sel_addObject_, a3); /*0x1b6031*/
  return a1; /*0x1b603b*/
}
