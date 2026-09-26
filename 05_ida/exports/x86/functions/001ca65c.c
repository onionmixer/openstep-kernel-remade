/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca65c. */
Ivar __cdecl object_setInstanceVariable(id obj, const char *name, void *value)
{
  objc_ivar *v3; // edx
  Ivar InstanceVariable; // eax

  v3 = nullptr; /*0x1ca666*/
  if ( obj ) /*0x1ca66a*/
  {
    if ( name ) /*0x1ca66e*/
    {
      InstanceVariable = class_getInstanceVariable(*(Class *)obj, name); /*0x1ca674*/
      v3 = InstanceVariable; /*0x1ca679*/
      if ( InstanceVariable ) /*0x1ca67d*/
        *(_DWORD *)((char *)obj + InstanceVariable->ivar_offset) = value; /*0x1ca687*/
    }
  }
  return v3; /*0x1ca68b*/
}
