/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b464c. */
id __cdecl -[KeyMap setDelegate:](KeyMap *self, SEL a2, id a3)
{
  const char *ClassName; // eax

  if ( (unsigned __int8)objc_msgSend(a3, sel_conformsTo_, &stru_1FDF5C) )
  {
    self->delegate = a3; /*0x1b4670*/
  }
  else
  {
    ClassName = object_getClassName(a3); /*0x1b4679*/
    IOLog((int)"KeyMap setDelegate: new delegate [%s] does not implement KeyMapDelegate protocol.\n", ClassName);
  }
  return self; /*0x1b468e*/
}
