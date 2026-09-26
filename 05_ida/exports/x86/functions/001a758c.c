/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a758c. */
int volCheckInit()
{
  dword_1E86E8 = +[Object new](aNxspinlock, sel_new); /*0x1a75a2*/
  dword_1E86DC = (int)&dword_1E86D8; /*0x1a75a7*/
  dword_1E86D8 = (int)&dword_1E86D8; /*0x1a75b1*/
  dword_1E86E4 = (int)&dword_1E86E0; /*0x1a75bb*/
  dword_1E86E0 = (int)&dword_1E86E0; /*0x1a75c5*/
  return IOForkThread(sub_1A7754, 0); /*0x1a75dd*/
}
