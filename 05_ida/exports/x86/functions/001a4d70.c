/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a4d70. */
int __cdecl +[IODevice setIntValues:forParameter:objectNumber:count:](
        id a1,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int a5,
        unsigned int a6)
{
  int v6; // ebx
  id v8; // [esp+4h] [ebp-4h] BYREF

  objc_msgSend(dword_1E8674, sel_lock); /*0x1a4d88*/
  v6 = sub_1A3D58(a5, (int *)&v8); /*0x1a4d97*/
  objc_msgSend(dword_1E8674, sel_unlock); /*0x1a4da7*/
  if ( !v6 ) /*0x1a4db1*/
    return (int)objc_msgSend(v8, sel_setIntValues_forParameter_count_, a3, a4, a6); /*0x1a4dcf*/
  return v6; /*0x1a4dd3*/
}
