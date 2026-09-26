/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a3ef4. */
id __cdecl +[IODevice initialize](id a1, SEL a2)
{
  if ( a1 != objc_getClass("IODevice") ) /*0x1a3f0a*/
    +[IODevice registerClass:](aIodevice_0, sel_registerClass_, a1); /*0x1a3f1b*/
  if ( !byte_1E50C0 ) /*0x1a3f2a*/
  {
    dword_1E8674 = +[Object new](aNxlock, sel_new); /*0x1a3f3f*/
    dword_1E8668 = 0; /*0x1a3f44*/
    dword_1E8670 = (int)&dword_1E866C; /*0x1a3f4e*/
    dword_1E866C = (int)&dword_1E866C; /*0x1a3f58*/
    dword_1E8680 = (int)&dword_1E867C; /*0x1a3f62*/
    dword_1E867C = (int)&dword_1E867C; /*0x1a3f6c*/
    dword_1E8684 = +[Object new](aNxlock, sel_new); /*0x1a3f89*/
    byte_1E50C0 = 1; /*0x1a3f8e*/
  }
  return a1; /*0x1a3f97*/
}
