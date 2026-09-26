/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a4bdc. */
int __cdecl +[IODevice lookupByObjectNumber:instance:](id a1, SEL a2, unsigned int a3, id *a4)
{
  int v4; // ebx

  objc_msgSend(dword_1E8674, sel_lock); /*0x1a4bf5*/
  v4 = sub_1A3D58(a3, (int *)a4); /*0x1a4c01*/
  objc_msgSend(dword_1E8674, sel_unlock); /*0x1a4c11*/
  return v4; /*0x1a4c1b*/
}
