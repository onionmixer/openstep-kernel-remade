/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca06c. */
void __cdecl -[Object printForDebugger:](Object *self, SEL a2, $FDB6067EFA2BACD1029BBA668871BE41 *a3)
{
  const char *ClassName; // eax

  ClassName = object_getClassName(self); /*0x1ca078*/
  NXPrintf((int)a3, (int)"<%s: 0x%x>", ClassName, self);
  NXFlush(); /*0x1ca08d*/
}
